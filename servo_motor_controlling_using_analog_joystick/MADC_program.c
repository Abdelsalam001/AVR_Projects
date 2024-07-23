/************************************/
/*	Author	  :	Omar Morsy			*/
/*	SWC		  : ADC					*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	November 3, 2023	*/
/*	Last Edit :	N/A					*/
/************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MADC_private.h"
#include "MADC_interface.h"

static void (*MADC_pvoidfUserFunction)(void) = NULL_POINTER;

void MADC_voidInit(u8 ARG_u8Vref, u8 ARG_u8Prescaler, u8 ARG_u8Resolution)
{
	if(((ARG_u8Vref<=1)||(3==ARG_u8Vref))&&(ARG_u8Prescaler<=7)&&(ARG_u8Resolution<=1))
	{
		ADMUX = (ADMUX&0x1F) | ((ARG_u8Vref<<REFS0) | (ARG_u8Resolution<<ADLAR));
		ADCSRA = (ADCSRA&0xF8) | ((1<<ADEN) | (ARG_u8Prescaler));
	}
	else
	{
		// Report an Error
	}
}

void MADC_voidEnableADC(void)
{
	SET_BIT(ADCSRA, ADEN);
}

void MADC_voidDisableADC(void)
{
	CLEAR_BIT(ADCSRA, ADEN);
}

void MADC_voidEnableInterrupt(void)
{
	SET_BIT(ADCSRA, ADIE);
}

void MADC_voidDisableInterrupt(void)
{
	CLEAR_BIT(ADCSRA, ADIE);
}

void MADC_voidSetCallback(void (*ARG_pvoidfUserFunction)(void))
{
	MADC_pvoidfUserFunction = ARG_pvoidfUserFunction;
}

u8	MADC_u8ReadADC(u8 ARG_u8Channel)
{
	MADC_voidStartConversion(ARG_u8Channel);
	MADC_voidFlagPolling();
	MADC_voidClearFlag();
	return ADCH;
}

u16	MADC_u16ReadADC(u8 ARG_u8Channel)
{
	MADC_voidStartConversion(ARG_u8Channel);
	MADC_voidFlagPolling();
	MADC_voidClearFlag();
	return ADC;
}

void MADC_voidStartConversion(u8 ARG_u8Channel)
{
	if(ARG_u8Channel<=31)
	{
		ADMUX = (ADMUX&0xE0) | (ARG_u8Channel);
		SET_BIT(ADCSRA, ADSC);
	}
	else
	{
		// Report an Error
	}
}

void MADC_voidFlagPolling(void)
{
	while(!GET_BIT(ADCSRA, ADIF));
}

void MADC_voidClearFlag(void)
{
	SET_BIT(ADCSRA, ADIF);
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	if(MADC_pvoidfUserFunction!=NULL_POINTER)
	{
		(*MADC_pvoidfUserFunction)();
	}
	else
	{
		// Do nothing
	}
}