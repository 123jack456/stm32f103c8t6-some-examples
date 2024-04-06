//////////////////////////////////////////////////////////////////////////////////	 
//±æ≥Ã–Ú÷ªπ©—ßœ∞ π”√£¨Œ¥æ≠◊˜’ﬂ–Ìø…£¨≤ªµ√”√”⁄∆‰À¸»Œ∫Œ”√Õæ
//  π¶ƒ‹√Ë ˆ   : 1.8¥ÁLCD 4Ω”ø⁄—› æ¿˝≥Ã(STM32œµ¡–)
/******************************************************************************
//±æ≥Ã–Ú  ”√”ÎSTM32F103C8
//              GND   µÁ‘¥µÿ
//              VCC   Ω”5VªÚ3.3vµÁ‘¥
//              SCL   Ω”PA5£®SCL£©
//              SDA   Ω”PA7£®SDA£©
//              RES   Ω”PB0
//              DC    Ω”PB1
//              CS    Ω”PA4 
//							BL		Ω”PB10
*******************************************************************************/
//#include "stm32f1xx_hal.h"
#include "Lcd_Driver.h"
#include "LCD_Config.h"



void LCD_RESET(){
	RST_Pin_L;
	HAL_Delay(1);
	RST_Pin_H;
	HAL_Delay(120);
}

void lcd_write_data(uint8_t data)
{
	CS_Pin_L;
	DC_Pin_H;
	for(int i = 0; i < 8; i++)
	{
		if(data & 0x80)	SDA_Pin_H;
		else			SDA_Pin_L;
		SCL_Pin_L;
		SCL_Pin_H;
		data = data << 1;
	}
	CS_Pin_H;
}

//ÂÜôÊìç‰Ωú: DC = 0
void lcd_write_command(uint8_t data)
{
	CS_Pin_L;
	DC_Pin_L;
	for(int i = 0; i < 8; i++)
	{
		if(data & 0x80)	SDA_Pin_H;
		else			SDA_Pin_L;
		SCL_Pin_L;
		SCL_Pin_H;
		data = data << 1;
	}
	CS_Pin_H;
}

//ÂÜôÂçÅÂÖ≠‰ΩçÊï∞ÊçÆ
void lcd_write_data_u16(uint16_t data)
{
	lcd_write_data(data >> 8);	
	lcd_write_data(data & 0x0f);	
}

void lcd_init()
{
	LCD_RESET();//Reset before LCD Init.
		
	//LCD Init For 1.44Inch LCD Panel with ST7735R.
	lcd_write_command(0x11);//Sleep exit ÈÄÄÂá∫Áù°Áú†Ê®°Âºè
	HAL_Delay(120);
		
	//ST7735R Frame Rate	 4 È¢úËâ≤Âà∑Êñ∞Áéá
	lcd_write_command(0xB1); 
	lcd_write_data(0x01); 
	lcd_write_data(0x2C); 
	lcd_write_data(0x2D); 
									
	lcd_write_command(0xB2); 
	lcd_write_data(0x01); 
	lcd_write_data(0x2C); 
	lcd_write_data(0x2D); 

	lcd_write_command(0xB3); 
	lcd_write_data(0x01); 
	lcd_write_data(0x2C); 
	lcd_write_data(0x2D); 
	lcd_write_data(0x01); 
	lcd_write_data(0x2C); 
	lcd_write_data(0x2D); 
	
	lcd_write_command(0xB4); //Column inversion 
	lcd_write_data(0x07); 
	
	//ST7735R Power Sequence
	lcd_write_command(0xC0); 
	lcd_write_data(0xA2); 
	lcd_write_data(0x02); 
	lcd_write_data(0x84); 
	lcd_write_command(0xC1); 
	lcd_write_data(0xC5); 

	lcd_write_command(0xC2); 
	lcd_write_data(0x0A); 
	lcd_write_data(0x00); 

	lcd_write_command(0xC3); 
	lcd_write_data(0x8A); 
	lcd_write_data(0x2A); 
	lcd_write_command(0xC4); 
	lcd_write_data(0x8A); 
	lcd_write_data(0xEE); 
	
	lcd_write_command(0xC5); //VCOM 
	lcd_write_data(0x0E); 
	
	lcd_write_command(0x36); //MX, MY, RGB mode 
	lcd_write_data(0xA0); //Á´ñÂ±èC8 Ê®™Â±è08 A8
//	lcd_write_data(0xC0); //Á´ñÂ±èC8 Ê®™Â±è08 A8 
	
	//ST7735R Gamma Sequence
	lcd_write_command(0xe0); 
	lcd_write_data(0x0f); 
	lcd_write_data(0x1a); 
	lcd_write_data(0x0f); 
	lcd_write_data(0x18); 
	lcd_write_data(0x2f); 
	lcd_write_data(0x28); 
	lcd_write_data(0x20); 
	lcd_write_data(0x22); 
	lcd_write_data(0x1f); 
	lcd_write_data(0x1b); 
	lcd_write_data(0x23); 
	lcd_write_data(0x37); 
	lcd_write_data(0x00); 	
	lcd_write_data(0x07); 
	lcd_write_data(0x02); 
	lcd_write_data(0x10); 

	lcd_write_command(0xe1); 
	lcd_write_data(0x0f); 
	lcd_write_data(0x1b); 
	lcd_write_data(0x0f); 
	lcd_write_data(0x17); 
	lcd_write_data(0x33); 
	lcd_write_data(0x2c); 
	lcd_write_data(0x29); 
	lcd_write_data(0x2e); 
	lcd_write_data(0x30); 
	lcd_write_data(0x30); 
	lcd_write_data(0x39); 
	lcd_write_data(0x3f); 
	lcd_write_data(0x00); 
	lcd_write_data(0x07); 
	lcd_write_data(0x03); 
	lcd_write_data(0x10);  
	
	lcd_write_command(0x2a);
	lcd_write_data(0x00);
	lcd_write_data(0x00+2);
	lcd_write_data(0x00);
	lcd_write_data(0x80+2);

	lcd_write_command(0x2b);
	lcd_write_data(0x00);
	lcd_write_data(0x00+3);
	lcd_write_data(0x00);
	lcd_write_data(0x80+3);
	
	lcd_write_command(0xF0); //Enable test command  
	lcd_write_data(0x01); 
	lcd_write_command(0xF6); //Disable ram power save mode 
	lcd_write_data(0x00); 
	
	lcd_write_command(0x3A); //65k mode 
	lcd_write_data(0x05); 
	
	
	lcd_write_command(0x29);//Display on
}

