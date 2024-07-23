#define F_CPU 8000000UL
#include <util/delay.h>

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MDIO_interface.h"


int main(void)

{
	MDIO_voidSetPinDirection(MDIO_PORTD,0,MDIO_INPUT_PULLUP);
	MDIO_voidSetPinDirection(MDIO_PORTD,1,MDIO_INPUT_PULLUP);

	MDIO_voidSetPinDirection(MDIO_PORTD,2,MDIO_OUTPUT);
	MDIO_voidSetPinDirection(MDIO_PORTD,3,MDIO_OUTPUT);
	MDIO_voidSetPinDirection(MDIO_PORTD,4,MDIO_OUTPUT);
	MDIO_voidSetPinDirection(MDIO_PORTD,5,MDIO_OUTPUT);

	while(1)
	{
		if((0==MDIO_voidGetPinValue(MDIO_PORTD,0)) && (1==MDIO_voidGetPinValue(MDIO_PORTD,1)))
		{
			MDIO_voidSetPinValue(MDIO_PORTD,2,MDIO_LOW);
			MDIO_voidSetPinValue(MDIO_PORTD,4,MDIO_LOW);
			MDIO_voidSetPinValue(MDIO_PORTD,3,MDIO_HIGH);
			MDIO_voidSetPinValue(MDIO_PORTD,5,MDIO_HIGH);
		}

		else if((0==MDIO_voidGetPinValue(MDIO_PORTD,1)) && (1==MDIO_voidGetPinValue(MDIO_PORTD,0)))
		{
			MDIO_voidSetPinValue(MDIO_PORTD,3,MDIO_LOW);
			MDIO_voidSetPinValue(MDIO_PORTD,5,MDIO_LOW);
			MDIO_voidSetPinValue(MDIO_PORTD,2,MDIO_HIGH);
			MDIO_voidSetPinValue(MDIO_PORTD,4,MDIO_HIGH);
		}
		else
		{
			MDIO_voidSetPinValue(MDIO_PORTD,3,MDIO_LOW);
			MDIO_voidSetPinValue(MDIO_PORTD,5,MDIO_LOW);
			MDIO_voidSetPinValue(MDIO_PORTD,2,MDIO_LOW);
			MDIO_voidSetPinValue(MDIO_PORTD,4,MDIO_LOW);
		}
	}




return 0;
}
