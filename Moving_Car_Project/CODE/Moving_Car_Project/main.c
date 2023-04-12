#include "APP/APP.h"
//#define  F_CPU 8000000UL
int main(void)
{

		app_Init();
		TIMER_2_INT();

while(1){

		 app_Start();
  }
			
   
}

