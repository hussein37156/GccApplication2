/*
 * UART.c
 *
 * Created: 6/10/2023 6:41:17 PM
 *  Author: husse
 */ 

#include "UART.h"

void M_UART_init(unsigned int baud ){
	UBRRH = (unsigned char)(baud>>8);
	UBRRL = (unsigned char)baud; 
	UCSRB = (1<<RXEN)|(1<<TXEN); 
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}

void M_UART_TX(char T_data){
	set_bit(UCSRA,TXC);
	UDR=T_data;
	while(read_bit(UCSRA,TXC)==0);
	
}

u8 M_UART_RX(void){
	while(!read_bit(UCSRA,RXC));
	clear_bit(UCSRA,RXC);
	return UDR;
}

void M_UART_RX_string(char *buffer) {
	unsigned char i = 0;
	//char data;
	do {
		buffer[i] = M_UART_RX();
		i++;
	} while (buffer[i-1] != '/' && i < sizeof(buffer)-1);
	buffer[i] = '\0';
}

void M_UART_TX_string(char *string){
	for (int i=0;string[i]!='\0';i++)
	{
		M_UART_TX(string[i]);
	}
	M_UART_TX(0x0a);
}

