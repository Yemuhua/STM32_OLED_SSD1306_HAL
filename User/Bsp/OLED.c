#include "oled.h"

static I2C_HandleTypeDef *g_hi2c = NULL;
static uint8_t g_i2c_addr = 0;

void OLED_Init(I2C_HandleTypeDef *hi2c,uint8_t i2c_addr)
{
	g_hi2c = hi2c;
	g_i2c_addr = i2c_addr;

}

uint8_t OLED_WriteBytes(uint8_t *data, uint16_t len, uint8_t is_cmd)
{
	 if(g_hi2c == NULL) return 0;
    
    uint8_t ctrl = is_cmd ? 0x00 : 0x40;
    uint8_t buffer[len + 1];
    buffer[0] = ctrl;
    
    for(uint16_t i = 0; i < len; i++)
        buffer[i + 1] = data[i];
    
    if(HAL_I2C_Master_Transmit(g_hi2c, g_i2c_addr, buffer, len + 1, 100)!=HAL_OK)
		{
			return 0;
		}
		return 1;
}

void OLED_DelayMs(uint32_t ms)
{
	HAL_Delay(ms);
}
