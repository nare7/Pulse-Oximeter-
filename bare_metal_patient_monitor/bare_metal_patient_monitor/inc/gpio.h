#ifndef GPIO_H
#define GPIO_H

#include "stm32f401xx.h"

/* GPIO Mode Definitions */
#define GPIO_MODE_INPUT       0x00
#define GPIO_MODE_OUTPUT      0x01
#define GPIO_MODE_AF          0x02
#define GPIO_MODE_ANALOG      0x03

/* GPIO Output Type */
#define GPIO_OTYPE_PP         0x00
#define GPIO_OTYPE_OD         0x01

/* GPIO Speed */
#define GPIO_SPEED_LOW        0x00
#define GPIO_SPEED_MEDIUM     0x01
#define GPIO_SPEED_FAST       0x02
#define GPIO_SPEED_HIGH       0x03

/* GPIO Pull-up/Pull-down */
#define GPIO_PUPD_NONE        0x00
#define GPIO_PUPD_PU          0x01
#define GPIO_PUPD_PD          0x02

/* Function Prototypes */
void gpio_init(void);
void gpio_set_pin(GPIO_TypeDef *GPIOx, uint8_t pin);
void gpio_reset_pin(GPIO_TypeDef *GPIOx, uint8_t pin);
void gpio_toggle_pin(GPIO_TypeDef *GPIOx, uint8_t pin);
uint8_t gpio_read_pin(GPIO_TypeDef *GPIOx, uint8_t pin);

#endif /* GPIO_H */
