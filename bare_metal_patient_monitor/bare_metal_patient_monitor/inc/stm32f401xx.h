#ifndef STM32F401XX_H
#define STM32F401XX_H

#include <stdint.h>

/* ==================== BASE ADDRESSES ==================== */
#define PERIPH_BASE           0x40000000UL
#define AHB1_BASE             (PERIPH_BASE + 0x00020000UL)
#define APB1_BASE             (PERIPH_BASE + 0x00000000UL)
#define APB2_BASE             (PERIPH_BASE + 0x00010000UL)

/* ==================== PERIPHERAL BASE ADDRESSES ==================== */
#define GPIOA_BASE            (AHB1_BASE + 0x0000UL)
#define GPIOB_BASE            (AHB1_BASE + 0x0400UL)
#define GPIOC_BASE            (AHB1_BASE + 0x0800UL)
#define RCC_BASE              (AHB1_BASE + 0x3800UL)
#define I2C1_BASE             (APB1_BASE + 0x5400UL)
#define SPI1_BASE             (APB2_BASE + 0x3000UL)
#define SPI2_BASE             (APB1_BASE + 0x3800UL)
#define USART2_BASE           (APB1_BASE + 0x4400UL)
#define TIM2_BASE             (APB1_BASE + 0x0000UL)
#define ADC1_BASE             (APB2_BASE + 0x2000UL)

/* ==================== GPIO STRUCTURE ==================== */
typedef struct {
    volatile uint32_t MODER;      /* GPIO port mode register */
    volatile uint32_t OTYPER;     /* GPIO port output type register */
    volatile uint32_t OSPEEDR;    /* GPIO port output speed register */
    volatile uint32_t PUPDR;      /* GPIO port pull-up/pull-down register */
    volatile uint32_t IDR;        /* GPIO port input data register */
    volatile uint32_t ODR;        /* GPIO port output data register */
    volatile uint32_t BSRR;       /* GPIO port bit set/reset register */
    volatile uint32_t LCKR;       /* GPIO port configuration lock register */
    volatile uint32_t AFR[2];     /* GPIO alternate function registers */
} GPIO_TypeDef;

/* ==================== RCC STRUCTURE ==================== */
typedef struct {
    volatile uint32_t CR;         /* RCC clock control register */
    volatile uint32_t PLLCFGR;    /* RCC PLL configuration register */
    volatile uint32_t CFGR;       /* RCC clock configuration register */
    volatile uint32_t CIR;        /* RCC clock interrupt register */
    volatile uint32_t AHB1RSTR;   /* RCC AHB1 peripheral reset register */
    volatile uint32_t AHB2RSTR;   /* RCC AHB2 peripheral reset register */
    uint32_t RESERVED0[2];
    volatile uint32_t APB1RSTR;   /* RCC APB1 peripheral reset register */
    volatile uint32_t APB2RSTR;   /* RCC APB2 peripheral reset register */
    uint32_t RESERVED1[2];
    volatile uint32_t AHB1ENR;    /* RCC AHB1 peripheral clock enable register */
    volatile uint32_t AHB2ENR;    /* RCC AHB2 peripheral clock enable register */
    uint32_t RESERVED2[2];
    volatile uint32_t APB1ENR;    /* RCC APB1 peripheral clock enable register */
    volatile uint32_t APB2ENR;    /* RCC APB2 peripheral clock enable register */
} RCC_TypeDef;

/* ==================== I2C STRUCTURE ==================== */
typedef struct {
    volatile uint32_t CR1;        /* I2C Control register 1 */
    volatile uint32_t CR2;        /* I2C Control register 2 */
    volatile uint32_t OAR1;       /* I2C Own address register 1 */
    volatile uint32_t OAR2;       /* I2C Own address register 2 */
    volatile uint32_t DR;         /* I2C Data register */
    volatile uint32_t SR1;        /* I2C Status register 1 */
    volatile uint32_t SR2;        /* I2C Status register 2 */
    volatile uint32_t CCR;        /* I2C Clock control register */
    volatile uint32_t TRISE;      /* I2C TRISE register */
} I2C_TypeDef;

/* ==================== SPI STRUCTURE ==================== */
typedef struct {
    volatile uint32_t CR1;        /* SPI control register 1 */
    volatile uint32_t CR2;        /* SPI control register 2 */
    volatile uint32_t SR;         /* SPI status register */
    volatile uint32_t DR;         /* SPI data register */
    volatile uint32_t CRCPR;      /* SPI CRC polynomial register */
    volatile uint32_t RXCRCR;     /* SPI RX CRC register */
    volatile uint32_t TXCRCR;     /* SPI TX CRC register */
    volatile uint32_t I2SCFGR;    /* SPI_I2S configuration register */
    volatile uint32_t I2SPR;      /* SPI_I2S prescaler register */
} SPI_TypeDef;

/* ==================== USART STRUCTURE ==================== */
typedef struct {
    volatile uint32_t SR;         /* USART Status register */
    volatile uint32_t DR;         /* USART Data register */
    volatile uint32_t BRR;        /* USART Baud rate register */
    volatile uint32_t CR1;        /* USART Control register 1 */
    volatile uint32_t CR2;        /* USART Control register 2 */
    volatile uint32_t CR3;        /* USART Control register 3 */
    volatile uint32_t GTPR;       /* USART Guard time and prescaler register */
} USART_TypeDef;