//ÂÜôÂÖ•Â±èÂπïÂú∞ÂùÄÂáΩÊï∞
void lcd_write_address(uint8_t x_start,uint8_t y_start,uint8_t x_end,uint8_t y_end)
{
	lcd_write_command(0x2a);
	lcd_write_data(x_start >> 8);
	lcd_write_data(x_start);
	lcd_write_data(x_end >> 8);
	lcd_write_data(x_end);
	
	lcd_write_command(0x2b);
	lcd_write_data(y_start >> 8);
	lcd_write_data(y_start);
	lcd_write_data(y_end >> 8);
	lcd_write_data(y_end);	
	
	lcd_write_command(0x2c);
}

//ÂÖ®Â±èÈ¢úËâ≤Â°´ÂÖÖ
void lcd_set_color(uint16_t color)
{
	lcd_write_address(0,0,159,127);//ÂÉèÁ¥†160*128
	for(int i = 0; i < 160; i++)
	{
		for(int j = 0; j < 128; j++)
		{
			lcd_write_data_u16(color);
		}
	}
} 


//Âå∫ÂüüÈ¢úËâ≤Â°´ÂÖÖ
void lcd_set_area_color(uint8_t x_start,uint8_t y_start,uint8_t x_end,uint8_t y_end,uint16_t color)
{
	lcd_write_address(x_start,y_start,x_end,y_end);
	//ËÆ°ÁÆóÂ°´ÂÖÖÂå∫ÂüüÁöÑÈïøÂ∫¶ÂíåÂÆΩÂ∫¶ÔºåÁªàÁÇπÂùêÊ†áÂáèËµ∑ÁÇπÂùêÊ†á+1
	uint8_t x_len = x_end - x_start + 1;//ËÆ°ÁÆóxÂùêÊ†áÁöÑÈïøÂ∫¶
	uint8_t y_len = y_end - y_start + 1;//ËÆ°ÁÆóyÂùêÊ†áÁöÑÈïøÂ∫¶
	for(int i = 0; i < x_len; i++)
	{
		for(int j = 0; j < y_len; j++)
		{
			lcd_write_data_u16(color);
		}
	}
}

//ÊèèÁÇπÂáΩÊï∞
void lcd_set_point_color(uint8_t x_point,uint8_t y_point,uint16_t color)
{
	lcd_write_address(x_point,y_point,x_point,y_point);
	lcd_write_data_u16(color);
}

void lcd_draw_line(uint8_t x_point,uint8_t y_point,uint8_t length,uint16_t color){
	for(uint8_t i=0;i<length;i++){
	lcd_set_point_color(x_point+i,y_point,color);
	}
	
}


