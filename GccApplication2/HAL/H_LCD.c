/*
 * LCD.c
 *
 * Created: 4/15/2023 8:28:41 PM
 *  Author: hussein
 */ 
#include "H_LCD.h"
#include <string.h>
int g=0 ,h=0;
void H_LCD_send_command( LCD_object lcd,u8 command){
	_delay_ms(10);
	M_DIO_set_pin_value(lcd.LCD_enable_port,lcd.LCD_RS_pin,low); //RS
	if (lcd.mode==_8_bit)
	{
		M_DIO_set_pin_value(lcd.LCD_enable_port,lcd.LCD_enable_pin,high);
		M_DIO_set_port_value(lcd.LCD_port,command);
		_delay_us(10);
		M_DIO_set_pin_value(lcd.LCD_enable_port,lcd.LCD_enable_pin,low);
	}
	else if (lcd.mode==_4_bit)
	{
		//high nipples
		M_DIO_set_pin_value(lcd.LCD_enable_port,lcd.LCD_enable_pin,high);
		M_DIO_clear_port_mask(lcd.LCD_port,0xF0);
		M_DIO_set_port_value_mask(lcd.LCD_port,(command&0xF0));
		_delay_us(10);
		M_DIO_set_pin_value(lcd.LCD_enable_port,lcd.LCD_enable_pin,low);
		_delay_ms(10);
		//low nipples
		M_DIO_set_pin_value(lcd.LCD_enable_port,lcd.LCD_enable_pin,high);
		M_DIO_clear_port_mask(lcd.LCD_port,0xF0);
		M_DIO_set_port_value_mask(lcd.LCD_port,(command&0x0F)<<4);
		_delay_us(10);
		M_DIO_set_pin_value(lcd.LCD_enable_port,lcd.LCD_enable_pin,low);
		
	}
}


void H_LCD_clear( LCD_object lcd){
	g=0;
	h=0;
	H_LCD_send_command(lcd,0x01);
}


void H_LCD_init(LCD_object lcd){
	M_DIO_set_pin_direction(lcd.LCD_enable_port,lcd.LCD_enable_pin,output);
	M_DIO_set_pin_direction(lcd.LCD_enable_port,lcd.LCD_RS_pin,output);
	M_DIO_set_pin_direction(lcd.LCD_enable_port,lcd.LCD_RW_pin,output);
	M_DIO_set_pin_value(lcd.LCD_enable_port,lcd.LCD_RW_pin,low);
	
	if (lcd.mode==_8_bit)
	{
		//pin direction
		M_DIO_set_port_direction(lcd.LCD_port,output);
		M_DIO_clear_port_mask(lcd.LCD_port,0b11111111);
		//wait till power up
		_delay_ms(1000);
		H_LCD_send_command(lcd,0x02);
		//first command
		H_LCD_send_command(lcd,0x38);
		//second command
		H_LCD_send_command(lcd,0x0F);
	}
	else if (lcd.mode==_4_bit)
	{
		M_DIO_set_port_direction_mask(lcd.LCD_port,output,0b11110000);
		//wait till power up
		_delay_ms(1000);
		H_LCD_send_command(lcd,0x02);
		//first command
		H_LCD_send_command(lcd,0x28);
		//second command
		H_LCD_send_command(lcd,0x0F);
	}
	H_LCD_clear(lcd);
}


void H_LCD_dispaly_char(LCD_object lcd,u8 letter){
	g++;
	if (g==17)
	{
		H_LCD_send_command(lcd,0xC0);
		g=1;
		h++;
		if (h==2)
		{
			H_LCD_send_command(lcd,0x01);
			H_LCD_send_command(lcd,0x80);
			g=0;
			h=0;
		}
	}
	_delay_ms(10);
	M_DIO_set_pin_value(lcd.LCD_enable_port,lcd.LCD_RS_pin,high);  //RS
	if (lcd.mode==_8_bit)
	{
		M_DIO_set_pin_value(lcd.LCD_enable_port,lcd.LCD_enable_pin,high);
		M_DIO_set_port_value(lcd.LCD_port,letter);
		_delay_us(10);
		M_DIO_set_pin_value(lcd.LCD_enable_port,lcd.LCD_enable_pin,low);
	}
	else if (lcd.mode==_4_bit)
	{
		M_DIO_clear_port_mask(lcd.LCD_port,0xF0);
		M_DIO_set_port_value_mask(lcd.LCD_port,(letter&0xF0));
		M_DIO_set_pin_value(lcd.LCD_enable_port,lcd.LCD_enable_pin,high);
		_delay_us(10);
		M_DIO_set_pin_value(lcd.LCD_enable_port,lcd.LCD_enable_pin,low);
		_delay_ms(10);
		//low nipples
		M_DIO_clear_port_mask(lcd.LCD_port,0xF0);
		M_DIO_set_port_value_mask(lcd.LCD_port,(letter&0x0F)<<4);
		M_DIO_set_pin_value(lcd.LCD_enable_port,lcd.LCD_enable_pin,high);
		_delay_us(10);		   					   
		M_DIO_set_pin_value(lcd.LCD_enable_port,lcd.LCD_enable_pin,low);
	}
}
void H_LCD_dispaly_text( LCD_object lcd,char* string){
	for (int i = 0; string[i]!='\0'; i++)
	{
		if (string[i]!='\n')
		{
			H_LCD_dispaly_char(lcd,string[i]);
		}
		if (i==14)
		{
			H_LCD_send_command(lcd,0xC0);
		}
	}
	
	
}


void H_LCD_set_cursor_location( LCD_object lcd,u8 x, u8 y)
{
	if(x==1)
	{
		H_LCD_send_command(lcd,0x80+y);
	}
	else if (x==2)
	{
		H_LCD_send_command(lcd,0xC0+y);
	}
}



