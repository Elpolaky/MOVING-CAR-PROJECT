
#ifndef app_H_
#define app_H_
#include "../MCAL/DIO/DIO.h"
#include "../HAL/button/BUTTON.h"
#include "../MCAL/EXI_INTERRUPT/EXI_INTERRUPT.h"
#include "../HAL/LED/LED.h"
#include "../HAL/MOTOR/MOTOR.h"
#include "../MCAL/TIMERS/timer.h"



#define distance_between_wheels  200
#define wheel_diameter            67
#define max_speed                120
#define PI                   3.14159




void app_Start(void);
void app_Init(void);
void ready_State(void);

void pwm(float speed);
void shortSide_init();
void shortSide_start();
void longSide_init();
void longSide_start();


void car_stop_state (void);
void rotate_90degree_calculation (void);
void rotate_90degree_state (void);

#endif