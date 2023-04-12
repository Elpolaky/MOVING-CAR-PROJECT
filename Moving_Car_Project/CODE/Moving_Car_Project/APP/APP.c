#include "APP.h"
float t;
float s;
float t2;

void pwm(float speed){
	 s= speed/100;
	 t=  (s * 256);
	 t2=256-t;
	TIMER_0_pwm(t);
	LED_ON(pinb0);
	
	TIMER_0_pwm(t2);
	LED_OFF(pinb0);
	
}



void shortSide_start()
{
	//mode_ovf= 7813 ;
	mode_ovf= 19532; // 5 seconds for simulation test
	LED_ON(pinc2);
	pwm(30);

}



void longSide_start()
{
	//mode_ovf= 11719; 
	// timee of stage / .000256
	mode_ovf= 19532;  // 5 seconds for simulation test
	Car_Moving_FWD();
	LED_ON(pinc1);
	pwm(50);
}

void ready_State(void){
	
		mode_ovf= 19532;  // 5 seconds for simulation test
		Car_Stop();
}

void app_Init(void){

	LED_INIT(pinb0);
	LED_INIT(pinc1);
	LED_INIT(pinc2);
	LED_INIT(pinb3);
	Car_Motors_init();

}

void app_Start(void){
	// delay after press start 
	if (car_mode == 0)
	{
		ready_State();
	}
	
	
	else if(car_mode == 1){

		longSide_start();
		
	}
	
	// rotation
	else if (car_mode == 2)
	{
		//mode_ovf= 1954 ;
		mode_ovf= 19532;  // 5 seconds for simulation test
		LED_OFF(pinc1);
		
	}
	
	else if (car_mode == 3)
	{
		shortSide_start();
		
	}
	
	// rotation
	else if(car_mode == 4){
		
		//mode_ovf= 1954 ;
		mode_ovf= 19532;  // 5 seconds for simulation test
		LED_OFF(pinc2);
		
	}
	
	
}

