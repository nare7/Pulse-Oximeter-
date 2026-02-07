#include "i2c.h"
#include "delay.h"

/**
 * @brief Initialize I2C1 peripheral
 *        - Clock: 100kHz (Standard Mode)
 *        - PB8: SCL, PB9: SDA
 *        - APB1 Clock: 42MHz (assuming default config)
 */
void i2c_init(void)
{
    /* Enable I2C1 clock */
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
    
    /* Reset I2C1 */
    RCC->APB1RSTR |= (1 << 21);
    RCC->APB1RSTR &= ~(1 << 21);
    
    /* Disable I2C1 before configuration */
    I2C1->CR1 &= ~I2C_CR1_PE;
    
    /* Configure I2C1 timing */
    /* APB1 Clock = 42MHz, Target I2C Clock = 100kHz */
    I2C1->CR2 = 42;  /* FREQ = 42MHz */
    
    /* CCR calculation for 100kHz: 
     * T_high = T_low = CCR * T_PCLK1
     * T_scl = 2 * CCR * T_PCLK1
     * CCR = T_scl / (2 * T_PCLK1) = 10us / (2 * 1/42MHz) = 210
     */
    I2C1->CCR = 210;
    
    /* Configure rise time: Max rise time = 1000ns
     * TRISE = (max_rise_time / T_PCLK1) + 1 = (1000ns / 23.8ns) + 1 = 43
     */
    I2C1->TRISE = 43;
    
    /* Enable I2C1 */
    I2C1->CR1 |= I2C_CR1_PE;
}

/**
 * @brief Generate I2C start condition
 */
void i2c_start(void)
{
    /* Generate START condition */
    I2C1->CR1 |= I2C_CR1_START;
    
    /* Wait for SB flag (Start Bit) */
    uint32_t timeout = I2C_TIMEOUT;
    while (!(I2C1->SR1 & I2C_SR1_SB) && timeout--);
}

/**
 * @brief Generate I2C stop condition
 */
void i2c_stop(void)
{
    /* Generate STOP condition */
    I2C1->CR1 |= I2C_CR1_STOP;
}

/**
 * @brief Send 7-bit address on I2C bus
 * @param addr: 7-bit slave address (will be shifted left)
 */
void i2c_write_addr(uint8_t addr)
{
    /* Send address with write bit (0) */
    I2C1->DR = (addr << 1);
    
    /* Wait for ADDR flag */
    uint32_t timeout = I2C_TIMEOUT;
    while (!(I2C1->SR1 & I2C_SR1_ADDR) && timeout--);
    
    /* Clear ADDR flag by reading SR1 and SR2 */
    (void)I2C1->SR1;
    (void)I2C1->SR2;
}

/**
 * @brief Write one byte of data to I2C bus
 * @param data: Data byte to write
 */
void i2c_write_data(uint8_t data)
{
    /* Wait for TXE flag (Transmit Data Register Empty) */
    uint32_t timeout = I2C_TIMEOUT;
    while (!(I2C1->SR1 & I2C_SR1_TXE) && timeout--);
    
    /* Write data to DR */
    I2C1->DR = data;
    
    /* Wait for BTF flag (Byte Transfer Finished) */
    timeout = I2C_TIMEOUT;
    while (!(I2C1->SR1 & I2C_SR1_BTF) && timeout--);
}

/**
 * @brief Read one byte of data from I2C bus
 * @param ack: 1 to send ACK, 0 to send NACK
 * @return Read data byte
 */
uint8_t i2c_read_data(uint8_t ack)
{
    uint32_t timeout = I2C_TIMEOUT;
    
    if (ack) {
        /* Enable ACK */
        I2C1->CR1 |= I2C_CR1_ACK;
    } else {
        /* Disable ACK (send NACK) */
        I2C1->CR1 &= ~I2C_CR1_ACK;
    }
    
    /* Wait for RXNE flag (Receive Data Register Not Empty) */
    while (!(I2C1->SR1 & I2C_SR1_RXNE) && timeout--);
    
    /* Read and return data */
    return I2C1->DR;
}

/**
 * @brief Write data to a specific register of I2C device
 * @param addr: 7-bit slave address
 * @param reg: Register address
 * @param data: Data to write
 */
void i2c_write_reg(uint8_t addr, uint8_t reg, uint8_t data)
{
    i2c_start();
    i2c_write_addr(addr);
    i2c_write_data(reg);
    i2c_write_data(data);
    i2c_stop();
}

/**
 * @brief Read data from a specific register of I2C device
 * @param addr: 7-bit slave address
 * @param reg: Register address
 * @return Read data byte
 */
uint8_t i2c_read_reg(uint8_t addr, uint8_t reg)
{
    uint8_t data;
    
    /* Write register address */
    i2c_start();
    i2c_write_addr(addr);
    i2c_write_data(reg);
    
    /* Repeated start for read */
    i2c_start();
    I2C1->DR = (addr << 1) | 0x01;  /* Address with read bit */
    
    /* Wait for ADDR flag */
    uint32_t timeout = I2C_TIMEOUT;
    while (!(I2C1->SR1 & I2C_SR1_ADDR) && timeout--);
    
    /* Disable ACK before clearing ADDR flag for single byte read */
    I2C1->CR1 &= ~I2C_CR1_ACK;
    
    /* Clear ADDR flag */
    (void)I2C1->SR1;
    (void)I2C1->SR2;
    
    /* Generate STOP before reading data */
    I2C1->CR1 |= I2C_CR1_STOP;
    
    /* Wait for RXNE */
    timeout = I2C_TIMEOUT;
    while (!(I2C1->SR1 & I2C_SR1_RXNE) && timeout--);
    
    /* Read data */
    data = I2C1->DR;
    
    return data;
}

/**
 * @brief Read multiple bytes from I2C device
 * @param addr: 7-bit slave address
 * @param reg: Starting register address
 * @param buffer: Buffer to store read data
 * @param len: Number of bytes to read
 */
void i2c_read_multi(uint8_t addr, uint8_t reg, uint8_t *buffer, uint8_t len)
{
    /* Write register address */
    i2c_start();
    i2c_write_addr(addr);
    i2c_write_data(reg);
    
    /* Repeated start for read */
    i2c_start();
    I2C1->DR = (addr << 1) | 0x01;
    
    /* Wait for ADDR flag */
    uint32_t timeout = I2C_TIMEOUT;
    while (!(I2C1->SR1 & I2C_SR1_ADDR) && timeout--);
    
    /* Clear ADDR flag */
    (void)I2C1->SR1;
    (void)I2C1->SR2;
    
    /* Enable ACK */
    I2C1->CR1 |= I2C_CR1_ACK;
    
    /* Read data bytes */
    for (uint8_t i = 0; i < len; i++) {
        if (i == len - 1) {
            /* Last byte: disable ACK and generate STOP */
            I2C1->CR1 &= ~I2C_CR1_ACK;
            I2C1->CR1 |= I2C_CR1_STOP;
        }
        
        /* Wait for RXNE */
        timeout = I2C_TIMEOUT;
        while (!(I2C1->SR1 & I2C_SR1_RXNE) && timeout--);
        
        /* Read data */
        buffer[i] = I2C1->DR;
    }
}
