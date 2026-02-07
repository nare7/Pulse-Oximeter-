#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "stm32f401xx.h"

/* ADC Channel for Temperature Sensor (example: PA0 = ADC1_IN0) */
#define TEMP_ADC_CHANNEL      0

/* Function Prototypes */
void temperature_init(void);
float temperature_read(void);
uint16_t adc_read(void);

#endif /* TEMPERATURE_H */
