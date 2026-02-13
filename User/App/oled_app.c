#include "oled_app.h"
#include "oled.h"
#include <stdio.h>
#include "u8g2_port.h"

static u8g2_t u8g2;

void OLED_App_Init(I2C_HandleTypeDef *hi2c, uint8_t i2c_addr)
{
		// 1. BSP层：硬件初始化
    OLED_Init(hi2c, i2c_addr);
    
    // 2. Port层：配置u8g2回调
		u8g2_Setup_ssd1306_i2c_128x64_noname_f(
        &u8g2,
        U8G2_R0,
        u8g2_byte_cb,
        u8g2_gpio_cb
    );
			
    // 3. 初始化屏幕
    u8g2_InitDisplay(&u8g2);

    u8g2_SetPowerSave(&u8g2, 0);
    
    // 4. 设置默认字体
    u8g2_SetFont(&u8g2, u8g2_font_6x10_tr);
    
    // 5. 清屏
    OLED_App_Clear();
}

// ========== 基础显示 ==========
void OLED_App_Clear(void)
{
    u8g2_ClearBuffer(&u8g2);
    u8g2_SendBuffer(&u8g2);
}

void OLED_App_ShowString(uint8_t x, uint8_t y, const char *str)
{
    u8g2_DrawStr(&u8g2, x, y, str);
    u8g2_SendBuffer(&u8g2);
}

void OLED_App_ShowNum(uint8_t x, uint8_t y, uint32_t num, uint8_t len)
{
    char buf[12];
    
    // 格式化：按指定长度，前面补0
    // len=3, num=5 -> "005"
    sprintf(buf, "%0*d", len, num);
    
    u8g2_DrawStr(&u8g2, x, y, buf);
    u8g2_SendBuffer(&u8g2);
}

// ========== 参数表 ==========
void OLED_App_ShowParamTable(float temp, float humi, float press)
{
    char buf[20];
    
    u8g2_ClearBuffer(&u8g2);
    
    // 第一行：温度
    sprintf(buf, "Temp: %.1f C", temp);
    u8g2_DrawStr(&u8g2, 0, 12, buf);
    
    // 第二行：湿度
    sprintf(buf, "Humi: %.1f %%", humi);
    u8g2_DrawStr(&u8g2, 0, 24, buf);
    
    // 第三行：气压
    sprintf(buf, "Press: %.1f kPa", press);
    u8g2_DrawStr(&u8g2, 0, 36, buf);
    
    u8g2_SendBuffer(&u8g2);
}

// ========== 测试模式 ==========
void OLED_App_FillTest(void)
{
    // 全屏填充
    u8g2_ClearBuffer(&u8g2);
    u8g2_DrawBox(&u8g2, 0, 0, 128, 64);
    u8g2_SendBuffer(&u8g2);
    OLED_DelayMs(500);
    
    // 清屏
    u8g2_ClearBuffer(&u8g2);
    u8g2_SendBuffer(&u8g2);
    OLED_DelayMs(500);
    
    // 画网格
    for(uint8_t x = 0; x < 128; x+=8) {
        u8g2_DrawVLine(&u8g2, x, 0, 64);
    }
    for(uint8_t y = 0; y < 64; y+=8) {
        u8g2_DrawHLine(&u8g2, 0, y, 128);
    }
    u8g2_SendBuffer(&u8g2);
}


