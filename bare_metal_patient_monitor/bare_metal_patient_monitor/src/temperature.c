#include "temperature.h"
#include "delay.h"

/**
 * @brief Initialize ADC1 for temperature sensor reading
 *        Using PA0 as ADC1_IN0
 *        External temperature sensor (e.g., LM35, TMP36, or thermistor)
 */
void temperature_init(void)
{
    /* Enable ADC1 clock */
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
    
    /* ADC Configuration */
    /* Set ADC prescaler: PCLK2 divided by 4 (84MHz / 4 = 21MHz) */
    /* This is done in ADC Common Control Register (not shown in simplified struct) */
    
    /* Set sampling time for channel 0
     * SMPR2 controls channels 0-9
     * 3 bits per channel, 000 = 3 cycles, 111 = 480 cycles
     * Use 480 cycles for better accuracy: 111 = 7
     */
    ADC1->SMPR2 |= (7 << (3 * TEMP_ADC_CHANNEL));
    
    /* Set regular sequence: 1 conversion, channel 0 */
    ADC1->SQR1 = 0;  /* L[3:0] = 0 means 1 conversion */
    ADC1->SQR3 = TEMP_ADC_CHANNEL;  /* First conversion is channel 0 */
    
    /* Configure ADC Control Register 2 */
    ADC1->CR2 = 0;
    
    /* Enable continuous conversion mode */
    ADC1->CR2 |= (1 << 1);  /* CONT bit */
    
    /* Data alignment: right aligned */
    /* This is default (bit 11 = 0) */
    
    /* Enable ADC */
    ADC1->CR2 |= (1 << 0);  /* ADON bit */
    
    /* Wait for ADC to stabilize */
    delay_ms(1);
    
    /* Start conversion */
    ADC1->CR2 |= (1 << 30);  /* SWSTART bit */
}

/**
 * @brief Read raw ADC value
 * @return 12-bit ADC value (0-4095)
 */
uint16_t adc_read(void)
{
    /* Wait for conversion to complete (EOC flag) */
    while (!(ADC1->SR & (1 << 1)));
    
    /* Read converted data (12-bit) */
    return ADC1->DR;
}

/**
 * @brief Read temperature from sensor
 * @return Temperature in degrees Celsius
 * 
 * This function assumes:
 * - Using LM35 sensor: 10mV/°C, 0°C = 0V
 * - Using TMP36 sensor: 10mV/°C, 0°C = 500mV
 * - Vref = 3.3V, 12-bit ADC
 * 
 * Modify the conversion formula based on your actual sensor
 */
float temperature_read(void)
{
    uint16_t adc_value = adc_read();
    float voltage;
    float temperature;
    
    /* Convert ADC value to voltage
     * Voltage = (ADC_value / 4095) * Vref
     * Vref = 3.3V
     */
    voltage = ((float)adc_value / 4095.0f) * 3.3f;
    
    /* ========== FOR LM35 SENSOR ========== */
    /* LM35 outputs 10mV per degree Celsius
     * Temperature (°C) = Voltage (V) * 100
     */
    // temperature = voltage * 100.0f;
    
    /* ========== FOR TMP36 SENSOR ========== */
    /* TMP36 outputs 10mV per degree, with 500mV offset at 0°C
     * Temperature (°C) = (Voltage - 0.5V) * 100
     */
    temperature = (voltage - 0.5f) * 100.0f;
    
    /* ========== FOR THERMISTOR (NTC 10K) ========== */
    /* Using Steinhart-Hart equation with voltage divider
     * Uncomment and modify coefficients for your thermistor
     */
    /*
    float R_series = 10000.0f;  // Series resistor value
    float Vcc = 3.3f;
    float R_thermistor = R_series * (Vcc / voltage - 1.0f);
    
    // Steinhart-Hart coefficients (example for generic NTC 10K)
    float A = 0.001129148f;
    float B = 0.000234125f;
    float C = 0.0000000876741f;
    
    float ln_R = logf(R_thermistor);
    float T_kelvin = 1.0f / (A + B * ln_R + C * ln_R * ln_R * ln_R);
    temperature = T_kelvin - 273.15f;  // Convert to Celsius
    */
    
    /* ========== SIMULATED/DUMMY DATA ========== */
    /* For testing without actual sensor, return normal body temperature */
    // temperature = 36.5f + ((float)(adc_value % 10) / 10.0f);
    
    return temperature;
}
