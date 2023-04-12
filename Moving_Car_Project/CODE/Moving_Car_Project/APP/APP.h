
#ifndef app_H_
#define app_H_
#include "../MCAL/DIO/DIO.h"
#include "../HAL/button/BUTTON.h"
#include "../MCAL/EXI_INTERRUPT/EXI_INTERRUPT.h"
#include "../HAL/LED/LED.h"
#include "../HAL/MOTOR/MOTOR.h"
#include "../MCAL/TIMERS/timer.h"

void app_Start(void);
void app_Init(void);
void ready_State(void);

void pwm(float speed);
void shortSide_init();
void shortSide_start();
void longSide_init();
void longSide_start();
#endif