/*
 * ADC.c
 *
 * Created: 4/14/2023 11:09:02 PM
 *  Author: husse
 */ 

#include "M_ADC.h"


void M_ADC_init(referance_type referance,ADC_adjust_type ADC_adjust,u8 ADC_prescaler){
	//reference
	clear_reg_mask(ADMUX,0b11000000);
	set_reg_mask(ADMUX,referance<<6);
	//adjustment
	if (ADC_adjust==right){clear_bit(ADMUX,5);} 
	else if(ADC_adjust==left){set_bit(ADMUX,5);}
	//prescaler and ADC enable
	clear_reg_mask(ADCSRA,0b00000111);
	set_reg_mask(ADCSRA,ADC_prescaler);
	set_bit(ADCSRA,7);
}

u16 M_ADC_read(u8 pin){
	//ACD pin selection
	clear_reg_mask(ADMUX,0b00011111);
	set_reg_mask(ADMUX,pin);
	//start conversion
	set_bit(ADCSRA,6);
	//waiting till ADC conversion  
	while (read_bit(ADCSRA,6));
	//return data
	if(read_bit(ADMUX,5)==1){return ADC>>6;}
	else if(read_bit(ADMUX,5)==0){return ADC;}
}