/*
 * TIMERS.c
 *
 * Created: 08/04/2023 07:44:43 ص
 *  Author: Genius
 */ 

#include "timer.h"
#include <math.h>

/************************* TIMER 0 *************************************/
Timer_ErrorStatus TIMER_0_init(Timer_Mode mode){
	Timer_ErrorStatus errorStatus = TIMER_OK;
	
	switch(mode){
		
		case NORMAL_MODE :
		clear_bit(TCCR0,WGM00);
		clear_bit(TCCR0,WGM01);
		break;
		
		case PWM_PHASE_CORRECT :
		set_bit(TCCR0,WGM00);
		clear_bit(TCCR0,WGM01);
		break;
		
		case CTC :
		clear_bit(TCCR0,WGM00);
		set_bit(TCCR0,WGM01);
		break;
		
		
		case FAST_PWM :
		set_bit(TCCR0,WGM00);
		set_bit(TCCR0,WGM01);
		break;
		
		default:
		errorStatus = INVALID_MODE ;
		break;
	}
	
	
	return errorStatus;
	
	
}
Timer_ErrorStatus TIMER_0_start(Timer_Prescaler prescaler){
	Timer_ErrorStatus errorStatus = TIMER_OK;
	
	switch(prescaler){
		
		case PRECALER_1 :
		set_bit(TCCR0,CS00);
		clear_bit(TCCR0,CS01);
		clear_bit(TCCR0,CS02);
		break;
		
		case PRECALER_8 :
		set_bit(TCCR0,CS01);
		clear_bit(TCCR0,CS00);
		clear_bit(TCCR0,CS02);
		break;
		
		case PRECALER_64 :
		set_bit(TCCR0,CS00);
		set_bit(TCCR0,CS01);
		clear_bit(TCCR0,CS02);
		break;
		
		case PRECALER_256 :
		set_bit(TCCR0,CS02);
		clear_bit(TCCR0,CS01);
		clear_bit(TCCR0,CS00);
		break;
		
		case PRECALER_1024 :
		set_bit(TCCR0,CS00);
		clear_bit(TCCR0,CS01);
		set_bit(TCCR0,CS02);
		break;
		
		default:
		errorStatus= INVALID_PRESCALER;
		break;
	}	
	
	return errorStatus ;
}
void TIMER_0_stop(void){
	
	clear_bit(TCCR0,CS00);
	clear_bit(TCCR0,CS01);
	clear_bit(TCCR0,CS02);
	
}


Timer_ErrorStatus TIMER_0_setIntialValue(double value){
	Timer_ErrorStatus errorStatus = TIMER_OK;

	if(value < TIMR0_MAX_VALUE && value >= 0){
		
		TCNT0 = ceil(value) ;
	}else{
		errorStatus = INVALID_VALUE;
	}
	return errorStatus ;
}


Timer_ErrorStatus TIMER_0_OvfNum(double overflow){
	Timer_ErrorStatus errorStatus = TIMER_OK;
	double num_ovf = 0;
	if (overflow > 0)
	{
		
		while(num_ovf<overflow){
			
			while(read_bit(TIFR,TOV0)==0);
			set_bit(TIFR,TOV0);
			num_ovf++;
		}
		num_ovf = 0;
	}else if (overflow <= 0)
	{
		overflow = 1 ;
		while(num_ovf<overflow){
			
			while(read_bit(TIFR,TOV0)==0);
			set_bit(TIFR,TOV0);
			num_ovf++;
		}
		num_ovf = 0;
	}
		
		else{
			errorStatus = INVALID_OVF;
		}
	
	return errorStatus;
}


/********************** TIMER_0_DELAY_MS ********************/
	double ovfNum  ;
	double t ;
void TIMER_0_DELAY_MS(double time_ms){
	 t = time_ms/1000 ;
	ovfNum = ceil (t / 0.000256) ;
	TIMER_0_init(NORMAL_MODE);
	TIMER_0_setIntialValue(0);
	TIMER_0_start(PRECALER_1);
	TIMER_0_OvfNum(ovfNum);
	
}

uint8_t setintial;
void TIMER_0_pwm(float intial){
	
	uint8_t timer = ceil(intial);
	clear_bit(TCCR0,WGM00);
	clear_bit(TCCR0,WGM01);
	
	TCNT0 =   timer ;     
	            
	set_bit(TCCR0,CS00);
	clear_bit(TCCR0,CS01);
	set_bit(TCCR0,CS02);
	
	while(read_bit(TIFR,TOV0)==0);
	TCCR0 = 0;
	TCNT0 =   0;    
	set_bit(TIFR,TOV0);
	
	
}



/************************************* TIMER2 ***********************************************/

