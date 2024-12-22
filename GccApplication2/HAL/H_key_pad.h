/*
 * key_pad.h
 *
 * Created: 4/14/2023 8:32:06 PM
 *  Author: husse
 */ 


#ifndef KEY_PAD_H_
	#define KEY_PAD_H_
	#include "../MCAL/M_DIO.h"
	#include "../CPU_configuration.h"
	#include <util/delay.h>
	
	typedef struct{
		DIO_port_name key_pad_port;	
	}key_pad_object;
	
	void H_key_pad_init(key_pad_object key);
	char H_key_pad_read(key_pad_object key);




#endif /* KEY_PAD_H_ */