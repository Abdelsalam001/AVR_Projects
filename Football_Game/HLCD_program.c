/************************************/
/* Author	 : Abdelsalam Mahmoud	*/
/* SWC		 : LCD					*/
/* Layer	 : HAL					*/
/* Version	 : 1.0					*/
/* Date		 : October 5, 2023		*/
/* Last Edit : A/N					*/
/************************************/
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"
#include "HLCD_interface.h"

void  HLCD_voidInit(void)
{
MDIO_voidSetPortDirection(HLCD_DATA_PORT,0xff);
MDIO_voidSetPinDirection(HLCD_CTRL_PORT, HLCD_RS_PIN , MDIO_OUTPUT);
MDIO_voidSetPinDirection(HLCD_CTRL_PORT, HLCD_RW_PIN , MDIO_OUTPUT);
MDIO_voidSetPinDirection(HLCD_CTRL_PORT, HLCD_EN_PIN , MDIO_OUTPUT);
_delay_ms(30);
HLCD_voidWriteCmd(0x3f);
_delay_ms(50);
HLCD_voidWriteCmd(0x0C);
_delay_ms(50);
HLCD_voidClearScreen();
HLCD_voidWriteCmd(0x06);
_delay_ms(50);
}
void  HLCD_voidWriteChar(const char ARG_ccharChar)
{
MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RW_PIN , MDIO_LOW);
MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN , MDIO_HIGH);
MDIO_voidSetPortValue(HLCD_DATA_PORT, ARG_ccharChar);
MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN , MDIO_LOW);
MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN , MDIO_HIGH);
_delay_us(1);
MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN , MDIO_LOW);
_delay_us(1);
}
void  HLCD_voidWriteCmd(const u8 ARG_cu8Cmd)
{
MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RW_PIN , MDIO_LOW);
MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN , MDIO_LOW);
MDIO_voidSetPortValue(HLCD_DATA_PORT, ARG_cu8Cmd);
MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN , MDIO_LOW);
MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN , MDIO_HIGH);
_delay_us(1);
MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN , MDIO_LOW);
_delay_us(1);

}
void  HLCD_voidClearScreen(void)
{
	HLCD_voidWriteCmd(0X01);
	_delay_ms(2);
}
void HLCD_voidWriteString(const char* ARG_ccharpString)
{
u8 L_u8i = 0;

	do
	{
	HLCD_voidWriteChar(ARG_ccharpString [L_u8i]);
	L_u8i++;
	}while(ARG_ccharpString [L_u8i]!= '\0');
}

void HLCD_voidSetCursor(u8 ARG_u8Row, u8 ARG_u8Col)

{


	if((ARG_u8Row<=1)&&(ARG_u8Col<=15))
	{
		HLCD_voidWriteCmd((1<<7) | (ARG_u8Row<<6) | ARG_u8Col);
	}
	else
	{
		/* Report an Error */
	}
}
