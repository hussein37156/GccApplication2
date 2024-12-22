/*
 * EEPROM.h
 *
 * Created: 7/14/2023 6:45:33 PM
 *  Author: husse
 */ 


#ifndef EEPROM_H_
	#define EEPROM_H_
	#include "../CPU_configuration.h"
	#include "avr/io.h"
	#include <util/delay.h>
	#include "../MCAL/I2C.h"

	void H_EEPROM_init(int SCL);
	void H_EEPROM_send(int EEPROM_page,int line,char data);
	char H_EEPROM_read(int EEPROM_page,int line);


#endif /* EEPROM_H_ */