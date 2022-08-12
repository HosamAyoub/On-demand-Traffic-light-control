/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: Application			*********************************/
/********************			SWC: Traffic light			*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "Application.h"

static u8 Global_u8YellowCarLEDState = 0;
void App_voidInit (void)
{
	//Initialize interrupt settings
	GIE_voidEnableGlobalInterrupt();
	EXTI_voidInit();
	DIO_u8SetPinDirection(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT);
	DIO_u8SetPinValue(DIO_PORTD, DIO_PIN2, DIO_PIN_HIGH);
	EXTI_voidInt0SetCallBack(&App_voidPedestrianMode);
	//Initialize Cars' LEDs
	LED_voidInitGroupOfLEDS(CAR_GREEN_LED, CAR_RED_LED, CAR_LED_PORT, CAR_LED_GREEN_PIN);
	//Initialize Pedestrians' LEDs
	LED_voidInitGroupOfLEDS(PEDESTRAIN_GREEN_LED, PEDESTRAIN_RED_LED, PEDESTRAIN_LED_PORT, PEDESTRAIN_LED_GREEN_PIN);
}

void App_voidStart (void)
{
	/*Normal mode*/
	//Car Green LED
	LED_voidTurnOnLED(CAR_GREEN_LED);
	TIMERS_voidTimer0Delay(LED_ON_TIME, TIMERS_S);
	LED_voidTurnOffLED(CAR_GREEN_LED);
	//Car Yellow LED
	for (u8 Local_u8Iterator = 0; Local_u8Iterator < LED_ON_TIME; Local_u8Iterator++)
	{
		Global_u8YellowCarLEDState = 1;
		LED_voidBlinkLED(CAR_YELLOW_LED, YELLOW_LED_BLINK_TIME, LED_MILLI_SECOND);
	}
	Global_u8YellowCarLEDState = 0;
	//Car Red LED
	LED_voidTurnOnLED(CAR_RED_LED);
	TIMERS_voidTimer0Delay(LED_ON_TIME, TIMERS_S);
	LED_voidTurnOffLED(CAR_RED_LED);
	//Car Yellow LED
	for (u8 Local_u8Iterator = 0; Local_u8Iterator < LED_ON_TIME; Local_u8Iterator++)
	{
		Global_u8YellowCarLEDState = 1;
		LED_voidBlinkLED(CAR_YELLOW_LED, YELLOW_LED_BLINK_TIME, LED_MILLI_SECOND);
	}
	Global_u8YellowCarLEDState = 0;
}

void App_voidPedestrianMode (void)
{
	/*Pedestrian Mode*/
	//variables for Cars' LEDs
	u8 Local_u8RedCarLEDState = 0, Local_u8GreenCarLEDState = 0;
	//check for Car Red LED
	DIO_u8GetPinValue(CAR_LED_PORT, CAR_LED_RED_PIN, &Local_u8RedCarLEDState);
	//check for Car Green and Yellow LEDs
	DIO_u8GetPinValue(CAR_LED_PORT, CAR_LED_GREEN_PIN, &Local_u8GreenCarLEDState);
	//The scenario if the red car LED was on
	if (Local_u8RedCarLEDState == 1)
	{
		LED_voidTurnOnLED(PEDESTRAIN_GREEN_LED);
		LED_voidTurnOnLED(CAR_RED_LED);
		TIMERS_voidTimer0Delay(LED_ON_TIME, TIMERS_S);
		LED_voidTurnOffLED(CAR_RED_LED);
	}
	//The scenario if the grenn or yellow car LED was on
	else if (Local_u8GreenCarLEDState == 1 || Global_u8YellowCarLEDState == 1)
	{
		if (Local_u8GreenCarLEDState == 1)
		{
			LED_voidTurnOnLED(PEDESTRAIN_RED_LED);
			TIMERS_voidTimer0Delay(LED_ON_TIME, TIMERS_S);
			LED_voidTurnOffLED(PEDESTRAIN_RED_LED);
			LED_voidTurnOffLED(CAR_GREEN_LED);
		}
		LED_voidTurnOffLED(PEDESTRAIN_YELLOW_LED);
		LED_voidTurnOffLED(CAR_YELLOW_LED);
		for (u8 Local_u8Iterator = 0; Local_u8Iterator < LED_ON_TIME * 2; Local_u8Iterator++)
		{
			Global_u8YellowCarLEDState = 1;
			LED_voidToggleLED(CAR_YELLOW_LED);
			LED_voidToggleLED(PEDESTRAIN_YELLOW_LED);
			TIMERS_voidTimer0Delay(YELLOW_LED_BLINK_TIME, TIMERS_MS);
		}
		Global_u8YellowCarLEDState = 0;
		//Time for the pedestrian cross
		LED_voidTurnOnLED(PEDESTRAIN_GREEN_LED);
		LED_voidTurnOnLED(CAR_RED_LED);
		TIMERS_voidTimer0Delay(LED_ON_TIME, TIMERS_S);
		LED_voidTurnOffLED(CAR_RED_LED);
	}
	LED_voidTurnOffLED(PEDESTRAIN_YELLOW_LED);
	LED_voidTurnOffLED(CAR_YELLOW_LED);
	for (u8 Local_u8Iterator = 0; Local_u8Iterator < LED_ON_TIME * 2; Local_u8Iterator++)
	{
		Global_u8YellowCarLEDState = 1;
		LED_voidToggleLED(CAR_YELLOW_LED);
		LED_voidToggleLED(PEDESTRAIN_YELLOW_LED);
		TIMERS_voidTimer0Delay(YELLOW_LED_BLINK_TIME, TIMERS_MS);
	}
	Global_u8YellowCarLEDState = 0;
	LED_voidTurnOffLED(PEDESTRAIN_GREEN_LED);
	//Back to normal state
	LED_voidTurnOnLED(PEDESTRAIN_RED_LED);
	LED_voidTurnOnLED(CAR_GREEN_LED);
}
