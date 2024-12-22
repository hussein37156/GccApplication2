/*
 * UART.h
 *
 * Created: 6/10/2023 6:41:33 PM
 *  Author: husse
 */ 


#ifndef UART_H_
	#include "../CPU_configuration.h"
	#define UART_H_
	#include <avr/io.h>
	#include <util/delay.h>
	#include "../UTIL/macros.h"
	#include "../UTIL/data_types.h"
	
	void M_UART_init(unsigned int baud);
	void M_UART_TX(char T_data);
	u8 M_UART_RX(void);
	void M_UART_RX_string(char *buffer);
	void M_UART_TX_string(char *string);
#endif /* UART_H_ */