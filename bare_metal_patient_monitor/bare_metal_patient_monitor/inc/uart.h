#ifndef UART_H
#define UART_H

#include "stm32f401xx.h"

/* Function Prototypes */
void uart_init(void);
void uart_send_char(char c);
void uart_send_string(const char *str);
void uart_send_number(uint32_t num);

#endif /* UART_H */
