/*
 * LCD.h
 *
 * Created: 4/15/2023 8:28:54 PM
 *  Author: husse
 */ 


#ifndef LCD_H_
	#define LCD_H_
	#include "../MCAL/M_DIO.h"
	#include "../CPU_configuration.h"
	#include <util/delay.h>
	typedef enum 
	{
		_8_bit,
		_4_bit
	}LCD_mode;
		
	typedef struct {
		LCD_mode mode;
		DIO_port_name LCD_port;
		DIO_port_name LCD_enable_port;
		int LCD_enable_pin;
		int LCD_RS_pin;
		int LCD_RW_pin;
	}LCD_object;

	void H_LCD_init( LCD_object lcd);
	void H_LCD_send_command( LCD_object lcd,u8 command);
	void H_LCD_dispaly_char( LCD_object lcd,u8 letter);
	void H_LCD_dispaly_text( LCD_object lcd,char* string);
	void H_LCD_set_cursor_location( LCD_object lcd,u8 x, u8 y);
	void H_LCD_clear( LCD_object lcd);
	
#endif /* LCD_H_ */