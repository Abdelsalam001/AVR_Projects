#define F_CPU 8000000UL
#include <util/delay.h>
#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MDIO_interface.h"
#include "MADC_interface.h"
#include "HLCD_interface.h"
#include <stdlib.h>
int main(void)
{

float x0;
float x1;
int a;
int b;
int c;
int y;
float z0;
float z1;
float z;

HLCD_voidInit();
HLCD_voidClearScreen();
HLCD_voidWriteString(" Current=");
while (1)
{
/**********************LCD***********************/
MADC_voidInit(MADC_VREF_AVCC, MADC_PRESCALER_32, MADC_RESOLUTION_8BITS);
x0= MADC_u8ReadADC(MADC_CHANNEL_ADC0);
z0=(x0*5/255);
x1= MADC_u8ReadADC(MADC_CHANNEL_ADC1);
z1=(x1*5/255);
z=1000*((z0-z1)/80);
y=z*10;
a=y/100;
HLCD_voidSetCursor(0,9);
HLCD_voidWriteChar(a + '0');
/**************************************/
y=y-(a*100);
b=y/10;
HLCD_voidSetCursor(0,10);
HLCD_voidWriteChar(b + '0');
/**************************************/
HLCD_voidSetCursor(0,11);
HLCD_voidWriteChar('.');
/**************************************/
y=y-(b*10);
c=y;
HLCD_voidSetCursor(0,12);
HLCD_voidWriteChar(c + '0');
/**************************************/
HLCD_voidSetCursor(0,13);
HLCD_voidWriteString("mA");
if(z>20)
{

	HLCD_voidSetCursor(0,9);
	HLCD_voidWriteString("    ");
}
}
return 0;
}
