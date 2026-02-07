#include "sdcard.h"
#include "spi.h"
#include "gpio.h"
#include "delay.h"

/**
 * @brief Initialize SD card
 * @return 0 on success, 1 on failure
 */
void sdcard_init(void)
{
    uint8_t response;
    uint16_t retry;
    
    /* Deselect SD card */
    spi_cs_high(SPI_CS_SD_PORT, SPI_CS_SD_PIN);
    
    /* Send 80 clock pulses to wake up SD card */
    for (uint8_t i = 0; i < 10; i++) {
        spi_transfer(0xFF);
    }
    
    /* Send CMD0: GO_IDLE_STATE */
    retry = 0;
    do {
        response = sdcard_send_command(CMD0, 0);
        retry++;
    } while (response != SD_IN_IDLE_STATE && retry < 0xFF);
    
    if (response != SD_IN_IDLE_STATE) {
        return;  /* Card not responding */
    }
    
    /* Send CMD8: SEND_IF_COND (for SD Card v2.0) */
    response = sdcard_send_command(CMD8, 0x000001AA);
    
    if (response == SD_IN_IDLE_STATE) {
        /* SD Card v2.0 detected */
        /* Read 4-byte response */
        for (uint8_t i = 0; i < 4; i++) {
            spi_transfer(0xFF);
        }
        
        /* Initialize card with ACMD41 */
        retry = 0;
        do {
            /* Send CMD55 (APP_CMD) before ACMD41 */
            sdcard_send_command(CMD55, 0);
            response = sdcard_send_command(ACMD41, 0x40000000);
            retry++;
            delay_ms(10);
        } while (response != SD_RESPONSE_NO_ERROR && retry < 0xFF);
    } else {
        /* SD Card v1.0 or MMC */
        retry = 0;
        do {
            sdcard_send_command(CMD55, 0);
            response = sdcard_send_command(ACMD41, 0);
            retry++;
            delay_ms(10);
        } while (response != SD_RESPONSE_NO_ERROR && retry < 0xFF);
    }
    
    if (response != SD_RESPONSE_NO_ERROR) {
        return;  /* Card initialization failed */
    }
    
    /* Set block size to 512 bytes */
    sdcard_send_command(CMD16, 512);
    
    delay_ms(10);
}

/**
 * @brief Send command to SD card
 * @param cmd: Command index
 * @param arg: 32-bit argument
 * @return R1 response
 */
uint8_t sdcard_send_command(uint8_t cmd, uint32_t arg)
{
    uint8_t response;
    uint8_t crc;
    
    /* Select SD card */
    spi_cs_low(SPI_CS_SD_PORT, SPI_CS_SD_PIN);
    
    /* Send command packet */
    spi_transfer(cmd);
    spi_transfer((arg >> 24) & 0xFF);
    spi_transfer((arg >> 16) & 0xFF);
    spi_transfer((arg >> 8) & 0xFF);
    spi_transfer(arg & 0xFF);
    
    /* CRC (only matters for CMD0 and CMD8) */
    if (cmd == CMD0) {
        crc = 0x95;
    } else if (cmd == CMD8) {
        crc = 0x87;
    } else {
        crc = 0x01;
    }
    spi_transfer(crc);
    
    /* Wait for response (R1) */
    for (uint8_t i = 0; i < 10; i++) {
        response = spi_transfer(0xFF);
        if (!(response & 0x80)) {
            break;  /* Valid response received */
        }
    }
    
    /* Deselect SD card */
    spi_cs_high(SPI_CS_SD_PORT, SPI_CS_SD_PIN);
    spi_transfer(0xFF);  /* Extra clock cycle */
    
    return response;
}

/**
 * @brief Read single block from SD card
 * @param block_addr: Block address (sector number)
 * @param buffer: Buffer to store 512 bytes
 * @return 0 on success, 1 on failure
 */
uint8_t sdcard_read_block(uint32_t block_addr, uint8_t *buffer)
{
    uint8_t response;
    uint16_t retry;
    
    /* Send READ_SINGLE_BLOCK command */
    spi_cs_low(SPI_CS_SD_PORT, SPI_CS_SD_PIN);
    
    response = sdcard_send_command(CMD17, block_addr);
    if (response != 0x00) {
        spi_cs_high(SPI_CS_SD_PORT, SPI_CS_SD_PIN);
        return 1;
    }
    
    /* Wait for start token (0xFE) */
    retry = 0;
    do {
        response = spi_transfer(0xFF);
        retry++;
    } while (response != SD_START_TOKEN && retry < 0xFFFF);
    
    if (response != SD_START_TOKEN) {
        spi_cs_high(SPI_CS_SD_PORT, SPI_CS_SD_PIN);
        return 1;
    }
    
    /* Read 512 bytes of data */
    for (uint16_t i = 0; i < 512; i++) {
        buffer[i] = spi_transfer(0xFF);
    }
    
    /* Read CRC (2 bytes, but we ignore it) */
    spi_transfer(0xFF);
    spi_transfer(0xFF);
    
    spi_cs_high(SPI_CS_SD_PORT, SPI_CS_SD_PIN);
    spi_transfer(0xFF);
    
    return 0;
}

/**
 * @brief Write single block to SD card
 * @param block_addr: Block address (sector number)
 * @param buffer: Buffer containing 512 bytes to write
 * @return 0 on success, 1 on failure
 */
uint8_t sdcard_write_block(uint32_t block_addr, const uint8_t *buffer)
{
    uint8_t response;
    uint16_t retry;
    
    /* Send WRITE_BLOCK command */
    spi_cs_low(SPI_CS_SD_PORT, SPI_CS_SD_PIN);
    
    response = sdcard_send_command(CMD24, block_addr);
    if (response != 0x00) {
        spi_cs_high(SPI_CS_SD_PORT, SPI_CS_SD_PIN);
        return 1;
    }
    
    /* Send start token */
    spi_transfer(SD_START_TOKEN);
    
    /* Write 512 bytes of data */
    for (uint16_t i = 0; i < 512; i++) {
        spi_transfer(buffer[i]);
    }
    
    /* Send dummy CRC (2 bytes) */
    spi_transfer(0xFF);
    spi_transfer(0xFF);
    
    /* Read data response token */
    response = spi_transfer(0xFF);
    if ((response & 0x1F) != SD_DATA_ACCEPTED) {
        spi_cs_high(SPI_CS_SD_PORT, SPI_CS_SD_PIN);
        return 1;
    }
    
    /* Wait for write to finish (card busy) */
    retry = 0;
    while (spi_transfer(0xFF) == 0x00 && retry < 0xFFFF) {
        retry++;
    }
    
    spi_cs_high(SPI_CS_SD_PORT, SPI_CS_SD_PIN);
    spi_transfer(0xFF);
    
    return 0;
}

/**
 * @brief Write a string to SD card (simple append)
 * @param str: Null-terminated string to write
 * 
 * This is a simplified function that writes to a fixed block.
 * For a real file system, use FAT32 implementation.
 */
void sdcard_write_string(const char *str)
{
    static uint8_t buffer[512] = {0};
    static uint16_t offset = 0;
    static uint32_t current_block = 100;  /* Start at block 100 */
    
    /* Copy string to buffer */
    while (*str && offset < 512) {
        buffer[offset++] = *str++;
    }
    
    /* If buffer is full or end of string, write to card */
    if (offset >= 500) {  /* Leave some margin */
        sdcard_write_block(current_block, buffer);
        current_block++;
        offset = 0;
        
        /* Clear buffer */
        for (uint16_t i = 0; i < 512; i++) {
            buffer[i] = 0;
        }
    }
}
