/************************************/
/* Author	 : Abdelsalam Mahmoud	*/
/* SWC		 : DIO					*/
/* Layer	 : MCAL					*/
/* Version	 : 1.1					*/
/* Date		 : September 9, 2023	*/
/* Last Edit : 15/9					*/
/************************************/

#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_

#define MDIO_PORTA	12 /*12,33,40,5 :magic number*/
#define MDIO_PORTB	33
#define MDIO_PORTC	40
#define MDIO_PORTD	5

#define MDIO_PORT_OUTPUT	0XFF
#define MDIO_PORT_INPUT		0X00

#define MDIO_OUTPUT			90	
#define MDIO_INPUT			100
#define MDIO_INPUT_PULLUP	200

#define MDIO_LOW 			0	
#define MDIO_HIGH			1
		
/*port access*/
void MDIO_voidSetPortDirection(u8 ARG_u8Port,u8 ARG_u8Directoin);
void MDIO_voidSetPortValue(u8 ARG_u8Port,u8 ARG_u8Value);
u8	 MDIO_voidGetPortValue(u8 ARG_u8Port);

/*Pin access*/
void MDIO_voidSetPinDirection(u8 ARG_u8Port,u8 ARG_u8Pin,u8 ARG_u8Directoin);
void MDIO_voidSetPinValue(u8 ARG_u8Port,u8 ARG_u8Pin,u8 ARG_u8Value);
u8	 MDIO_voidGetPinValue(u8 ARG_u8Port,u8 ARG_u8Pin);
#endif