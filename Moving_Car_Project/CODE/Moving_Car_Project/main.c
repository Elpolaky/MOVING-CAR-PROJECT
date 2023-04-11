#include "MCAL/DIO/DIO.h"

#include "HAL/LED/LED.h"
#include "HAL/MOTOR/MOTOR.h"
#include "MCAL/TIMERS/timer.h"
int main(void)
{
	LED_INIT(pinc0);
	Car_Motors_init();
	//Car_Moving_FWD();
	//Car_Rotating();
    while (1) 
    {
		
		LED_ON(pinc0);
		TIMER_2_DELAY_MS(5000);
		LED_OFF(pinc0);
		TIMER_2_DELAY_MS(5000);

    }
}

