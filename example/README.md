## 本驱动已在 STM32F103C8T6 + 0.96寸 SSD1306 上实测通过。
## 1_Hello 例程使用说明

这是一个最简显示例程，显示 "hello,github!"。

### 使用方法
1. CubeMX 配置（必须一致）

    在 CubeMX 中完成以下配置（和你 `main.c` 里的时钟设置对应）：

- **I2C1**  
  - 引脚：PB6 (SCL), PB7 (SDA)  
  - 模式：Standard Mode (100kHz) 或 Fast Mode (400kHz) 均可  
  - 上拉：开启内部上拉

- **时钟树 (RCC)**  
  - HSE：8MHz 外部晶振  
  - PLL：9倍频 → 72MHz  
  - APB1：/2 → 36MHz（I2C时钟源）
  - FLASH：2等待周期
2. 把本仓库的 `User/` 文件夹复制到你的工程根目录

3. 在 CubeMX 生成的 `main.c` 中：
   - 添加头文件：`#include "oled_app.h"`
   - 在 `/* USER CODE BEGIN 2 */` 区域添加：
     ```c
     HAL_Delay(100);
     OLED_App_Init(&hi2c1, 0x78);
     OLED_App_ShowString(30, 36, "hello,github!");
     ```

4. 编译烧录

### 参考
完整的 `main.c` 示例见同目录下的 `main.c.example`