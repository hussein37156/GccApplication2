/*
 * EEPROM.c
 *
 * Created: 7/14/2023 6:49:50 PM
 * Author : Hussein
*/

#include "MCAL/Timer_0.h"
#include "MCAL/M_DIO.h"
#include "HAL/H_7_segments.h"
_7_segment_object object_1={A,comon_cathode_decoder,up};

int main(void){
	M_Timer_0_init(normal);
	
	H_7_segment_init(object_1);
	M_Timer_0_start(0b101);
	M_DIO_set_pin_direction(A,6,output);
	M_DIO_set_pin_direction(A,5,output);
	M_DIO_set_pin_direction(A,4,output);
	M_DIO_set_pin_value(A,6,low);
	M_DIO_set_pin_value(A,4,low);
	M_DIO_set_pin_value(A,4,low);
	
	while (1)
	{
		
	}
}

ISR(TIMER0_OVF_vect){
	static int i=0;
	static int counter=0;
	i++;
	counter=i*0.25;
	H_7_segment_clear(object_1);
	if (counter<10 & counter>=0){
		H_7_segment_display(object_1,counter);
		M_DIO_set_pin_value(A,6,high);
		M_DIO_set_pin_value(A,5,low);
		M_DIO_set_pin_value(A,4,low);
		
	}
	else if(counter<=13 && counter>10){
		H_7_segment_display(object_1,counter-10);
		M_DIO_set_pin_value(A,6,low);
		M_DIO_set_pin_value(A,5,high);
		M_DIO_set_pin_value(A,4,low);
	}
	else if(counter>13){
		H_7_segment_display(object_1,counter-13);
		M_DIO_set_pin_value(A,6,low);
		M_DIO_set_pin_value(A,5,low);
		M_DIO_set_pin_value(A,4,high);
		if (counter>22)i=0;
	}
	
	
}


