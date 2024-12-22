/*
 * HX711.h
 *
 * Created: 07/04/2024 09:08:16 PM
 *  Author: husse
 */ 


#ifndef HX711_H_
	#define HX711_H_
	#include "../MCAL/I2C.h"
	void HX711_init();
	u8 HX711_read(char address);

#endif /* HX711_H_ */