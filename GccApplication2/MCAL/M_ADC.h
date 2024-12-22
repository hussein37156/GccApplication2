/*
 * ADC.h
 *
 * Created: 4/14/2023 11:09:25 PM
 *  Author: husse
 */ 


#ifndef ADC_H_
	#define ADC_H_
	#include <avr/io.h>
	#include "../UTIL/data_types.h"
	#include "../UTIL/macros.h"
	
	typedef enum 
	{
		AREF,
		AVCC,
		reseved, //valueless(it is used only to tune the orede in the enum)
		internal_reference
	}referance_type;
	
	typedef enum{
		left,
		right	
	}ADC_adjust_type;
	void M_ADC_init(referance_type referance,ADC_adjust_type ADC_adjust,u8 prescaler);
	u16 M_ADC_read(u8 pin);


#endif /* ADC_H_ */
