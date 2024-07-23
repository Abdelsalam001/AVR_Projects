/************************************/
/*	Author	  :	Omar Morsy			*/
/*	SWC		  : ADC					*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	November 3, 2023	*/
/*	Last Edit :	N/A					*/
/************************************/

#ifndef _MADC_INTERFACE_H_
#define _MADC_INTERFACE_H_

#define MADC_VREF_AREF			0
#define MADC_VREF_AVCC			1
#define MADC_VREF_2_56V			3

#define MADC_RESOLUTION_8BITS	1
#define MADC_RESOLUTION_10BITS	0

#define MADC_PRESCALER_2		1
#define MADC_PRESCALER_4		2
#define MADC_PRESCALER_8		3
#define MADC_PRESCALER_16		4
#define MADC_PRESCALER_32		5
#define MADC_PRESCALER_64		6
#define MADC_PRESCALER_128		7

#define MADC_CHANNEL_ADC0		0
#define MADC_CHANNEL_ADC1		1
#define MADC_CHANNEL_ADC2		2
#define MADC_CHANNEL_ADC3		3
#define MADC_CHANNEL_ADC4		4
#define MADC_CHANNEL_ADC5		5
#define MADC_CHANNEL_ADC6		6
#define MADC_CHANNEL_ADC7		7
#define MADC_CHANNEL_1_22V		30
#define MADC_CHANNEL_GND		31

void MADC_voidInit(u8 ARG_u8Vref, u8 ARG_u8Prescaler, u8 ARG_u8Resolution);

void MADC_voidEnableADC(void);
void MADC_voidDisableADC(void);

void MADC_voidEnableInterrupt(void);
void MADC_voidDisableInterrupt(void);
void MADC_voidSetCallback(void (*ARG_pvoidfUserFunction)(void));

u8	MADC_u8ReadADC(u8 ARG_u8Channel);
u16	MADC_u16ReadADC(u8 ARG_u8Channel);

void MADC_voidStartConversion(u8 ARG_u8Channel);
void MADC_voidFlagPolling(void);
void MADC_voidClearFlag(void);

#endif