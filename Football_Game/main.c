
#define F_CPU 8000000UL
#include <util/delay.h>

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MDIO_interface.h"
#include "HLCD_interface.h"


void char1(void);
void char2(void);
void char3(void);
void char4(void);
void clear(void);
void goal(void);
void shap1(void);
void shap2(void);
char numChar[] ={'1','2','3','4','5'};
int humenChar1[] = {
  0b01110,
  0b01110,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010,
  0b10010
};
int humenChar2[] = {
  0b01110,
  0b01110,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010,
  0b10001
};

int ballChar[]  = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11000,
  0b11000
 };

int clearbit[]  = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
 };

int G[] = {
  0b11111,
  0b00101,
  0b11111,
  0b00101,
  0b11111,
  0B00101,
  0b11111,
  0b00101
};

int s[] = {
  0b10101,
  0b01010,
  0b10101,
  0b01010,
  0b00000,
  0b11111,
  0b01010,
  0b00100
};

int sad[] = {
  0b00000,
  0b00000,
  0b11011,
  0b01010,
  0b00000,
  0b01110,
  0b10001,
  0b00000
};

int keeper[] = {
  0b00000,
  0b00000,
  0b11000,
  0b11000,
  0b00100,
  0b11010,
  0b11011,
  0b00101
};
int main(void)
{
	int i,j;
	HLCD_voidInit();
	/************player**********/
	char2();
	HLCD_voidSetCursor(1,7);
	HLCD_voidWriteChar(1);
	/**************	Goal_keaper********/
	char2();
	HLCD_voidSetCursor(1,14);
	HLCD_voidWriteChar(1);
	/**************ball********/
	char3();
	HLCD_voidSetCursor(1,8);
	HLCD_voidWriteChar(2);
	/**************goal********/
	goal();
	HLCD_voidSetCursor(1,15);
	HLCD_voidWriteChar(4);
	/**************buttons********/
	MDIO_voidSetPinDirection(MDIO_PORTD,1,MDIO_INPUT_PULLUP);
	MDIO_voidSetPinDirection(MDIO_PORTD,0,MDIO_INPUT_PULLUP);
	u8 flag = 0;
	while(1)
	{
		if(flag == 0)
		{
			HLCD_voidClearScreen();
			/************player**********/
			char2();
			HLCD_voidSetCursor(1,7);
			HLCD_voidWriteChar(1);
			/**************	Goal_keaper********/
			char2();
			HLCD_voidSetCursor(1,14);
			HLCD_voidWriteChar(1);
			/**************ball********/
			char3();
			HLCD_voidSetCursor(1,8);
			HLCD_voidWriteChar(2);
			/**************goal********/
			goal();
			HLCD_voidSetCursor(1,15);
			HLCD_voidWriteChar(4);
			flag = 1;
		}
		if(0==MDIO_voidGetPinValue(MDIO_PORTD,1))
		{
			_delay_ms(50);
			char1();
			_delay_ms(250);
			char2();
			HLCD_voidSetCursor(1,7);
			HLCD_voidWriteChar(1);
			_delay_ms(70);
			for(j=9;j<=14;j++)
			{
				clear();
				HLCD_voidSetCursor(1,j-1);
				HLCD_voidWriteChar(3);
				char3();
				HLCD_voidSetCursor(1,j);
				HLCD_voidWriteChar(2);
				_delay_ms(170);
				if((j==14)&&(0==MDIO_voidGetPinValue(MDIO_PORTD,0)))
				{
					_delay_ms(10);
					char4();
					_delay_ms(1000);
					HLCD_voidClearScreen();
					HLCD_voidSetCursor(0, 4);
					HLCD_voidWriteString("missed");
					shap2();
					HLCD_voidSetCursor(0,10);
					HLCD_voidWriteChar(6);
					_delay_ms(2000);
					break;
				}
			}
			if(j<15)
			{
				flag = 0;
				continue;
			}
			_delay_ms(50);
			HLCD_voidClearScreen();
			HLCD_voidSetCursor(0, 4);
			HLCD_voidWriteString("goooaaal");
			for(i=0;i<10;i++)
			{
				shap1();
				HLCD_voidSetCursor(0,3);
				HLCD_voidWriteChar(5);
				_delay_ms(100);
				clear();
				HLCD_voidSetCursor(0,3);
				HLCD_voidWriteChar(3);
				HLCD_voidSetCursor(0,12);
				HLCD_voidWriteChar(5);
				_delay_ms(100);
				clear();
				HLCD_voidSetCursor(0,12);
				HLCD_voidWriteChar(3);
			}
			flag = 0;
		}

	}
return 0;
}
void char1(void)
{
	int i;
	HLCD_voidWriteCmd(0X40);
	for(i=0;i<8;i++)
	{
		 HLCD_voidWriteChar(humenChar1[i]);
	}
	HLCD_voidSetCursor(1,7);
	HLCD_voidWriteChar(0);
}
void char2(void)
{
	int i;
	 HLCD_voidWriteCmd(0X48);
	for(i=0;i<8;i++)
	{
		 HLCD_voidWriteChar(humenChar2[i]);
	}
}
void char3(void)
{
	int i;
	  HLCD_voidWriteCmd(0X50);
	for(i=0;i<8;i++)
	{
		 HLCD_voidWriteChar(ballChar[i]);
	}
}
void char4(void)
{
	int i;
	HLCD_voidWriteCmd(0X78);
	for(i=0;i<8;i++)
	{
		 HLCD_voidWriteChar(keeper[i]);
	}
	HLCD_voidSetCursor(1,14);
	HLCD_voidWriteChar(7);
}

void clear(void)
{
	int i;
	  HLCD_voidWriteCmd(0X58);
	for(i=0;i<8;i++)
	{
		 HLCD_voidWriteChar(clearbit[i]);
	}
}
void goal(void)
{
	int i;
	HLCD_voidWriteCmd(0X60);
	for(i=0;i<8;i++)
	{
		 HLCD_voidWriteChar(G[i]);
	}
	HLCD_voidSetCursor(1,15);
	HLCD_voidWriteChar(4);
}

void shap1(void)
{
	int i;
	HLCD_voidWriteCmd(0X68);
	for(i=0;i<8;i++)
	{
		 HLCD_voidWriteChar(s[i]);
	}

}

void shap2(void)
{
	int i;
	HLCD_voidWriteCmd(0X70);
	for(i=0;i<8;i++)
	{
		 HLCD_voidWriteChar(sad[i]);
	}

}


