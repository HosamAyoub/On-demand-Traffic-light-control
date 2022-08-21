/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "LIB/STD_TYPES.h"
#include "MCAL/TIMERS/TIMERS_interface.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE/GIE_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "ECUAL/LED/LED_interface.h"

void Int (void)
{
	LED_voidTurnOffGroupOfLEDS(9, 16);
	DIO_u8SetPortValue(DIO_PORTC, DIO_PORT_LOW);
	TIMERS_voidTimer0Delay(500, TIMERS_MS);
}

int main(void)
{
	LED_voidInitGroupOfLEDS(0, 7, DIO_PORTC, DIO_PIN0);
	LED_voidInitLED(8, DIO_PORTB, DIO_PIN5);

	DIO_u8SetPinDirection(DIO_PORTD, DIO_PIN0, DIO_PIN_INPUT);
	DIO_u8SetPinValue(DIO_PORTD, DIO_PIN0, DIO_PIN_HIGH);
	EXTI_voidInit();
	GIE_voidEnableGlobalInterrupt();
	EXTI_voidInt0SetCallBack(&Int);
	LED_voidInitGroupOfLEDS(9, 16, DIO_PORTB, DIO_PIN0);

	while(1)
	{
		LED_voidTurnOnLED(0);
		LED_voidTurnOnGroupOfLEDS(1, 8);
		TIMERS_voidTimer0Delay(500, TIMERS_MS);
		LED_voidTurnOffGroupOfLEDS(0, 8);
		TIMERS_voidTimer0Delay(500, TIMERS_MS);
	}
	return 0;
}
