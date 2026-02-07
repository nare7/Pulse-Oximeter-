#include "spi.h"
#include "gpio.h"

/**
 * @brief Initialize SPI1 peripheral
 *        - PA5: SCK, PA6: MISO, PA7: MOSI
 *        - Mode: Master, Full-Duplex
 *        - Clock: APB2/16 = 84MHz/16 = 5.25MHz
 *        - CPOL=0, CPHA=0
 */
void spi_init(void)
{
    /* Enable SPI1 clock */
    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
    
    /* Configure SPI1 Control Register 1 (CR1) */
    SPI1->CR1 = 0;  /* Clear all bits first */
    
    /* Baud rate control: fPCLK/16 (BR[2:0] = 011) */
    SPI1->CR1 |= (3 << SPI_CR1_BR_Pos);
    
    /* Clock polarity: CPOL = 0 (clock idle low) */
    /* Clock phase: CPHA = 0 (first edge) */
    /* These are default (0), so no setting needed */
    
    /* Master mode */
    SPI1->CR1 |= SPI_CR1_MSTR;
    
    /* Software slave management */
    SPI1->CR1 |= SPI_CR1_SSM;
    SPI1->CR1 |= SPI_CR1_SSI;
    
    /* MSB first (default) */
    /* 8-bit data frame (default) */
    
    /* Enable SPI1 */
    SPI1->CR1 |= SPI_CR1_SPE;
}

/**
 * @brief Transmit and receive one byte via SPI
 * @param data: Data byte to transmit
 * @return Received data byte
 */
uint8_t spi_transfer(uint8_t data)
{
    /* Wait until TXE (Transmit buffer Empty) */
    while (!(SPI1->SR & SPI_SR_TXE));
    
    /* Write data to data register */
    SPI1->DR = data;
    
    /* Wait until RXNE (Receive buffer Not Empty) */
    while (!(SPI1->SR & SPI_SR_RXNE));
    
    /* Read and return received data */
    return SPI1->DR;
}

/**
 * @brief Pull CS line low (select device)
 * @param port: GPIO port
 * @param pin: GPIO pin number
 */
void spi_cs_low(GPIO_TypeDef *port, uint8_t pin)
{
    gpio_reset_pin(port, pin);
}

/**
 * @brief Pull CS line high (deselect device)
 * @param port: GPIO port
 * @param pin: GPIO pin number
 */
void spi_cs_high(GPIO_TypeDef *port, uint8_t pin)
{
    gpio_set_pin(port, pin);
}