Timer_ErrorStatus TIMER_2_init(Timer_Mode mode){
	Timer_ErrorStatus errorStatus = TIMER_OK;
	
	switch(mode){
		
		case NORMAL_MODE :
		clear_bit(TCCR2,WGM20);
		clear_bit(TCCR2,WGM21);
		break;
		
		case PWM_PHASE_CORRECT :
		set_bit(TCCR2,WGM20);
		clear_bit(TCCR2,WGM21);
		break;
		
		case CTC :
		clear_bit(TCCR2,WGM20);
		set_bit(TCCR2,WGM21);
		break;
		
		
		case FAST_PWM :
		set_bit(TCCR2,WGM20);
		set_bit(TCCR2,WGM21);
		break;
		
		default:
		errorStatus = INVALID_MODE ;
		break;
	}
	
	
	return errorStatus;
	
	
}



void TIMER_2_stop(void){
	
	clear_bit(TCCR2,CS20);
	clear_bit(TCCR2,CS21);
	clear_bit(TCCR2,CS22);
	
}



Timer_ErrorStatus TIMER_2_setIntialValue(uint8_t value){
	Timer_ErrorStatus errorStatus = TIMER_OK;

	if(value < TIMR2_MAX_VALUE && value >= 0){
		
		TCNT2 = value ;
		}else{
		errorStatus = INVALID_VALUE;
	}
	return errorStatus ;
}



Timer_ErrorStatus TIMER_2_start(Timer_Prescaler prescaler){
	Timer_ErrorStatus errorStatus = TIMER_OK;
	
	switch(prescaler){
		
		case PRECALER_1 :
		set_bit(TCCR2,CS20);
		clear_bit(TCCR2,CS21);
		clear_bit(TCCR2,CS22);
		break;
		
		case PRECALER_8 :
		set_bit(TCCR2,CS21);
		clear_bit(TCCR2,CS20);
		clear_bit(TCCR2,CS22);
		break;
		
		case PRECALER_32 :
		set_bit(TCCR2,CS20);
		set_bit(TCCR2,CS21);
		clear_bit(TCCR2,CS22);
		break;
		
		case PRECALER_64 :
		set_bit(TCCR2,CS22);
		clear_bit(TCCR2,CS21);
		clear_bit(TCCR2,CS20);
		break;
		
		case PRECALER_128 :
		set_bit(TCCR2,CS20);
		clear_bit(TCCR2,CS21);
		set_bit(TCCR2,CS22);
		break;
		
		case PRECALER_256 :
		set_bit(TCCR2,CS22);
		clear_bit(TCCR2,CS20);
		set_bit(TCCR2,CS21);
		break;
			
		case PRECALER_1024 :
		set_bit(TCCR2,CS20);
		set_bit(TCCR2,CS21);
		set_bit(TCCR2,CS22);
		break;
		
		
		default:
		errorStatus= INVALID_PRESCALER;
		break;
	}
	
	return errorStatus ;
}



Timer_ErrorStatus TIMER_2_OvfNum(double overflow){
	Timer_ErrorStatus errorStatus = TIMER_OK;
	double num_ovf = 0;
	if (overflow > 0)
	{
		
		while(num_ovf<overflow){
			
			while(read_bit(TIFR,TOV2)==0);
			set_bit(TIFR,TOV2);
			num_ovf++;
		}
		num_ovf = 0;
	}else if (overflow <= 0)
	{
		overflow = 1 ;
		while(num_ovf<overflow){
			
			while(read_bit(TIFR,TOV2)==0);
			set_bit(TIFR,TOV2);
			num_ovf++;
		}
		num_ovf = 0;
	}
	
	else{
		errorStatus = INVALID_OVF;
	}
	
	return errorStatus;
}



void TIMER_2_DELAY_MS(double time_ms){
	double ovfNum2  ;
	double t2 ;
	t2 = time_ms/1000 ;
	ovfNum2 = ceil (t2 / 0.000256) ;
	TIMER_2_init(NORMAL_MODE);
	TIMER_2_setIntialValue(0);
	TIMER_2_start(PRECALER_1);
	TIMER_2_OvfNum(ovfNum2);
	
}







void TIMER_2_INT(){
	sei();
	set_bit(TIMSK,TOIE2);
	TIMER_2_init(NORMAL_MODE);
	TIMER_2_setIntialValue(0);
	TIMER_2_start(PRECALER_1);
	
	
	
}



uint8_t car_mode = 0;
int mode_ovf = 0;
 int ovf = 0;

ISR(TIMER2_OVF){
	
	if (ovf < mode_ovf ){
		ovf++;
	}
	else if ( ovf == mode_ovf ){
		ovf =0 ;
	
		if (car_mode < 4)
		{
			car_mode++;
			
			}else{
			car_mode = 1 ;
		}
		
		}
		
	
	
}