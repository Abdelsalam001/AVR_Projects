#define F_CPU 8000000UL
#include <util/delay.h>
#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MDIO_interface.h"
#include "HLCD_interface.h"
#include "MGIE_interface.h"
#include "MEXTI_interface.h"
#include "MTIM_interface.h"
#include <stdlib.h>


 static volatile int pulse = 0;
static volatile int i = 0;
void func1(void);
int main(void)
{
	HLCD_voidInit();
  int count_a = 0;
  char show_a[16];
MDIO_voidSetPinDirection(MDIO_PORTB, 3, MDIO_OUTPUT);
MDIO_voidSetPinDirection(MDIO_PORTD,2,MDIO_INPUT);
MDIO_voidSetPinDirection(MDIO_PORTD,0,MDIO_OUTPUT);
MDIO_voidSetPinDirection(MDIO_PORTD,1,MDIO_OUTPUT);
  _delay_ms(50);
  MTIM_voidInit(MTIM_TIMER0, MTIM_MODE_PHASECORRECTPWM, MTIM_CS_PRESCALER_256, MTIM_HWPIN_NONINVERTING_PWM);
  MTIM_voidStartTimer(MTIM_TIMER0);
  MTIM_voidInit(MTIM_TIMER1, MTIM_MODE_NORMAL, MTIM_CS_PRESCALER_8, MTIM_HWPIN_DISCONNECTED);
  MEXTI_voidInit(MEXTI_INT0,MEXTI_MODE_IOC);  //1---MODE & INTERRUPT
  MEXTI_voidSetCallback(func1,MEXTI_INT0);   //2-- ISR FUNCTION CALL
  MEXTI_voidEnableInterrupt(MEXTI_INT0);    //3---ENABLE INTERRUPT
  MGIE_voidEnableGI();                     //4--GLOBAL ENABLE
  HLCD_voidClearScreen();
  while(1)
  {
    MDIO_voidSetPinValue(MDIO_PORTD,0,MDIO_HIGH);
    _delay_us(15);

    MDIO_voidSetPinValue(MDIO_PORTD,0,MDIO_LOW);
    count_a = pulse/58;

HLCD_voidSetCursor(0,0);
    HLCD_voidWriteString("Distance Sensor");
    HLCD_voidSetCursor(1,2);
    HLCD_voidWriteString("Distance=");
    itoa(count_a,show_a,10);
    HLCD_voidWriteString(show_a);
    HLCD_voidWriteString(" ");
    HLCD_voidSetCursor(1,13);
    HLCD_voidWriteString("cm");
    HLCD_voidSetCursor(1,1);
   if (count_a <=10)
     {
    	 MDIO_voidSetPinValue(MDIO_PORTD,1,MDIO_HIGH);/*buzzer*/
    	 MTIM_voidSetOCR(MTIM_TIMER0, 16); /*servo motor*/
     }
   else
   {
  	 MDIO_voidSetPinValue(MDIO_PORTD,1,MDIO_LOW); /*buzzer*/
  	MTIM_voidSetOCR(MTIM_TIMER0, 31);/*servo motor*/
   }
  }
}

void func1(void)

{
  if(i == 0)
  {
 MTIM_voidStartTimer(MTIM_TIMER1);
    i = 1;
  }
  else
  {
   MTIM_voidStopTimer(MTIM_TIMER1);
    pulse = MTIM_u16GetTimerValue(MTIM_TIMER1);
    MTIM_voidResetTimer(MTIM_TIMER1);
    i = 0;
  }
}
