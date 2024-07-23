/************************************/
/* Author	 : Abdelsalam Mahmoud	*/
/* SWC		 : DIO					*/
/* Layer	 : MCAL					*/
/* Version	 : 1.0					*/
/* Date		 : September 9, 2023	*/
/* Last Edit : N/A					*/
/************************************/

#ifndef _MDIO_PRIVATE_H_
#define _MDIO_PRIVATE_H_

typedef struct 
{
	const u8	PIN; /*const: (pin:read only)*/
	u8			DDR;
	u8			PORT;
}GPIO_t;

#define GPIOA	((volatile GPIO_t*)0x39)
#define GPIOB	((volatile GPIO_t*)0x36)
#define GPIOC	((volatile GPIO_t*)0x33)
#define GPIOD	((volatile GPIO_t*)0x30)

#endif