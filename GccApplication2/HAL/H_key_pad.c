
/*
 * key_pad.c
 *
 * Created: 4/14/2023 8:31:47 PM
 *  Author: husse
 */ 
#include "H_key_pad.h"
void H_key_pad_init(key_pad_object key){
	M_DIO_set_port_direction_mask(key.key_pad_port,output,0b00001111);
	M_DIO_set_port_direction_mask(key.key_pad_port,input,0b11110000);
	M_DIO_set_port_value(key.key_pad_port,0xFF);
}
char H_key_pad_read(key_pad_object key){
	volatile char x=0;	
	M_DIO_set_pin_value(key.key_pad_port,0,low);
			 if(M_DIO_read_pin_state(key.key_pad_port,4)==low){x='7';while(M_DIO_read_pin_state(key.key_pad_port,4)==low);}
		else if(M_DIO_read_pin_state(key.key_pad_port,5)==low){x='8';while(M_DIO_read_pin_state(key.key_pad_port,5)==low);}
		else if(M_DIO_read_pin_state(key.key_pad_port,6)==low){x='9';while(M_DIO_read_pin_state(key.key_pad_port,6)==low);}
		else if(M_DIO_read_pin_state(key.key_pad_port,7)==low){x='/';while(M_DIO_read_pin_state(key.key_pad_port,7)==low);}
		_delay_ms(10);
		
	M_DIO_set_pin_value(key.key_pad_port,0,high);
	
	M_DIO_set_pin_value(key.key_pad_port,1,low);																		
			 if(M_DIO_read_pin_state(key.key_pad_port,4)==low){x='4';while(M_DIO_read_pin_state(key.key_pad_port,4)==low);}
		else if(M_DIO_read_pin_state(key.key_pad_port,5)==low){x='5';while(M_DIO_read_pin_state(key.key_pad_port,5)==low);}
		else if(M_DIO_read_pin_state(key.key_pad_port,6)==low){x='6';while(M_DIO_read_pin_state(key.key_pad_port,6)==low);}
		else if(M_DIO_read_pin_state(key.key_pad_port,7)==low){x='*';while(M_DIO_read_pin_state(key.key_pad_port,7)==low);}
		_delay_ms(10);
	M_DIO_set_pin_value(key.key_pad_port,1,high);
	//_delay_ms(10);
	
	M_DIO_set_pin_value(key.key_pad_port,2,low);					
			 if(M_DIO_read_pin_state(key.key_pad_port,4)==low){x='1';while(M_DIO_read_pin_state(key.key_pad_port,4)==low);}
		else if(M_DIO_read_pin_state(key.key_pad_port,5)==low){x='2';while(M_DIO_read_pin_state(key.key_pad_port,5)==low);}
		else if(M_DIO_read_pin_state(key.key_pad_port,6)==low){x='3';while(M_DIO_read_pin_state(key.key_pad_port,6)==low);}
		else if(M_DIO_read_pin_state(key.key_pad_port,7)==low){x='-';while(M_DIO_read_pin_state(key.key_pad_port,7)==low);}
		_delay_ms(10);
	M_DIO_set_pin_value(key.key_pad_port,2,high);
	//_delay_ms(10);
	
	M_DIO_set_pin_value(key.key_pad_port,3,low);			
			 if(M_DIO_read_pin_state(key.key_pad_port,4)==low){x='c';while(M_DIO_read_pin_state(key.key_pad_port,4)==low);}
		else if(M_DIO_read_pin_state(key.key_pad_port,5)==low){x='0';while(M_DIO_read_pin_state(key.key_pad_port,5)==low);}
		else if(M_DIO_read_pin_state(key.key_pad_port,6)==low){x='=';while(M_DIO_read_pin_state(key.key_pad_port,6)==low);}
		else if(M_DIO_read_pin_state(key.key_pad_port,7)==low){x='+';while(M_DIO_read_pin_state(key.key_pad_port,7)==low);}
		_delay_ms(10);
	M_DIO_set_pin_value(key.key_pad_port,3,high);
	_delay_ms(10);
	
	return x;
			
}