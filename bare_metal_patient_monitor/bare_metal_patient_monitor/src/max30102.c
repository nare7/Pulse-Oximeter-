#include "max30102.h"
#include "i2c.h"
#include "delay.h"

/**
 * @brief Initialize MAX30102 sensor
 */
void max30102_init(void)
{
    /* Reset the sensor */
    max30102_reset();
    delay_ms(100);
    
    /* Check part ID */
    uint8_t part_id = max30102_get_part_id();
    if (part_id != 0x15) {
        /* Part ID mismatch - sensor not detected */
        return;
    }
    
    /* Configure FIFO */
    i2c_write_reg(MAX30102_ADDR, MAX30102_FIFO_CONFIG, MAX30102_FIFO_SAMPLES);
    
    /* Configure Mode: SpO2 mode */
    i2c_write_reg(MAX30102_ADDR, MAX30102_MODE_CONFIG, MAX30102_MODE_SPO2);
    
    /* Configure SpO2:
     * - Sample Rate: 100 samples/sec
     * - LED Pulse Width: 411us (18-bit resolution)
     * - ADC Range: 4096nA
     */
    uint8_t spo2_config = (MAX30102_SPO2_SR_100 << 2) | (MAX30102_SPO2_PW_411 << 0);
    i2c_write_reg(MAX30102_ADDR, MAX30102_SPO2_CONFIG, spo2_config);
    
    /* Configure LED Pulse Amplitude
     * Red LED (LED1): 7.0mA
     * IR LED (LED2): 7.0mA
     */
    i2c_write_reg(MAX30102_ADDR, MAX30102_LED1_PA, 0x1F);  /* Red LED */
    i2c_write_reg(MAX30102_ADDR, MAX30102_LED2_PA, 0x1F);  /* IR LED */
    
    /* Clear FIFO pointers */
    i2c_write_reg(MAX30102_ADDR, MAX30102_FIFO_WR_PTR, 0x00);
    i2c_write_reg(MAX30102_ADDR, MAX30102_FIFO_RD_PTR, 0x00);
}

/**
 * @brief Reset MAX30102 sensor
 */
void max30102_reset(void)
{
    /* Write reset bit in MODE_CONFIG register */
    i2c_write_reg(MAX30102_ADDR, MAX30102_MODE_CONFIG, 0x40);
    delay_ms(10);
}

/**
 * @brief Get MAX30102 Part ID
 * @return Part ID (should be 0x15 for MAX30102)
 */
uint8_t max30102_get_part_id(void)
{
    return i2c_read_reg(MAX30102_ADDR, MAX30102_PART_ID);
}

/**
 * @brief Check if new data is available in FIFO
 * @return Number of samples available
 */
uint8_t max30102_data_available(void)
{
    uint8_t wr_ptr = i2c_read_reg(MAX30102_ADDR, MAX30102_FIFO_WR_PTR);
    uint8_t rd_ptr = i2c_read_reg(MAX30102_ADDR, MAX30102_FIFO_RD_PTR);
    
    int8_t samples_available = wr_ptr - rd_ptr;
    if (samples_available < 0) {
        samples_available += 32;  /* FIFO is circular with 32 samples */
    }
    
    return (uint8_t)samples_available;
}

/**
 * @brief Read one sample from FIFO
 * @param data: Pointer to structure to store RED and IR values
 */
void max30102_read_fifo(MAX30102_Data *data)
{
    uint8_t buffer[6];
    
    /* Read 6 bytes from FIFO:
     * Bytes 0-2: RED LED data (18-bit)
     * Bytes 3-5: IR LED data (18-bit)
     */
    i2c_read_multi(MAX30102_ADDR, MAX30102_FIFO_DATA, buffer, 6);
    
    /* Reconstruct 18-bit values */
    data->red = ((uint32_t)buffer[0] << 16) | ((uint32_t)buffer[1] << 8) | buffer[2];
    data->ir = ((uint32_t)buffer[3] << 16) | ((uint32_t)buffer[4] << 8) | buffer[5];
    
    /* Mask to 18 bits */
    data->red &= 0x3FFFF;
    data->ir &= 0x3FFFF;
}

/**
 * @brief Read die temperature from MAX30102
 * @param temp: Pointer to store temperature in Celsius
 */
