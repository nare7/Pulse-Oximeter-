#ifndef SPI_H
#define SPI_H

#include "stm32f401xx.h"

/* SPI Chip Select Pins */
#define SPI_CS_DISPLAY_PORT   GPIOB
#define SPI_CS_DISPLAY_PIN    6

#define SPI_CS_SD_PORT        GPIOA
#define SPI_CS_SD_PIN         4

/* Function Prototypes */
void spi_init(void);
uint8_t spi_transfer(uint8_t data);
void spi_cs_low(GPIO_TypeDef *port, uint8_t pin);
void spi_cs_high(GPIO_TypeDef *port, uint8_t pin);

#endif /* SPI_H */
