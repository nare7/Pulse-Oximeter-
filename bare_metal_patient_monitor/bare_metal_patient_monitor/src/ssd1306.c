#include "ssd1306.h"
#include "spi.h"
#include "gpio.h"
#include "delay.h"

/* Display buffer */
static uint8_t ssd1306_buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];

/* Current cursor position */
static uint8_t cursor_x = 0;
static uint8_t cursor_y = 0;

/* Simple 5x7 font (only basic ASCII characters) */
static const uint8_t font_5x7[][5] = {
    {0x00, 0x00, 0x00, 0x00, 0x00}, // Space
    {0x00, 0x00, 0x5F, 0x00, 0x00}, // !
    {0x00, 0x07, 0x00, 0x07, 0x00}, // "
    {0x14, 0x7F, 0x14, 0x7F, 0x14}, // #
    {0x24, 0x2A, 0x7F, 0x2A, 0x12}, // $
    {0x23, 0x13, 0x08, 0x64, 0x62}, // %
    {0x36, 0x49, 0x55, 0x22, 0x50}, // &
    {0x00, 0x05, 0x03, 0x00, 0x00}, // '
    {0x00, 0x1C, 0x22, 0x41, 0x00}, // (
    {0x00, 0x41, 0x22, 0x1C, 0x00}, // )
    {0x14, 0x08, 0x3E, 0x08, 0x14}, // *
    {0x08, 0x08, 0x3E, 0x08, 0x08}, // +
    {0x00, 0x50, 0x30, 0x00, 0x00}, // ,
    {0x08, 0x08, 0x08, 0x08, 0x08}, // -
    {0x00, 0x60, 0x60, 0x00, 0x00}, // .
    {0x20, 0x10, 0x08, 0x04, 0x02}, // /
    {0x3E, 0x51, 0x49, 0x45, 0x3E}, // 0
    {0x00, 0x42, 0x7F, 0x40, 0x00}, // 1
    {0x42, 0x61, 0x51, 0x49, 0x46}, // 2
    {0x21, 0x41, 0x45, 0x4B, 0x31}, // 3
    {0x18, 0x14, 0x12, 0x7F, 0x10}, // 4
    {0x27, 0x45, 0x45, 0x45, 0x39}, // 5
    {0x3C, 0x4A, 0x49, 0x49, 0x30}, // 6
    {0x01, 0x71, 0x09, 0x05, 0x03}, // 7
    {0x36, 0x49, 0x49, 0x49, 0x36}, // 8
    {0x06, 0x49, 0x49, 0x29, 0x1E}, // 9
    {0x00, 0x36, 0x36, 0x00, 0x00}, // :
    {0x00, 0x56, 0x36, 0x00, 0x00}, // ;
    {0x08, 0x14, 0x22, 0x41, 0x00}, // <
    {0x14, 0x14, 0x14, 0x14, 0x14}, // =
    {0x00, 0x41, 0x22, 0x14, 0x08}, // >
    {0x02, 0x01, 0x51, 0x09, 0x06}, // ?
    {0x32, 0x49, 0x79, 0x41, 0x3E}, // @
    {0x7E, 0x11, 0x11, 0x11, 0x7E}, // A
    {0x7F, 0x49, 0x49, 0x49, 0x36}, // B
    {0x3E, 0x41, 0x41, 0x41, 0x22}, // C
    {0x7F, 0x41, 0x41, 0x22, 0x1C}, // D
    {0x7F, 0x49, 0x49, 0x49, 0x41}, // E
    {0x7F, 0x09, 0x09, 0x09, 0x01}, // F
    {0x3E, 0x41, 0x49, 0x49, 0x7A}, // G
    {0x7F, 0x08, 0x08, 0x08, 0x7F}, // H
    {0x00, 0x41, 0x7F, 0x41, 0x00}, // I
    {0x20, 0x40, 0x41, 0x3F, 0x01}, // J
    {0x7F, 0x08, 0x14, 0x22, 0x41}, // K
    {0x7F, 0x40, 0x40, 0x40, 0x40}, // L
    {0x7F, 0x02, 0x0C, 0x02, 0x7F}, // M
    {0x7F, 0x04, 0x08, 0x10, 0x7F}, // N
    {0x3E, 0x41, 0x41, 0x41, 0x3E}, // O
    {0x7F, 0x09, 0x09, 0x09, 0x06}, // P
    {0x3E, 0x41, 0x51, 0x21, 0x5E}, // Q
    {0x7F, 0x09, 0x19, 0x29, 0x46}, // R
    {0x46, 0x49, 0x49, 0x49, 0x31}, // S
    {0x01, 0x01, 0x7F, 0x01, 0x01}, // T
    {0x3F, 0x40, 0x40, 0x40, 0x3F}, // U
    {0x1F, 0x20, 0x40, 0x20, 0x1F}, // V
    {0x3F, 0x40, 0x38, 0x40, 0x3F}, // W
    {0x63, 0x14, 0x08, 0x14, 0x63}, // X
    {0x07, 0x08, 0x70, 0x08, 0x07}, // Y
    {0x61, 0x51, 0x49, 0x45, 0x43}, // Z
};

/**
 * @brief Send command to SSD1306
 */
void ssd1306_command(uint8_t cmd)
{
    gpio_reset_pin(SSD1306_DC_PORT, SSD1306_DC_PIN);  /* DC low = command */
    spi_cs_low(SPI_CS_DISPLAY_PORT, SPI_CS_DISPLAY_PIN);
    spi_transfer(cmd);
    spi_cs_high(SPI_CS_DISPLAY_PORT, SPI_CS_DISPLAY_PIN);
}

/**
 * @brief Send data to SSD1306
 */
