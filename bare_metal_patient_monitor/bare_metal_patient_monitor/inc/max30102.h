#ifndef MAX30102_H
#define MAX30102_H

#include "stm32f401xx.h"

/* MAX30102 I2C Address */
#define MAX30102_ADDR         0x57

/* MAX30102 Register Addresses */
#define MAX30102_INT_STATUS_1 0x00
#define MAX30102_INT_STATUS_2 0x01
#define MAX30102_INT_ENABLE_1 0x02
#define MAX30102_INT_ENABLE_2 0x03
#define MAX30102_FIFO_WR_PTR  0x04
#define MAX30102_FIFO_RD_PTR  0x06
#define MAX30102_FIFO_DATA    0x07
#define MAX30102_FIFO_CONFIG  0x08
#define MAX30102_MODE_CONFIG  0x09
#define MAX30102_SPO2_CONFIG  0x0A
#define MAX30102_LED1_PA      0x0C
#define MAX30102_LED2_PA      0x0D
#define MAX30102_TEMP_INT     0x1F
#define MAX30102_TEMP_FRAC    0x20
#define MAX30102_TEMP_CONFIG  0x21
#define MAX30102_REV_ID       0xFE
#define MAX30102_PART_ID      0xFF

/* Mode Configuration */
#define MAX30102_MODE_SPO2    0x03
#define MAX30102_MODE_HR      0x02

/* SpO2 Configuration */
#define MAX30102_SPO2_SR_100  0x00
#define MAX30102_SPO2_SR_200  0x01
#define MAX30102_SPO2_SR_400  0x02
#define MAX30102_SPO2_SR_800  0x03

#define MAX30102_SPO2_PW_69   0x00
#define MAX30102_SPO2_PW_118  0x01
#define MAX30102_SPO2_PW_215  0x02
#define MAX30102_SPO2_PW_411  0x03

/* FIFO Configuration */
#define MAX30102_FIFO_SAMPLES 0x0F

/* Data Structure */
typedef struct {
    uint32_t red;
    uint32_t ir;
} MAX30102_Data;

/* Function Prototypes */
void max30102_init(void);
void max30102_reset(void);
uint8_t max30102_get_part_id(void);
void max30102_read_fifo(MAX30102_Data *data);
void max30102_read_temperature(float *temp);
uint8_t max30102_data_available(void);

#endif /* MAX30102_H */
