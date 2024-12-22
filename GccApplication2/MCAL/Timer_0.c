/*
 * Timer_0.c
 *
 * Created: 6/23/2023 10:21:24 AM
 * Author: husse
 */ 
#include "Timer_0.h"

void M_Timer_0_init(wave_form_generator_mode generator_mode){
	if(generator_mode==CTC) {
		set_reg_mask(TCCR0,0x08);		//setting bit GWM01 to enable normal mode
		set_bit(TIMSK,1);				//setting bit TIOE0 to enabled overflow interrupt 
	}

	if (generator_mode==normal)
	{
		clear_reg_mask(TCCR0,0x08);		//clearing bit GWM01 to enable CTC mode
		set_bit(TIMSK,0);				//setting bit OCIE0 to enabled compare match interrupt 
	}
	sei();	
}


void M_Timer_0_start(u8 prescaler){
	set_reg_mask(TCCR0,prescaler);
}

void M_Timer_0_stop(void){
	clear_reg_mask(TCCR0,0x07);
	clear_reg_mask(TIMSK,0x03);			//peripheral interrupt disable
}

void M_Timer_0_reset(void){
	clear_reg(TCNT0);
}




u8 PWM_duty_cycle_array[max_PWM_pins];

void M_Timer_0_PWM_init(void){
	set_reg_value(OCR0,0);
	M_Timer_0_init(CTC);
	M_Timer_0_start(1);
	
}

void M_Timer_0_PWM(int pin,u8 PWM_duty_cycle){
	set_bit(DDRD,pin);
	PWM_duty_cycle_array[pin]=PWM_duty_cycle;
}

void M_Timer_0_PWM_schedular(){
	static  u8 PWM_duty_cycle_check=0;
	PWM_duty_cycle_check++;
	
	for (int i=0;i<max_PWM_pins;i++)
	{
		if (PWM_duty_cycle_array[i]!=0 &&(PWM_duty_cycle_array[i]==PWM_duty_cycle_check || PWM_duty_cycle_check==0))
		{
			toggle_bit(PORTD,i);
		}
	}
}



ISR(TIMER0_COMP_vect){
	M_Timer_0_PWM_schedular();
}











