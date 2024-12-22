/*
 * I2C.h
 *
 * Created: 7/10/2023 9:22:36 PM
 *  Author: husse
 */ 


#ifndef I2C_H_
	#define I2C_H_
	#define bit_rate(scl) ((F_CPU/scl)-16)/8
	#include <avr/io.h>
	#include "../UTIL/data_types.h"
	#include "../UTIL/macros.h"
	#include "../CPU_configuration.h"
	
	typedef enum
	{
		master,
		slave
	}I2C_configuration;
	
	typedef enum 
	{
		write,
		read
	}I2C_data_direction;
	
	typedef enum 
	{
		ack,
		nack
	}acknowlegment_type;
	
	void M_I2C_init(int SCL);
	u8 M_I2C_start(char address,I2C_data_direction direction);
	u8 M_I2C_send(char data);
	u8 M_I2C_receive(acknowlegment_type acknowlegment);
	void M_I2C_slave_address(char address);
	void M_I2C_stop(void);
	




#endif /* I2C_H_ */