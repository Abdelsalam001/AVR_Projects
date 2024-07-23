#define F_CPU 8000000UL
#include <util/delay.h>

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MDIO_interface.h"
#include "MADC_interface.h"
#include "MTIM_interface.h"

int main(void)
{
	u8 L_u8ADCValue = 0;
	u8 L_u8OCRValue = 0;

	MDIO_voidSetPinDirection(MDIO_PORTD,7,MDIO_OUTPUT);


	MDIO_voidSetPinDirection(MDIO_PORTB, 3, MDIO_OUTPUT);
	MADC_voidInit(MADC_VREF_AVCC, MADC_PRESCALER_8, MADC_RESOLUTION_8BITS);
	MTIM_voidInit(MTIM_TIMER0, MTIM_MODE_PHASECORRECTPWM, MTIM_CS_PRESCALER_256, MTIM_HWPIN_NONINVERTING_PWM);
	MTIM_voidStartTimer(MTIM_TIMER0);
	while(1)
	{

		MDIO_voidSetPinValue(MDIO_PORTD,7,MDIO_HIGH);


		L_u8ADCValue = MADC_u8ReadADC(MADC_CHANNEL_ADC0);
		L_u8OCRValue = (((f32)L_u8ADCValue*15)/255)+16;
		MTIM_voidSetOCR(MTIM_TIMER0, L_u8OCRValue);

	}
	 return 0;
}
