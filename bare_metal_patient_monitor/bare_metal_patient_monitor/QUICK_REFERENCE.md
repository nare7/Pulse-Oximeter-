# STM32F401 Register Programming Quick Reference

## 🔧 GPIO Configuration

### Enable Clock
```c
RCC->AHB1ENR |= (1 << 0);  // GPIOA
RCC->AHB1ENR |= (1 << 1);  // GPIOB
```

### Configure Pin Mode
```c
// Mode: 00=Input, 01=Output, 10=AF, 11=Analog
GPIOA->MODER &= ~(3 << (2 * pin_number));  // Clear
GPIOA->MODER |= (mode << (2 * pin_number)); // Set
```

### Configure Alternate Function
```c
// AFR[0] = pins 0-7, AFR[1] = pins 8-15
GPIOA->AFR[0] &= ~(0xF << (4 * pin));
GPIOA->AFR[0] |= (af_number << (4 * pin));
```

### Set/Reset Pin
```c
GPIOA->BSRR = (1 << pin);        // Set
GPIOA->BSRR = (1 << (pin + 16)); // Reset
GPIOA->ODR ^= (1 << pin);        // Toggle
```

## 📡 I2C Configuration

### Enable and Configure
```c
RCC->APB1ENR |= (1 << 21);       // Enable I2C1 clock
I2C1->CR2 = 42;                  // APB1 frequency (42MHz)
I2C1->CCR = 210;                 // 100kHz I2C clock
I2C1->TRISE = 43;                // Rise time
I2C1->CR1 |= (1 << 0);          // Enable I2C
```

### I2C Transaction
```c
// Start
I2C1->CR1 |= (1 << 8);
while(!(I2C1->SR1 & (1 << 0)));

// Send Address
I2C1->DR = (address << 1);
while(!(I2C1->SR1 & (1 << 1)));
(void)I2C1->SR1; (void)I2C1->SR2;

// Send Data
while(!(I2C1->SR1 & (1 << 7)));
I2C1->DR = data;

// Stop
I2C1->CR1 |= (1 << 9);
```

## 🔄 SPI Configuration

### Enable and Configure
```c
RCC->APB2ENR |= (1 << 12);       // Enable SPI1
SPI1->CR1 = 0;
SPI1->CR1 |= (3 << 3);          // Baud = fPCLK/16
SPI1->CR1 |= (1 << 2);          // Master mode
SPI1->CR1 |= (1 << 9);          // SSM
SPI1->CR1 |= (1 << 8);          // SSI
SPI1->CR1 |= (1 << 6);          // Enable SPI
```

### SPI Transfer
```c
while(!(SPI1->SR & (1 << 1)));   // Wait TXE
SPI1->DR = data;
while(!(SPI1->SR & (1 << 0)));   // Wait RXNE
return SPI1->DR;
```

## 📤 USART Configuration

### Enable and Configure
```c
RCC->APB1ENR |= (1 << 17);       // Enable USART2
USART2->BRR = 0x16D;             // 115200 @ 42MHz
USART2->CR1 |= (1 << 3);        // TE enable
USART2->CR1 |= (1 << 2);        // RE enable
USART2->CR1 |= (1 << 13);       // UE enable
```

### Send/Receive
```c
// Send
while(!(USART2->SR & (1 << 7))); // Wait TXE
USART2->DR = data;

// Receive
while(!(USART2->SR & (1 << 5))); // Wait RXNE
return USART2->DR;
```

## ⏱️ Timer Configuration

### Enable and Configure
```c
RCC->APB1ENR |= (1 << 0);        // Enable TIM2
TIM2->PSC = 83;                  // Prescaler
TIM2->ARR = 999;                 // Auto-reload
TIM2->CR1 |= (1 << 0);          // Enable counter
```

### Delay Implementation
```c
void delay_ms(uint32_t ms) {
    for(uint32_t i = 0; i < ms; i++) {
        for(volatile uint32_t j = 0; j < 8400; j++) {
            __asm volatile ("nop");
        }
    }
}
```

