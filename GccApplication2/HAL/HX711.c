/*
 * HX711.c
 *
 * Created: 07/04/2024 09:08:32 PM
 *  Author: husse
 */ 


#include "HX711.h"
void HX711_init(){
	M_I2C_init(8000);
}


u8 HX711_read(char address){
	static u8 x=0;
	M_I2C_start(address,read);
	x=M_I2C_receive(nack);		
	M_I2C_stop();
	return x;
}