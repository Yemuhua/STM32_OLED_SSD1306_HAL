# STM32_OLED_SSD1306_HAL

基于 STM32F103C8T6 开发测试的SSD1306 OLED驱动，移植自u8g2并做精简，理论上支持全系列stm32，不支持标准库。大一项目，代码可能有些纰漏，感谢各位指正。

## 用法
1. 把 `User/` 文件夹复制到你的工程
2. 添加头文件路径
3. `#include "oled_app.h"`
4. `OLED_App_Init(&hi2c1, 0x78);`

## 依赖
- STM32 HAL库
- I2C已初始化（PB6/PB7）
- 时钟72MHz（HSE）

## 文件结构
- Bsp/   硬件操作层
- Port/  u8g2适配层  
- App/   应用接口层

## 致谢
- [u8g2](https://github.com/olikraus/u8g2)
