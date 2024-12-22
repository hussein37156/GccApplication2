/*
 * SPI.c
 *
 * Created: 7/7/2023 8:49:53 PM
 *  Author: husse
 */ 

#include "SPI.h"


void M_SPI_init(SPI_configuration configuration){
	set_bit(SPCR,6);
	if (configuration==master){
		set_bit(SPCR,4);
		set_bit(DDRB,4);
		set_bit(PORTB,4);
		set_bit(DDRB,5);
		clear_bit(DDRB,6);
		set_bit(DDRB,7);
	} 
	else if(configuration==slave){
		clear_bit(SPCR,4);
		clear_bit(DDRB,4);
		clear_bit(DDRB,5);
		set_bit(DDRB,6);
		clear_bit(DDRB,7);
	}
}

void M_SPI_send_data(char data){
	SPDR=data;
	while (read_bit(SPSR,7)==0);
}

char M_SPI_recive_data(void){
	SPDR=0xff;
	while (read_bit(SPSR,7)==0);
	return SPDR;
}