## 🔬 ADC Configuration

### Enable and Configure
```c
RCC->APB2ENR |= (1 << 8);        // Enable ADC1
ADC1->SMPR2 |= (7 << (3 * ch)); // Sample time 480 cycles
ADC1->SQR1 = 0;                  // 1 conversion
ADC1->SQR3 = channel;            // Channel number
ADC1->CR2 |= (1 << 1);          // Continuous mode
ADC1->CR2 |= (1 << 0);          // ADON
```

### Read ADC
```c
ADC1->CR2 |= (1 << 30);          // Start conversion
while(!(ADC1->SR & (1 << 1)));   // Wait EOC
return ADC1->DR;
```

## 📝 Register Bit Definitions

### RCC Registers
```c
RCC->AHB1ENR   // AHB1 peripheral clock enable
RCC->APB1ENR   // APB1 peripheral clock enable
RCC->APB2ENR   // APB2 peripheral clock enable
```

### Common Bit Operations
```c
// Set bit
REG |= (1 << bit);

// Clear bit
REG &= ~(1 << bit);

// Toggle bit
REG ^= (1 << bit);

// Test bit
if(REG & (1 << bit)) { }

// Clear and set multiple bits
REG &= ~(mask << position);
REG |= (value << position);
```

## 🎯 Memory Map

```
0x0800 0000 - 0x087F FFFF : FLASH (512KB)
0x2000 0000 - 0x2001 7FFF : SRAM (96KB)
0x4000 0000 - 0x4007 FFFF : APB1 Peripherals
0x4001 0000 - 0x4001 5FFF : APB2 Peripherals
0x4002 0000 - 0x4002 3FFF : AHB1 Peripherals

Peripheral Base Addresses:
GPIOA:  0x4002 0000
GPIOB:  0x4002 0400
GPIOC:  0x4002 0800
I2C1:   0x4000 5400
SPI1:   0x4001 3000
USART2: 0x4000 4400
TIM2:   0x4000 0000
ADC1:   0x4001 2000
RCC:    0x4002 3800
```

## 🔍 Debugging Tips

### Read Register Values
```c
volatile uint32_t reg_value = PERIPHERAL->REGISTER;
```

### UART Printf
```c
void uart_print_hex(uint32_t value) {
    char buffer[9];
    for(int i = 7; i >= 0; i--) {
        uint8_t nibble = (value >> (i * 4)) & 0xF;
        buffer[7-i] = (nibble < 10) ? ('0' + nibble) : ('A' + nibble - 10);
    }
    buffer[8] = '\0';
    uart_send_string(buffer);
}
```

### LED Toggle for Debugging
```c
// Quick visual feedback
GPIOC->ODR ^= (1 << 13);
delay_ms(100);
```

## 📊 Clock Tree (STM32F401)

```
HSI (16MHz) ──┐
              ├─→ PLL ──→ SYSCLK (up to 84MHz)
HSE (8MHz) ──┘            │
                          ├─→ AHB (HCLK) = 84MHz
                          │   └─→ Cortex-M4
                          │
                          ├─→ APB1 (PCLK1) = 42MHz
                          │   └─→ I2C, USART2, TIM2
                          │
                          └─→ APB2 (PCLK2) = 84MHz
                              └─→ SPI1, ADC1
```

## ⚡ Quick Start Template

```c
#include "stm32f401xx.h"

int main(void) {
    // Enable GPIO clock
    RCC->AHB1ENR |= (1 << 2);  // GPIOC
    
    // Configure PC13 as output (LED)
    GPIOC->MODER &= ~(3 << (2 * 13));
    GPIOC->MODER |= (1 << (2 * 13));
    
    while(1) {
        // Toggle LED
        GPIOC->ODR ^= (1 << 13);
        
        // Delay
        for(volatile uint32_t i = 0; i < 1000000; i++);
    }
}
```

---
**Remember**: Always refer to the STM32F401 Reference Manual for complete register details!