void max30102_read_temperature(float *temp)
{
    /* Trigger temperature measurement */
    i2c_write_reg(MAX30102_ADDR, MAX30102_TEMP_CONFIG, 0x01);
    
    /* Wait for conversion to complete (~30ms) */
    delay_ms(30);
    
    /* Read temperature integer part */
    int8_t temp_int = (int8_t)i2c_read_reg(MAX30102_ADDR, MAX30102_TEMP_INT);
    
    /* Read temperature fractional part */
    uint8_t temp_frac = i2c_read_reg(MAX30102_ADDR, MAX30102_TEMP_FRAC);
    
    /* Calculate temperature
     * Temperature = Integer + (Fraction * 0.0625)
     */
    *temp = (float)temp_int + ((float)temp_frac * 0.0625f);
}

/**
 * @brief Calculate heart rate from IR signal
 * @param ir_buffer: Buffer of IR values
 * @param buffer_length: Length of buffer
 * @return Calculated heart rate in BPM
 */
uint16_t max30102_calculate_heart_rate(uint32_t *ir_buffer, uint8_t buffer_length)
{
    /* Simple peak detection algorithm
     * This is a basic implementation - for production use,
     * implement more sophisticated algorithms
     */
    uint8_t peak_count = 0;
    uint32_t threshold = 50000;  /* Adjust based on your LED intensity */
    uint8_t min_distance = 10;   /* Minimum samples between peaks */
    uint8_t last_peak = 0;
    
    for (uint8_t i = 1; i < buffer_length - 1; i++) {
        /* Detect peak: current value > neighbors and > threshold */
        if (ir_buffer[i] > ir_buffer[i-1] && 
            ir_buffer[i] > ir_buffer[i+1] && 
            ir_buffer[i] > threshold &&
            (i - last_peak) > min_distance) {
            peak_count++;
            last_peak = i;
        }
    }
    
    /* Calculate BPM
     * Assuming 100 samples/sec, 100 samples = 1 second
     * BPM = (peaks * 60) / (buffer_length / sample_rate)
     */
    if (peak_count > 0) {
        return (peak_count * 60 * 100) / buffer_length;
    }
    
    return 0;
}

/**
 * @brief Calculate SpO2 from RED and IR signals
 * @param red_buffer: Buffer of RED values
 * @param ir_buffer: Buffer of IR values
 * @param buffer_length: Length of buffers
 * @return Calculated SpO2 percentage
 */
uint8_t max30102_calculate_spo2(uint32_t *red_buffer, uint32_t *ir_buffer, uint8_t buffer_length)
{
    /* Calculate DC and AC components for RED and IR
     * This is a simplified implementation
     * For accurate SpO2, use calibration and more sophisticated algorithms
     */
    uint32_t red_dc = 0, ir_dc = 0;
    uint32_t red_ac_max = 0, red_ac_min = 0xFFFFFFFF;
    uint32_t ir_ac_max = 0, ir_ac_min = 0xFFFFFFFF;
    
    /* Calculate DC (average) and find AC range */
    for (uint8_t i = 0; i < buffer_length; i++) {
        red_dc += red_buffer[i];
        ir_dc += ir_buffer[i];
        
        if (red_buffer[i] > red_ac_max) red_ac_max = red_buffer[i];
        if (red_buffer[i] < red_ac_min) red_ac_min = red_buffer[i];
        if (ir_buffer[i] > ir_ac_max) ir_ac_max = ir_buffer[i];
        if (ir_buffer[i] < ir_ac_min) ir_ac_min = ir_buffer[i];
    }
    
    red_dc /= buffer_length;
    ir_dc /= buffer_length;
    
    uint32_t red_ac = (red_ac_max - red_ac_min) / 2;
    uint32_t ir_ac = (ir_ac_max - ir_ac_min) / 2;
    
    /* Calculate R value: (AC_red/DC_red) / (AC_ir/DC_ir) */
    if (ir_dc == 0 || ir_ac == 0) return 0;
    
    float r = ((float)red_ac / (float)red_dc) / ((float)ir_ac / (float)ir_dc);
    
    /* Empirical formula for SpO2 calculation
     * SpO2 = -45.060 * R^2 + 30.354 * R + 94.845
     * This is an approximation and needs calibration
     */
    float spo2 = -45.060f * r * r + 30.354f * r + 94.845f;
    
    /* Clamp to valid range */
    if (spo2 > 100.0f) spo2 = 100.0f;
    if (spo2 < 0.0f) spo2 = 0.0f;
    
    return (uint8_t)spo2;
}
