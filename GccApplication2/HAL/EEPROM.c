/*
 * EEPROM.c
 *
 * Created: 7/14/2023 6:45:16 PM
 *  Author: husse
 */ 
#include "EEPROM.h"


void H_EEPROM_init(int SCL){
	M_I2C_init(SCL);
}

void H_EEPROM_send(int EEPROM_page,int line,char data){
	M_I2C_start((0b1010000|(EEPROM_page)),write);
	M_I2C_send(line);
	M_I2C_send(data);
	_delay_ms(100);
	M_I2C_stop();
}

char H_EEPROM_read(int EEPROM_page,int line){
	static char data;
	M_I2C_start((0b1010000|(EEPROM_page)),write);
	M_I2C_send(line);
	M_I2C_start((0b1010000|(EEPROM_page)),read);
	data=M_I2C_receive(ack);
	_delay_ms(100);
	M_I2C_stop();
	return data;
}

