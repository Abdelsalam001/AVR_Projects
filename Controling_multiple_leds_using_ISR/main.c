#define F_CPU 8000000UL
#include <util/delay.h>
#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MDIO_interface.h"
#include "MGIE_interface.h"
#include "MEXTI_interface.h"
void func1(void);
int main(void)
{

	MDIO_voidSetPinDirection(MDIO_PORTD,2,MDIO_INPUT_PULLUP);


	MDIO_voidSetPinDirection(MDIO_PORTB,0,MDIO_OUTPUT);
	MDIO_voidSetPinDirection(MDIO_PORTB,1,MDIO_OUTPUT);
	MDIO_voidSetPinDirection(MDIO_PORTB,2,MDIO_OUTPUT);
	MDIO_voidSetPinDirection(MDIO_PORTB,3,MDIO_OUTPUT);


MEXTI_voidInit(MEXTI_INT0,MEXTI_MODE_IOC);  //1---MODE & INTERRUPT


MEXTI_voidSetCallback(func1,MEXTI_INT0);   //2-- ISR FUNCTION CALL


MEXTI_voidEnableInterrupt(MEXTI_INT0);    //3---ENABLE INTERRUPT


MGIE_voidEnableGI();                     //4--GLOBAL ENABLE
	while(1)
	{

	}
	return 0;
}

void func1(void)
{
	static int i=0;

	switch(i)
	{

	case 1 : MDIO_voidSetPinValue(MDIO_PORTB,0,MDIO_TOGGLE);
	break;
	case 2 : MDIO_voidSetPinValue(MDIO_PORTB,1,MDIO_TOGGLE);
	break;
	case 3 : MDIO_voidSetPinValue(MDIO_PORTB,2,MDIO_TOGGLE);
	break;
	case 4 : MDIO_voidSetPinValue(MDIO_PORTB,3,MDIO_TOGGLE);
	break;
	default :
	break;
	}
	if(0==MDIO_voidGetPinValue(MDIO_PORTD,2))
	{
		i++;
	}
	if(i>4)
	{i=0;}

}


