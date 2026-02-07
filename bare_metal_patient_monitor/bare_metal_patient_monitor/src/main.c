#include "stm32f401xx.h"
#include "gpio.h"
#include "i2c.h"
#include "spi.h"
#include "uart.h"
#include "delay.h"
#include "max30102.h"
#include "temperature.h"
#include "ssd1306.h"
#include "sdcard.h"

/* Data buffers for MAX30102 */
#define BUFFER_SIZE 100
static uint32_t red_buffer[BUFFER_SIZE];
static uint32_t ir_buffer[BUFFER_SIZE];
static uint8_t buffer_index = 0;

/* Patient vital signs */
typedef struct {
    uint16_t heart_rate;      /* BPM */
    uint8_t spo2;             /* Percentage */
    float temperature;        /* Celsius */
    uint32_t timestamp;       /* Milliseconds */
} VitalSigns_t;

static VitalSigns_t current_vitals;

/**
 * @brief System clock configuration
 *        Configure to run at 84MHz using HSE and PLL
 */
void system_clock_config(void)
{
    /* Enable HSI (16MHz) - already running by default */
    
    /* Configure Flash latency for 84MHz operation */
    /* Set 2 wait states for 84MHz @ 3.3V */
    
    /* Configure PLL: HSI/16 * 168 / 2 = 84MHz */
    /* For simplicity, we'll run on HSI (16MHz) */
    /* In production, configure PLL for higher speed */
    
    /* Enable peripheral clocks are done in individual init functions */
}

/**
 * @brief Format and display vitals on OLED
 */
void display_vitals(VitalSigns_t *vitals)
{
    ssd1306_clear();
    
    /* Line 1: Heart Rate */
    ssd1306_set_cursor(0, 0);
    ssd1306_write_string("HR: ");
    ssd1306_write_number(vitals->heart_rate);
    ssd1306_write_string(" BPM");
    
    /* Line 2: SpO2 */
    ssd1306_set_cursor(0, 16);
    ssd1306_write_string("SPO2: ");
    ssd1306_write_number(vitals->spo2);
    ssd1306_write_string(" %");
    
    /* Line 3: Temperature */
    ssd1306_set_cursor(0, 32);
    ssd1306_write_string("TEMP: ");
    ssd1306_write_number((uint32_t)vitals->temperature);
    ssd1306_write_char('.');
    ssd1306_write_number((uint32_t)((vitals->temperature - (uint32_t)vitals->temperature) * 10));
    ssd1306_write_string(" C");
    
    /* Line 4: Status */
    ssd1306_set_cursor(0, 48);
    if (vitals->heart_rate > 0 && vitals->spo2 > 0) {
        ssd1306_write_string("STATUS: OK");
    } else {
        ssd1306_write_string("MEASURING...");
    }
    
    /* Update display */
    ssd1306_update();
}

/**
 * @brief Send vitals to UART for debugging/monitoring
 */
void send_vitals_uart(VitalSigns_t *vitals)
{
    uart_send_string("\r\n=== VITAL SIGNS ===\r\n");
    
    uart_send_string("Heart Rate: ");
    uart_send_number(vitals->heart_rate);
    uart_send_string(" BPM\r\n");
    
    uart_send_string("SpO2: ");
    uart_send_number(vitals->spo2);
    uart_send_string(" %\r\n");
    
    uart_send_string("Temperature: ");
    uart_send_number((uint32_t)vitals->temperature);
    uart_send_char('.');
    uart_send_number((uint32_t)((vitals->temperature - (uint32_t)vitals->temperature) * 10));
    uart_send_string(" C\r\n");
    
    uart_send_string("==================\r\n");
}

/**
 * @brief Log vitals to SD card
 */
void log_vitals_sdcard(VitalSigns_t *vitals)
{
    char log_buffer[128];
    
    /* Simple CSV format logging */
    /* Format: timestamp,heart_rate,spo2,temperature */
    
    /* Convert values to strings and write */
    sdcard_write_string("TIME:");
    /* In real implementation, add timestamp */
    
    sdcard_write_string(",HR:");
    /* Add heart rate as string */
    
    sdcard_write_string(",SPO2:");
    /* Add SpO2 as string */
    
    sdcard_write_string(",TEMP:");
    /* Add temperature as string */
    
    sdcard_write_string("\n");
}

/**
 * @brief Collect sensor data and calculate vitals
 */
