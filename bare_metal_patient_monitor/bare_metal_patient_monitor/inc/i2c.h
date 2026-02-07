#ifndef I2C_H
#define I2C_H

#include "stm32f401xx.h"

/* I2C Timeout */
#define I2C_TIMEOUT           10000

/* Function Prototypes */
void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_write_addr(uint8_t addr);
void i2c_write_data(uint8_t data);
uint8_t i2c_read_data(uint8_t ack);
void i2c_write_reg(uint8_t addr, uint8_t reg, uint8_t data);
uint8_t i2c_read_reg(uint8_t addr, uint8_t reg);
void i2c_read_multi(uint8_t addr, uint8_t reg, uint8_t *buffer, uint8_t len);

#endif /* I2C_H */
