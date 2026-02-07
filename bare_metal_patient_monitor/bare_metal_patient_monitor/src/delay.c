#include "delay.h"

static volatile uint32_t tick_counter = 0;

/**
 * @brief Initialize TIM2 for delay functions
 *        - APB1 Timer Clock: 84MHz (after doubling)
 *        - Configure for 1ms tick
 */
void delay_init(void)
{
    /* Enable TIM2 clock */
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    
    /* Configure TIM2 for 1ms tick
     * Timer Clock = 84MHz (APB1 x2 when APB1 prescaler != 1)
     * Prescaler = 84 - 1 (to get 1MHz)
     * Auto-reload = 1000 - 1 (to get 1ms period)
     */
    TIM2->PSC = 83;        /* Prescaler: 84MHz / 84 = 1MHz */
    TIM2->ARR = 999;       /* Auto-reload: 1MHz / 1000 = 1kHz (1ms) */
    
    /* Enable update interrupt */
    TIM2->DIER |= (1 << 0);
    
    /* Clear update flag */
    TIM2->SR &= ~(1 << 0);
    
    /* Enable counter */
    TIM2->CR1 |= (1 << 0);
}

/**
 * @brief Simple blocking delay in milliseconds
 * @param ms: Delay time in milliseconds
 */
void delay_ms(uint32_t ms)
{
    /* Simple approach using busy-wait loop
     * For more accuracy, use timer-based delay with interrupts
     */
    for (uint32_t i = 0; i < ms; i++) {
        /* Approximate 1ms delay at 84MHz
         * Adjust multiplier based on actual clock frequency
         */
        for (volatile uint32_t j = 0; j < 8400; j++) {
            __asm volatile ("nop");
        }
    }
}

/**
 * @brief Simple blocking delay in microseconds
 * @param us: Delay time in microseconds
 */
void delay_us(uint32_t us)
{
    /* Approximate delay for microseconds
     * Adjust multiplier based on actual clock frequency
     */
    for (uint32_t i = 0; i < us; i++) {
        for (volatile uint32_t j = 0; j < 8; j++) {
            __asm volatile ("nop");
        }
    }
}

/**
 * @brief TIM2 interrupt handler (if using interrupt-based delay)
 */
void TIM2_IRQHandler(void)
{
    if (TIM2->SR & (1 << 0)) {
        /* Clear update interrupt flag */
        TIM2->SR &= ~(1 << 0);
        
        /* Increment tick counter */
        tick_counter++;
    }
}
