/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************************************************************************************/
/********************************************************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include <util/delay.h>

void main(void)
{
	while(1)
	{
		DIO_u8SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT);
		DIO_u8SetPinDirection(DIO_PORTA, DIO_PIN1, DIO_PIN_OUTPUT);
		DIO_u8SetPinValue(DIO_PORTA, DIO_PIN0, DIO_PIN_HIGH);
		DIO_u8SetPinValue(DIO_PORTA, DIO_PIN1, DIO_PIN_HIGH);
		_delay_ms(1000);

		DIO_u8SetPinValue(DIO_PORTA, DIO_PIN0, DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA, DIO_PIN1, DIO_PIN_LOW);
		_delay_ms(1000);

		DIO_u8SetPortDirection(DIO_PORTA, DIO_PORT_OUTPUT);
		DIO_u8SetPortValue(DIO_PORTA, DIO_PORT_HIGH);
		_delay_ms(1000);

		DIO_u8SetPortValue(DIO_PORTA, DIO_PORT_LOW);
		_delay_ms(1000);
	}
}
