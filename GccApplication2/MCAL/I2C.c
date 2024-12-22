/*
 * I2C.c
 *
 * Created: 7/10/2023 9:22:50 PM
 *  Author: husse
 */ 

#include "I2C.h"
void M_I2C_init(int SCL){
	TWBR=bit_rate(SCL);
}

u8 M_I2C_start(char address,I2C_data_direction direction){
	//start BUS
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while(read_bit(TWCR,TWINT)==0);			
	if((TWSR&0xF8)!=0x08 && (TWSR&0xF8)!=0x10){return 0;}	
			
	//send address
	TWDR=(address<<1)|direction;			
					
	TWCR=(1<<TWINT)|(1<<TWEN);			
	while(read_bit(TWCR,TWINT)==0);			
	if((TWSR&0xF8)==0x18){return 1;}			
	if((TWSR&0xF8)==0x20){return 2;}								
					 else{return 3;}
}																		
																		
																		
u8 M_I2C_send(char data){											
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(read_bit(TWCR,TWINT)==0);										
		 if((TWSR&0xF8)==0x28){return 0;}								
	else if((TWSR&0xF8)==0x30){return 1;}								
}

u8 M_I2C_receive(acknowlegment_type acknowlegment){
		 if(acknowlegment== ack){set_bit(TWCR,6);}
	else if(acknowlegment==nack){clear_bit(TWCR,6);}	
	TWCR=(1<<TWINT)|(1<<TWEN);														
	while(read_bit(TWCR,TWINT)==0);											
	return TWDR;
}

void M_I2C_slave_address(char address){
	TWAR=(address<<1);
}

void M_I2C_stop(void){
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);	
	while(read_bit(TWCR,TWSTO)!=0);
}