void showimage(const unsigned char *p) //ÊòæÁ§∫ÂõæÁâá
{
	unsigned char picH,picL;
//	lcd_set_color(0XFFFF); //Ê∏ÖÂ±è  

	lcd_write_address(0,0,159,127);

	for(uint16_t i=0;i<160*128;i++)
	 {	
		picL=*(p+i*2);	//Êï∞ÊçÆ‰Ωé‰ΩçÂú®Ââç
		picH=*(p+i*2+1);				
	   lcd_write_data_u16(picH<<8|picL);  						
	 }	
}

void showPicture(void){
	showimage(gImage_zz);
}

/*
	colÂàóÔºå1-10Âàó
	rowË°åÔºå1-8Ë°å
	16*16

	uint8_t i;
	
	OLED_SetCursor(y,x);
	for(i=0;i<16;i++){
		OLED_WriteData(OLED[loc][i]);
	}
	OLED_SetCursor(y+1,x);
	for(i=0;i<16;i++){
		OLED_WriteData(OLED[loc][i+16]);
	}
*/
void showChinese(uint8_t row,uint8_t col,uint16_t backcolor,uint8_t fontcolor,uint8_t loc){
//	lcd_write_address((row-1)*16,(col-1)*16,(row-1)*16+16-1,(row-1)*16+16-1);
	lcd_write_address((col-1)*16,(row-1)*16,(col-1)*16+16-1,(row-1)*16+16-1);
	for(uint16_t k=0;k<16*2;k++)
	 {
		 for(uint16_t i=0;i<8;i++){
		 if(fronts[loc][k]&(0x01<<i)){
			lcd_write_data_u16(fontcolor);
		 }else{
			lcd_write_data_u16(backcolor);	 
		 }
	 }
	 }
	
}

/*
void showChinese(uint8_t row,uint8_t col,uint16_t color,uint8_t loc){

	
	
	uint8_t temp;
	
	uint8_t count=0,b=0;
	
		for(uint16_t k=0;k<16;k++)
	 {
	 	temp=fronts[loc][k];
	 	
	 	if(k%2==0 &&k!=0){
	 		b++;
		 }
		 
		 
		 for(uint16_t i=0;i<8;i++){
		 	if(temp&(0x01<<i)){
					lcd_set_point_color((row-1)*16+b,(col-1)*16+8*count+i,WHITE);
				}
				else{			
					lcd_set_point_color((row-1)*16+b,(col-1)*16+8*count+i,color);
				}
//		 	printf(" %d %d \n",(row-1)*16+b,(col-1)*16+8*count+i);
		 }
			count++;
		 	count%=2;
	 	
	 }
//	 printf("--------------------------\n");
	 b++;
	 	for(uint16_t k=0;k<16;k++)
	 {
	 	temp=fronts[loc+1][k];
	 	
	 	if(k%2==0 &&k!=0){
	 		b++;
		 }
		 
		 
//		 printf("%#x\n",temp);
		 for(uint16_t i=0;i<8;i++){
		 	if(temp&(0x01<<i)){
					lcd_set_point_color((row-1)*16+b,(col-1)*16+8*count+i,WHITE);
				}
				else{			
					lcd_set_point_color((row-1)*16+b,(col-1)*16+8*count+i,color);
				}
//		 	printf(" %d %d \n",(row-1)*16+b,(col-1)*16+8*count+i);
		 }
			count++;
		 	count%=2;
	 	
	 }
	
	
		
	
	
	
	 
	
}
*/
//col 1-20
//row 1-8
/*ÂÆΩ8ÂÉèÁ¥†ÔºåÈ´ò16ÂÉèÁ¥†*/

void showchar(uint8_t row,uint8_t col,uint16_t backcolor,uint8_t fontcolor,uint8_t Char){
	
	lcd_write_address((col-1)*8,(row-1)*16,(col-1)*8+8-1,(row-1)*16+16-1);
	for(uint16_t k=0;k<16;k++)
	 {
//		 OLED_F8x16[Char - ' '][i + 8]
		 for(uint16_t i=0;i<8;i++){
		 if(tft_8x16[Char - ' '][k]&(0x01<<i)){
			lcd_write_data_u16(fontcolor);
		 }else{
			lcd_write_data_u16(backcolor);	 
		 }
	 }
	 }
	
}

void OLED_ShowString(uint8_t row,uint8_t col,uint16_t backcolor,uint8_t fontcolor, char *String)
{
	uint8_t i;
	for (i = 0; String[i] != '\0'; i++)
	{
		showchar(row, col+i,backcolor,fontcolor, String[i]);
	}
}
