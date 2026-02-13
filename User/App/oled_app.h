#ifndef OLED_APP_H
#define OLED_APP_H

#include "u8g2.h"
#include "stm32f1xx_hal.h" 

// ========== 初始化 ==========
// 传I2C句柄和地址，自动完成所有初始化
void OLED_App_Init(I2C_HandleTypeDef *hi2c, uint8_t i2c_addr);

// ========== 基础显示 ==========
// 清屏
void OLED_App_Clear(void);

// 显示字符串（自动换行处理）
void OLED_App_ShowString(uint8_t x, uint8_t y, const char *str);

// 显示数字（自动转字符串）
void OLED_App_ShowNum(uint8_t x, uint8_t y, uint32_t num, uint8_t len);

// ========== 高级功能 ==========
// 显示参数表（温湿度、气压等）
void OLED_App_ShowParamTable(float temp, float humi, float press);

// ========== 调试专用 ==========
// 全屏填充（测试屏幕用）
void OLED_App_FillTest(void);

#endif


