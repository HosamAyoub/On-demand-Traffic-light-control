/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: Application			*********************************/
/********************			SWC: Traffic light			*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef APPLICATION_H
#define APPLICATION_H

#define F_CPU 8000000UL
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMERS/TIMERS_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../ECUAL/LED/LED_interface.h"

void App_voidInit (void);
void App_voidStart (void);
void App_voidPedestrianMode (void);

//Cars' LEDs
#define CAR_LED_PORT						DIO_PORTA
#define CAR_LED_GREEN_PIN					DIO_PIN0
#define CAR_LED_YELLOW_PIN					DIO_PIN1
#define CAR_LED_RED_PIN						DIO_PIN2
#define CAR_GREEN_LED						0
#define CAR_YELLOW_LED						1
#define CAR_RED_LED							2

//Pedestrians' LEDs
#define PEDESTRAIN_LED_PORT					DIO_PORTB
#define PEDESTRAIN_LED_GREEN_PIN			DIO_PIN0
#define PEDESTRAIN_LED_YELLOW_PIN			DIO_PIN1
#define PEDESTRAIN_LED_RED_PIN				DIO_PIN2
#define PEDESTRAIN_GREEN_LED				3
#define PEDESTRAIN_YELLOW_LED				4
#define PEDESTRAIN_RED_LED					5

//Cars' LEDs Time
#define LED_ON_TIME							5
#define YELLOW_LED_BLINK_TIME				500



#endif
