#ifndef __OLED_H__
#define __OLED_H__

#include "stm32f1xx_hal.h"

void OLED_Init(I2C_HandleTypeDef *hi2c, uint8_t i2c_addr);
uint8_t OLED_WriteBytes(uint8_t *data, uint16_t len, uint8_t is_cmd);
void OLED_DelayMs(uint32_t ms);

#endif