/* ==================== TIM STRUCTURE ==================== */
typedef struct {
    volatile uint32_t CR1;        /* TIM control register 1 */
    volatile uint32_t CR2;        /* TIM control register 2 */
    volatile uint32_t SMCR;       /* TIM slave mode control register */
    volatile uint32_t DIER;       /* TIM DMA/interrupt enable register */
    volatile uint32_t SR;         /* TIM status register */
    volatile uint32_t EGR;        /* TIM event generation register */
    volatile uint32_t CCMR1;      /* TIM capture/compare mode register 1 */
    volatile uint32_t CCMR2;      /* TIM capture/compare mode register 2 */
    volatile uint32_t CCER;       /* TIM capture/compare enable register */
    volatile uint32_t CNT;        /* TIM counter */
    volatile uint32_t PSC;        /* TIM prescaler */
    volatile uint32_t ARR;        /* TIM auto-reload register */
    uint32_t RESERVED1;
    volatile uint32_t CCR1;       /* TIM capture/compare register 1 */
    volatile uint32_t CCR2;       /* TIM capture/compare register 2 */
    volatile uint32_t CCR3;       /* TIM capture/compare register 3 */
    volatile uint32_t CCR4;       /* TIM capture/compare register 4 */
    uint32_t RESERVED2;
    volatile uint32_t DCR;        /* TIM DMA control register */
    volatile uint32_t DMAR;       /* TIM DMA address for full transfer */
    volatile uint32_t OR;         /* TIM option register */
} TIM_TypeDef;

/* ==================== ADC STRUCTURE ==================== */
typedef struct {
    volatile uint32_t SR;         /* ADC status register */
    volatile uint32_t CR1;        /* ADC control register 1 */
    volatile uint32_t CR2;        /* ADC control register 2 */
    volatile uint32_t SMPR1;      /* ADC sample time register 1 */
    volatile uint32_t SMPR2;      /* ADC sample time register 2 */
    volatile uint32_t JOFR1;      /* ADC injected channel data offset register 1 */
    volatile uint32_t JOFR2;      /* ADC injected channel data offset register 2 */
    volatile uint32_t JOFR3;      /* ADC injected channel data offset register 3 */
    volatile uint32_t JOFR4;      /* ADC injected channel data offset register 4 */
    volatile uint32_t HTR;        /* ADC watchdog higher threshold register */
    volatile uint32_t LTR;        /* ADC watchdog lower threshold register */
    volatile uint32_t SQR1;       /* ADC regular sequence register 1 */
    volatile uint32_t SQR2;       /* ADC regular sequence register 2 */
    volatile uint32_t SQR3;       /* ADC regular sequence register 3 */
    volatile uint32_t JSQR;       /* ADC injected sequence register */
    volatile uint32_t JDR1;       /* ADC injected data register 1 */
    volatile uint32_t JDR2;       /* ADC injected data register 2 */
    volatile uint32_t JDR3;       /* ADC injected data register 3 */
    volatile uint32_t JDR4;       /* ADC injected data register 4 */
    volatile uint32_t DR;         /* ADC regular data register */
} ADC_TypeDef;

/* ==================== PERIPHERAL DECLARATIONS ==================== */
#define GPIOA                 ((GPIO_TypeDef*)GPIOA_BASE)
#define GPIOB                 ((GPIO_TypeDef*)GPIOB_BASE)
#define GPIOC                 ((GPIO_TypeDef*)GPIOC_BASE)
#define RCC                   ((RCC_TypeDef*)RCC_BASE)
#define I2C1                  ((I2C_TypeDef*)I2C1_BASE)
#define SPI1                  ((SPI_TypeDef*)SPI1_BASE)
#define SPI2                  ((SPI_TypeDef*)SPI2_BASE)
#define USART2                ((USART_TypeDef*)USART2_BASE)
#define TIM2                  ((TIM_TypeDef*)TIM2_BASE)
#define ADC1                  ((ADC_TypeDef*)ADC1_BASE)

/* ==================== BIT DEFINITIONS ==================== */
/* RCC AHB1ENR */
#define RCC_AHB1ENR_GPIOAEN   (1 << 0)
#define RCC_AHB1ENR_GPIOBEN   (1 << 1)
#define RCC_AHB1ENR_GPIOCEN   (1 << 2)

/* RCC APB1ENR */
#define RCC_APB1ENR_TIM2EN    (1 << 0)
#define RCC_APB1ENR_SPI2EN    (1 << 14)
#define RCC_APB1ENR_USART2EN  (1 << 17)
#define RCC_APB1ENR_I2C1EN    (1 << 21)

/* RCC APB2ENR */
#define RCC_APB2ENR_ADC1EN    (1 << 8)
#define RCC_APB2ENR_SPI1EN    (1 << 12)

/* I2C CR1 */
#define I2C_CR1_PE            (1 << 0)
#define I2C_CR1_START         (1 << 8)
#define I2C_CR1_STOP          (1 << 9)
#define I2C_CR1_ACK           (1 << 10)

/* I2C SR1 */
#define I2C_SR1_SB            (1 << 0)
#define I2C_SR1_ADDR          (1 << 1)
#define I2C_SR1_BTF           (1 << 2)
#define I2C_SR1_TXE           (1 << 7)
#define I2C_SR1_RXNE          (1 << 6)

/* SPI CR1 */
#define SPI_CR1_SPE           (1 << 6)
#define SPI_CR1_BR_Pos        3
#define SPI_CR1_MSTR          (1 << 2)
#define SPI_CR1_SSM           (1 << 9)
#define SPI_CR1_SSI           (1 << 8)

/* SPI SR */
#define SPI_SR_TXE            (1 << 1)
#define SPI_SR_RXNE           (1 << 0)
#define SPI_SR_BSY            (1 << 7)

/* USART SR */
#define USART_SR_TXE          (1 << 7)
#define USART_SR_RXNE         (1 << 5)

/* USART CR1 */
#define USART_CR1_UE          (1 << 13)
#define USART_CR1_TE          (1 << 3)
#define USART_CR1_RE          (1 << 2)

#endif /* STM32F401XX_H */
