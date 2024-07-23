#define F-CPU 8000000
#include <util/delay.h>

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MDIO_interface.h"

#define HLCD_DATA_PORT 	MDIO_PORTA
#define HLCD_CTRL_PORT 	MDIO_PORTB
#define HLCD_RS_PIN		0
#define HLCD_RW_PIN		1
#define HLCD_EN_PIN		2

void  HLCD_voidInit(void);
void  HLCD_voidWriteChar(const char ARG_ccharChar);
void  HLCD_voidWriteCmd(const u8 ARG_cu8Cmd);
void  HLCD_voidClearScreen(void);
void HLCD_voidWriteString(const char* ARG_ccharpString);
void HLCD_voidSetCursor(u8 ARG_u8Row, u8 ARG_u8Col);

u8 x[] = {
  0b00000,
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100
};
int main(void)
{
int i;

HLCD_voidInit();
HLCD_voidWriteString("Codex");
HLCD_voidSetCursor(1, 5);
HLCD_voidWriteString("Hello");
HLCD_voidWriteCmd(0x40);
for (i=0; i<11; i++)
{
HLCD_voidWriteChar(x[i]);

}
HLCD_voidSetCursor(1, 0);
HLCD_voidWriteChar(0);
while(1);

return 0;
}



void  HLCD_voidInit(void)
{
MDIO_voidSetPortDirection(HLCD_DATA_PORT,0xff);
MDIO_voidSetPinDirection(HLCD_CTRL_PORT, HLCD_RS_PIN , MDIO_OUTPUT);
MDIO_voidSetPinDirection(HLCD_CTRL_PORT, HLCD_RW_PIN , MDIO_OUTPUT);
MDIO_voidSetPinDirection(HLCD_CTRL_PORT, HLCD_EN_PIN , MDIO_OUTPUT);
_delay_ms(30);
HLCD_voidWriteCmd(0x3f);
_delay_ms(50);
HLCD_voidWriteCmd(0x0f);
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