void ssd1306_data(uint8_t data)
{
    gpio_set_pin(SSD1306_DC_PORT, SSD1306_DC_PIN);  /* DC high = data */
    spi_cs_low(SPI_CS_DISPLAY_PORT, SPI_CS_DISPLAY_PIN);
    spi_transfer(data);
    spi_cs_high(SPI_CS_DISPLAY_PORT, SPI_CS_DISPLAY_PIN);
}

/**
 * @brief Initialize SSD1306 display
 */
void ssd1306_init(void)
{
    /* Hardware reset (if RST pin is connected - using PC0 as example) */
    gpio_reset_pin(GPIOC, 0);
    delay_ms(10);
    gpio_set_pin(GPIOC, 0);
    delay_ms(10);
    
    /* Initialization sequence */
    ssd1306_command(SSD1306_DISPLAYOFF);
    
    ssd1306_command(SSD1306_SETDISPLAYCLOCKDIV);
    ssd1306_command(0x80);  /* Suggested ratio */
    
    ssd1306_command(SSD1306_SETMULTIPLEX);
    ssd1306_command(0x3F);  /* 64 MUX */
    
    ssd1306_command(SSD1306_SETDISPLAYOFFSET);
    ssd1306_command(0x00);  /* No offset */
    
    ssd1306_command(SSD1306_SETSTARTLINE | 0x00);
    
    ssd1306_command(SSD1306_CHARGEPUMP);
    ssd1306_command(0x14);  /* Enable charge pump */
    
    ssd1306_command(SSD1306_MEMORYMODE);
    ssd1306_command(0x00);  /* Horizontal addressing mode */
    
    ssd1306_command(SSD1306_SEGREMAP | 0x01);
    ssd1306_command(SSD1306_COMSCANDEC);
    
    ssd1306_command(SSD1306_SETCOMPINS);
    ssd1306_command(0x12);
    
    ssd1306_command(SSD1306_SETCONTRAST);
    ssd1306_command(0xCF);
    
    ssd1306_command(SSD1306_SETPRECHARGE);
    ssd1306_command(0xF1);
    
    ssd1306_command(SSD1306_SETVCOMDETECT);
    ssd1306_command(0x40);
    
    ssd1306_command(SSD1306_DISPLAYALLON_RESUME);
    ssd1306_command(SSD1306_NORMALDISPLAY);
    
    ssd1306_command(SSD1306_DISPLAYON);
    
    /* Clear buffer */
    ssd1306_clear();
}

/**
 * @brief Clear display buffer
 */
void ssd1306_clear(void)
{
    for (uint16_t i = 0; i < sizeof(ssd1306_buffer); i++) {
        ssd1306_buffer[i] = 0x00;
    }
    cursor_x = 0;
    cursor_y = 0;
}

/**
 * @brief Update display with buffer contents
 */
void ssd1306_update(void)
{
    ssd1306_command(SSD1306_COLUMNADDR);
    ssd1306_command(0);
    ssd1306_command(SSD1306_WIDTH - 1);
    
    ssd1306_command(SSD1306_PAGEADDR);
    ssd1306_command(0);
    ssd1306_command(7);  /* 64 pixels / 8 = 8 pages */
    
    gpio_set_pin(SSD1306_DC_PORT, SSD1306_DC_PIN);
    spi_cs_low(SPI_CS_DISPLAY_PORT, SPI_CS_DISPLAY_PIN);
    
    for (uint16_t i = 0; i < sizeof(ssd1306_buffer); i++) {
        spi_transfer(ssd1306_buffer[i]);
    }
    
    spi_cs_high(SPI_CS_DISPLAY_PORT, SPI_CS_DISPLAY_PIN);
}

/**
 * @brief Set cursor position
 */
void ssd1306_set_cursor(uint8_t x, uint8_t y)
{
    cursor_x = x;
    cursor_y = y;
}

/**
 * @brief Write a character to buffer
 */
void ssd1306_write_char(char c)
{
    if (c < 32 || c > 90) {
        c = 32;  /* Replace unknown chars with space */
    }
    
    uint8_t font_index = c - 32;
    
    for (uint8_t i = 0; i < 5; i++) {
        if (cursor_x < SSD1306_WIDTH) {
            uint8_t page = cursor_y / 8;
            uint16_t buffer_index = cursor_x + (page * SSD1306_WIDTH);
            ssd1306_buffer[buffer_index] = font_5x7[font_index][i];
            cursor_x++;
        }
    }
    cursor_x++;  /* Space between characters */
}

/**
 * @brief Write a string to buffer
 */
void ssd1306_write_string(const char *str)
{
    while (*str) {
        ssd1306_write_char(*str++);
    }
}

/**
 * @brief Write a number to buffer
 */
void ssd1306_write_number(uint32_t num)
{
    char buffer[12];
    int i = 0;
    
    if (num == 0) {
        ssd1306_write_char('0');
        return;
    }
    
    while (num > 0) {
        buffer[i++] = '0' + (num % 10);
        num /= 10;
    }
    
    while (i > 0) {
        ssd1306_write_char(buffer[--i]);
    }
}

/**
 * @brief Draw a pixel in buffer
 */
void ssd1306_draw_pixel(uint8_t x, uint8_t y, uint8_t color)
{
    if (x >= SSD1306_WIDTH || y >= SSD1306_HEIGHT) {
        return;
    }
    
    uint8_t page = y / 8;
    uint8_t bit = y % 8;
    uint16_t buffer_index = x + (page * SSD1306_WIDTH);
    
    if (color) {
        ssd1306_buffer[buffer_index] |= (1 << bit);
    } else {
        ssd1306_buffer[buffer_index] &= ~(1 << bit);
    }
}
