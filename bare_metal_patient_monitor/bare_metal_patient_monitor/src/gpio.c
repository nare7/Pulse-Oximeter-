#include "gpio.h"

/**
 * @brief Initialize all GPIO pins for the project
 *        - PA2, PA3: USART2 TX/RX (AF7)
 *        - PA5, PA6, PA7: SPI1 SCK, MISO, MOSI (AF5)
 *        - PA4: SPI1 CS for SD Card (Output)
 *        - PB6, PB7, PB8: SPI Display CS, DC, RST (Output)
 *        - PB8, PB9: I2C1 SCL, SDA (AF4)
 *        - PA0: ADC1_IN0 for temperature sensor
 */
void gpio_init(void)
{
    /* Enable GPIO clocks */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;  /* Enable GPIOA clock */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;  /* Enable GPIOB clock */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;  /* Enable GPIOC clock */
    
    /* ========== Configure USART2 Pins (PA2=TX, PA3=RX) ========== */
    /* PA2: Alternate Function (AF7) */
    GPIOA->MODER &= ~(3 << (2 * 2));      /* Clear mode bits */
    GPIOA->MODER |= (2 << (2 * 2));       /* Set alternate function mode */
    GPIOA->AFR[0] &= ~(0xF << (4 * 2));   /* Clear AF bits */
    GPIOA->AFR[0] |= (7 << (4 * 2));      /* Set AF7 (USART2) */
    GPIOA->OSPEEDR |= (3 << (2 * 2));     /* High speed */
    
    /* PA3: Alternate Function (AF7) */
    GPIOA->MODER &= ~(3 << (2 * 3));
    GPIOA->MODER |= (2 << (2 * 3));
    GPIOA->AFR[0] &= ~(0xF << (4 * 3));
    GPIOA->AFR[0] |= (7 << (4 * 3));
    GPIOA->OSPEEDR |= (3 << (2 * 3));
    
    /* ========== Configure SPI1 Pins (PA5=SCK, PA6=MISO, PA7=MOSI) ========== */
    /* PA5: Alternate Function (AF5) */
    GPIOA->MODER &= ~(3 << (2 * 5));
    GPIOA->MODER |= (2 << (2 * 5));
    GPIOA->AFR[0] &= ~(0xF << (4 * 5));
    GPIOA->AFR[0] |= (5 << (4 * 5));      /* Set AF5 (SPI1) */
    GPIOA->OSPEEDR |= (3 << (2 * 5));     /* High speed */
    
    /* PA6: Alternate Function (AF5) */
    GPIOA->MODER &= ~(3 << (2 * 6));
    GPIOA->MODER |= (2 << (2 * 6));
    GPIOA->AFR[0] &= ~(0xF << (4 * 6));
    GPIOA->AFR[0] |= (5 << (4 * 6));
    GPIOA->OSPEEDR |= (3 << (2 * 6));
    
    /* PA7: Alternate Function (AF5) */
    GPIOA->MODER &= ~(3 << (2 * 7));
    GPIOA->MODER |= (2 << (2 * 7));
    GPIOA->AFR[0] &= ~(0xF << (4 * 7));
    GPIOA->AFR[0] |= (5 << (4 * 7));
    GPIOA->OSPEEDR |= (3 << (2 * 7));
    
    /* PA4: Output for SD Card CS */
    GPIOA->MODER &= ~(3 << (2 * 4));
    GPIOA->MODER |= (1 << (2 * 4));       /* Output mode */
    GPIOA->OTYPER &= ~(1 << 4);           /* Push-pull */
    GPIOA->OSPEEDR |= (3 << (2 * 4));     /* High speed */
    GPIOA->ODR |= (1 << 4);               /* Set CS high (deselect) */
    
    /* ========== Configure I2C1 Pins (PB8=SCL, PB9=SDA) ========== */
    /* PB8: Alternate Function (AF4), Open-Drain */
    GPIOB->MODER &= ~(3 << (2 * 8));
    GPIOB->MODER |= (2 << (2 * 8));       /* Alternate function mode */
    GPIOB->OTYPER |= (1 << 8);            /* Open-drain */
    GPIOB->OSPEEDR |= (3 << (2 * 8));     /* High speed */
    GPIOB->PUPDR &= ~(3 << (2 * 8));
    GPIOB->PUPDR |= (1 << (2 * 8));       /* Pull-up */
    GPIOB->AFR[1] &= ~(0xF << (4 * 0));   /* PB8 is in AFR[1] */
    GPIOB->AFR[1] |= (4 << (4 * 0));      /* Set AF4 (I2C1) */
    
    /* PB9: Alternate Function (AF4), Open-Drain */
    GPIOB->MODER &= ~(3 << (2 * 9));
    GPIOB->MODER |= (2 << (2 * 9));
    GPIOB->OTYPER |= (1 << 9);
    GPIOB->OSPEEDR |= (3 << (2 * 9));
    GPIOB->PUPDR &= ~(3 << (2 * 9));
    GPIOB->PUPDR |= (1 << (2 * 9));
    GPIOB->AFR[1] &= ~(0xF << (4 * 1));
    GPIOB->AFR[1] |= (4 << (4 * 1));
    
    /* ========== Configure Display Control Pins (PB6=CS, PB7=DC, PB8=RST) ========== */
    /* PB6: Output for Display CS */
    GPIOB->MODER &= ~(3 << (2 * 6));
    GPIOB->MODER |= (1 << (2 * 6));
    GPIOB->OTYPER &= ~(1 << 6);
    GPIOB->OSPEEDR |= (3 << (2 * 6));
    GPIOB->ODR |= (1 << 6);               /* Set CS high */
    
    /* PB7: Output for Display DC */
    GPIOB->MODER &= ~(3 << (2 * 7));
    GPIOB->MODER |= (1 << (2 * 7));
    GPIOB->OTYPER &= ~(1 << 7);
    GPIOB->OSPEEDR |= (3 << (2 * 7));
    
    /* Note: PB8 is used for I2C SCL, not RST in this config */
    /* If RST needed, use different pin like PC0 */
    
    /* ========== Configure ADC Pin (PA0) ========== */
    /* PA0: Analog mode for ADC */
    GPIOA->MODER &= ~(3 << (2 * 0));
    GPIOA->MODER |= (3 << (2 * 0));       /* Analog mode */
    
    /* ========== Configure LED Pin (PC13 - onboard LED) ========== */
    GPIOC->MODER &= ~(3 << (2 * 13));
    GPIOC->MODER |= (1 << (2 * 13));      /* Output mode */
    GPIOC->OTYPER &= ~(1 << 13);          /* Push-pull */
}

/**
 * @brief Set a GPIO pin high
 */
void gpio_set_pin(GPIO_TypeDef *GPIOx, uint8_t pin)
{
    GPIOx->BSRR = (1 << pin);
}

/**
 * @brief Set a GPIO pin low
 */
void gpio_reset_pin(GPIO_TypeDef *GPIOx, uint8_t pin)
{
    GPIOx->BSRR = (1 << (pin + 16));
}

/**
 * @brief Toggle a GPIO pin
 */
void gpio_toggle_pin(GPIO_TypeDef *GPIOx, uint8_t pin)
{
    GPIOx->ODR ^= (1 << pin);
}

/**
 * @brief Read a GPIO pin state
 */
uint8_t gpio_read_pin(GPIO_TypeDef *GPIOx, uint8_t pin)
{
    return (GPIOx->IDR & (1 << pin)) ? 1 : 0;
}
