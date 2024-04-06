//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//  功能描述   : 1.8寸LCD 4接口演示例程(STM32系列)
/******************************************************************************
//本程序适用与STM32F103C8
//              GND   电源地
//              VCC   接5V或3.3v电源
//              SCL   接PA5（SCL）
//              SDA   接PA7（SDA）
//              RES   接PB0
//              DC    接PB1
//              CS    接PA4 
//							BL		接PB10
*******************************************************************************/
#ifndef LCD_DRIVER_H
#define LCD_DRIVER_H

#include "stm32f1xx_hal.h"
//#include "main.h"
//#include "LCD_Config.h"
#include "gpio.h"

#define u8 uint8_t 
#define u16 uint16_t 

#define RED  	0xf800
#define GREEN	0x07e0
#define BLUE 	0x001f
#define WHITE	0xffff
#define BLACK	0x0000
#define YELLOW  0xFFE0
#define GRAY0   0xEF7D   	//灰色0 3165 00110 001011 00101
#define GRAY1   0x8410      	//灰色1      00000 000000 00000
#define GRAY2   0x4208      	//灰色2  1111111111011111


//#define DC_Pin GPIO_PIN_1
//#define DC_GPIO_Port GPIOA
//#define RST_Pin GPIO_PIN_2
//#define RST_GPIO_Port GPIOA
//#define CS_Pin GPIO_PIN_4
//#define CS_GPIO_Port GPIOA
//#define SCL_Pin GPIO_PIN_5
//#define SCL_GPIO_Port GPIOA
//#define SDA_Pin GPIO_PIN_7
//#define SDA_GPIO_Port GPIOA

#define DC_Pin_L HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin,GPIO_PIN_RESET)
#define DC_Pin_H HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin,GPIO_PIN_SET)

#define RST_Pin_L HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin,GPIO_PIN_RESET)
#define RST_Pin_H HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin,GPIO_PIN_SET)

#define CS_Pin_L  HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,GPIO_PIN_RESET)
#define CS_Pin_H  HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,GPIO_PIN_SET)

#define SCL_Pin_L HAL_GPIO_WritePin(SCL_GPIO_Port,SCL_Pin,GPIO_PIN_RESET)
#define SCL_Pin_H HAL_GPIO_WritePin(SCL_GPIO_Port,SCL_Pin,GPIO_PIN_SET)

#define SDA_Pin_L HAL_GPIO_WritePin(SDA_GPIO_Port,SDA_Pin,GPIO_PIN_RESET)
#define SDA_Pin_H HAL_GPIO_WritePin(SDA_GPIO_Port,SDA_Pin,GPIO_PIN_SET)

void lcd_init(void);
void lcd_set_color(uint16_t color);
void lcd_set_area_color(uint8_t x_start,uint8_t y_start,uint8_t x_end,uint8_t y_end,uint16_t color);
void showimage(const unsigned char *p);
void lcd_set_point_color(uint8_t x_point,uint8_t y_point,uint16_t color);
void lcd_draw_line(uint8_t x_point,uint8_t y_point,uint8_t length,uint16_t color);
void showChinese(uint8_t row,uint8_t col,uint16_t backcolor,uint8_t fontcolor,uint8_t loc);
void showPicture(void);
void showchar(uint8_t row,uint8_t col,uint16_t backcolor,uint8_t fontcolor,uint8_t loc);
void OLED_ShowString(uint8_t row,uint8_t col,uint16_t backcolor,uint8_t fontcolor, char *String);
#endif
