#ifndef DELAY_H
#define DELAY_H

#include "stm32f401xx.h"

/* Function Prototypes */
void delay_init(void);
void delay_ms(uint32_t ms);
void delay_us(uint32_t us);

#endif /* DELAY_H */
