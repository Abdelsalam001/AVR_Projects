#define F_CPU 8000000UL
#include <util/delay.h>
/*library includes*/
#include "LSTD_types.h"
#include "LBIT_math.h"
/*MCAL includes*/
#include "MDIO_interface.h"

int main(void)
{
	s8 i, button1,button2,button3;
	for(i=0;i<=7;i++)
	{
		MDIO_voidSetPinDirection(MDIO_PORTA ,i,MDIO_OUTPUT);
	}
	for(i=0;i<=2;i++)
	{
		MDIO_voidSetPinDirection(MDIO_PORTB ,i,MDIO_INPUT_PULLUP);
	}
	while(1)
	{
		button1 =  	MDIO_voidSetPinValue(MDIO_PORTB ,0);
		button2 =  	MDIO_voidSetPinValue(MDIO_PORTB ,1);
		button3 =  	MDIO_voidSetPinValue(MDIO_PORTB ,2);
		if(0==button1)
		{
			for(i=0;i<=7;i++)
			{
				MDIO_voidSetPinValue(MDIO_PORTA ,i,MDIO_HIGH);
				_delay_ms(100);
				MDIO_voidSetPinValue(MDIO_PORTA ,i,MDIO_LOW);
			}
		}
		else if(0==button2)
		{
			for(i=7;i>=0;i--)
			{
				MDIO_voidSetPinValue(MDIO_PORTA ,i,MDIO_HIGH);
				_delay_ms(100);
				MDIO_voidSetPinValue(MDIO_PORTA ,i,MDIO_LOW);
			}
		}
		else if(0==button3)
		{
			for(i=0;i<=7;i++)
			{
				MDIO_voidSetPinValue(MDIO_PORTA ,i,MDIO_HIGH);
				_delay_ms(100);
				MDIO_voidSetPinValue(MDIO_PORTA ,i,MDIO_LOW);
			}
			for(i=7;i>=0;i--)
			{
				MDIO_voidSetPinValue(MDIO_PORTA ,i,MDIO_HIGH);
				_delay_ms(100);
				MDIO_voidSetPinValue(MDIO_PORTA ,i,MDIO_LOW);
			}
		}
		else
		{
			for(i=0;i<=7;i++)
			{
				MDIO_voidSetPinValue(MDIO_PORTA ,i,MDIO_LOW);
			}
		}
	}
}
