#include "uart.h"

/**
 * @brief Initialize USART2 peripheral
 *        - PA2: TX, PA3: RX
 *        - Baud rate: 115200
 *        - 8 data bits, 1 stop bit, no parity
 *        - APB1 Clock: 42MHz
 */
void uart_init(void)
{
    /* Enable USART2 clock */
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    
    /* Calculate baud rate
     * BRR = fCK / (16 * baud_rate)
     * For 115200 baud at 42MHz APB1 clock:
     * BRR = 42000000 / (16 * 115200) = 22.786
     * Mantissa = 22, Fraction = 0.786 * 16 = 12.576 ≈ 13
     * BRR = (22 << 4) | 13 = 0x16D
     */
    USART2->BRR = 0x16D;
    
    /* Configure USART2 Control Register 1 */
    USART2->CR1 = 0;  /* Clear all bits */
    
    /* Enable transmitter */
    USART2->CR1 |= USART_CR1_TE;
    
    /* Enable receiver */
    USART2->CR1 |= USART_CR1_RE;
    
    /* Enable USART */
    USART2->CR1 |= USART_CR1_UE;
}

/**
 * @brief Send one character via UART
 * @param c: Character to send
 */
void uart_send_char(char c)
{
    /* Wait until TXE (Transmit Data Register Empty) */
    while (!(USART2->SR & USART_SR_TXE));
    
    /* Write data to data register */
    USART2->DR = c;
}

/**
 * @brief Send a string via UART
 * @param str: Null-terminated string to send
 */
void uart_send_string(const char *str)
{
    while (*str) {
        uart_send_char(*str++);
    }
}

/**
 * @brief Send a number as ASCII string via UART
 * @param num: Number to send
 */
void uart_send_number(uint32_t num)
{
    char buffer[12];  /* Max 10 digits + sign + null */
    int i = 0;
    
    /* Handle zero case */
    if (num == 0) {
        uart_send_char('0');
        return;
    }
    
    /* Convert number to string (reverse order) */
    while (num > 0) {
        buffer[i++] = '0' + (num % 10);
        num /= 10;
    }
    
    /* Send string in correct order */
    while (i > 0) {
        uart_send_char(buffer[--i]);
    }
}
