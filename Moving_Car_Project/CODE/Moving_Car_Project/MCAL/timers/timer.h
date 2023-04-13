
#ifndef TIMER_H_
#define TIMER_H_

#include "../../SERVICE/STD_TYPES.h"
#include "../../SERVICE/UTILES.h"
#include "../MEMORYMAP.h"
#include "../EXI_INTERRUPT/EXI_INTERRUPT.h"



#define TIMR0_MAX_VALUE		256
#define TIMR2_MAX_VALUE		256

typedef enum {
	INVALID_PRESCALER,
	INVALID_MODE,
	INVALID_OVF,
	INVALID_VALUE,
	TIMER_OK
	}Timer_ErrorStatus;

typedef enum {
	NORMAL_MODE,
	FAST_PWM,
	CTC,
	PWM_PHASE_CORRECT
	
	}Timer_Mode;
	
typedef enum{
	PRECALER_1,
	PRECALER_8,
	PRECALER_64,
	PRECALER_32, // ONLY FOR TIMER_2
	PRECALER_128, // ONLY FOR TIMER_2
	PRECALER_256,
	PRECALER_1024,
	}Timer_Prescaler;


/********************************** TIMER_0_ ******************************************/
Timer_ErrorStatus TIMER_0_init(Timer_Mode mode);
Timer_ErrorStatus TIMER_0_start(Timer_Prescaler prescaler);
void TIMER_0_stop(void);
Timer_ErrorStatus TIMER_0_setIntialValue(double value);
Timer_ErrorStatus TIMER_0_OvfNum(double overflow);
void TIMER_0_DELAY_MS(double _delay);

void TIMER_0_pwm(float intial);
/********************************** TIMER_2_ ******************************************/
Timer_ErrorStatus TIMER_2_init(Timer_Mode mode);
Timer_ErrorStatus TIMER_2_start(Timer_Prescaler prescaler);
void TIMER_2_stop(void);
Timer_ErrorStatus TIMER_2_setIntialValue(uint8_t value);
Timer_ErrorStatus TIMER_2_OvfNum(double overflow);
void TIMER_2_DELAY_MS(double _delay);

void TIMER_2_INT();



extern uint8_t car_mode ;
extern  int mode_ovf ;

#endif /* TIMER_H_ */