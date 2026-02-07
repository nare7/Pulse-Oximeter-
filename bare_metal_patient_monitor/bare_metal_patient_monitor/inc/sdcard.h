#ifndef SDCARD_H
#define SDCARD_H

#include "stm32f401xx.h"

/* SD Card Commands */
#define CMD0    0x40  /* GO_IDLE_STATE */
#define CMD1    0x41  /* SEND_OP_COND */
#define CMD8    0x48  /* SEND_IF_COND */
#define CMD9    0x49  /* SEND_CSD */
#define CMD10   0x4A  /* SEND_CID */
#define CMD12   0x4C  /* STOP_TRANSMISSION */
#define CMD16   0x50  /* SET_BLOCKLEN */
#define CMD17   0x51  /* READ_SINGLE_BLOCK */
#define CMD18   0x52  /* READ_MULTIPLE_BLOCK */
#define CMD23   0x57  /* SET_BLOCK_COUNT */
#define CMD24   0x58  /* WRITE_BLOCK */
#define CMD25   0x59  /* WRITE_MULTIPLE_BLOCK */
#define CMD55   0x77  /* APP_CMD */
#define CMD58   0x7A  /* READ_OCR */
#define ACMD41  0x69  /* SD_SEND_OP_COND */

/* SD Card Response Tokens */
#define SD_RESPONSE_NO_ERROR      0x00
#define SD_IN_IDLE_STATE          0x01
#define SD_START_TOKEN            0xFE
#define SD_DATA_ACCEPTED          0x05

/* Function Prototypes */
void sdcard_init(void);
uint8_t sdcard_send_command(uint8_t cmd, uint32_t arg);
uint8_t sdcard_read_block(uint32_t block_addr, uint8_t *buffer);
uint8_t sdcard_write_block(uint32_t block_addr, const uint8_t *buffer);
void sdcard_write_string(const char *str);

#endif /* SDCARD_H */