void collect_and_process_vitals(void)
{
    MAX30102_Data sensor_data;
    
    /* Check if data is available */
    if (max30102_data_available() > 0) {
        /* Read FIFO data */
        max30102_read_fifo(&sensor_data);
        
        /* Store in buffers */
        red_buffer[buffer_index] = sensor_data.red;
        ir_buffer[buffer_index] = sensor_data.ir;
        buffer_index++;
        
        /* When buffer is full, calculate vitals */
        if (buffer_index >= BUFFER_SIZE) {
            buffer_index = 0;
            
            /* Calculate heart rate from IR signal */
            current_vitals.heart_rate = max30102_calculate_heart_rate(ir_buffer, BUFFER_SIZE);
            
            /* Calculate SpO2 from RED and IR signals */
            current_vitals.spo2 = max30102_calculate_spo2(red_buffer, ir_buffer, BUFFER_SIZE);
            
            /* Read temperature */
            current_vitals.temperature = temperature_read();
            
            /* Display on OLED */
            display_vitals(&current_vitals);
            
            /* Send to UART */
            send_vitals_uart(&current_vitals);
            
            /* Log to SD card */
            log_vitals_sdcard(&current_vitals);
        }
    }
}

/**
 * @brief Main function
 */
int main(void)
{
    /* Configure system clock */
    system_clock_config();
    
    /* Initialize delay timer */
    delay_init();
    
    /* Initialize GPIO */
    gpio_init();
    
    /* Initialize peripherals */
    uart_init();
    spi_init();
    i2c_init();
    
    /* Send startup message */
    uart_send_string("\r\n");
    uart_send_string("==========================================\r\n");
    uart_send_string("  PULSE OXIMETER PATIENT MONITOR v1.0\r\n");
    uart_send_string("  Bare Metal STM32F401RE Implementation\r\n");
    uart_send_string("==========================================\r\n");
    uart_send_string("Initializing peripherals...\r\n");
    
    /* Initialize display */
    uart_send_string("Initializing OLED display...\r\n");
    ssd1306_init();
    delay_ms(100);
    
    /* Show startup screen */
    ssd1306_clear();
    ssd1306_set_cursor(10, 16);
    ssd1306_write_string("PULSE OX");
    ssd1306_set_cursor(10, 32);
    ssd1306_write_string("MONITOR");
    ssd1306_update();
    delay_ms(2000);
    
    /* Initialize MAX30102 sensor */
    uart_send_string("Initializing MAX30102 sensor...\r\n");
    max30102_init();
    delay_ms(100);
    
    /* Verify sensor */
    uint8_t part_id = max30102_get_part_id();
    if (part_id == 0x15) {
        uart_send_string("MAX30102 detected (Part ID: 0x15)\r\n");
    } else {
        uart_send_string("MAX30102 detection failed!\r\n");
    }
    
    /* Initialize temperature sensor */
    uart_send_string("Initializing temperature sensor...\r\n");
    temperature_init();
    delay_ms(100);
    
    /* Initialize SD card */
    uart_send_string("Initializing SD card...\r\n");
    sdcard_init();
    delay_ms(100);
    
    /* Write header to SD card */
    sdcard_write_string("=== PATIENT MONITOR LOG ===\n");
    sdcard_write_string("TIME,HR,SPO2,TEMP\n");
    
    uart_send_string("System initialization complete!\r\n");
    uart_send_string("Starting measurements...\r\n\r\n");
    
    /* Initialize vitals structure */
    current_vitals.heart_rate = 0;
    current_vitals.spo2 = 0;
    current_vitals.temperature = 0.0f;
    current_vitals.timestamp = 0;
    
    /* LED heartbeat indicator */
    uint32_t led_counter = 0;
    
    /* Main loop */
    while (1) {
        /* Collect sensor data and process */
        collect_and_process_vitals();
        
        /* Heartbeat LED (PC13 - onboard LED) */
        if (++led_counter > 1000) {
            led_counter = 0;
            gpio_toggle_pin(GPIOC, 13);
        }
        
        /* Small delay to prevent overwhelming the system */
        delay_ms(10);
    }
    
    return 0;
}

/**
 * @brief Default interrupt handler
 */
void Default_Handler(void)
{
    while (1);
}

/**
 * @brief Hard Fault Handler
 */
void HardFault_Handler(void)
{
    uart_send_string("\r\n!!! HARD FAULT !!!\r\n");
    while (1) {
        gpio_toggle_pin(GPIOC, 13);
        delay_ms(100);
    }
}
