/*
 * SPI.h
 *
 * Created: 7/7/2023 8:50:05 PM
 *  Author: husse
 */ 


#ifndef SPI_H_

	#define SPI_H_
	#include <avr/io.h>
	#include "..\UTIL\data_types.h"
	#include "..\UTIL\macros.h"
	
	typedef enum
	{
		master,
		slave
	}SPI_configuration;
	
	void M_SPI_init(SPI_configuration confivuration);
	void M_SPI_send_data(char data);
	char M_SPI_recive_data(void);
	





#endif /* SPI_H_ */