/************************************/
/* Author	 : Abdelsalam Mahmoud	*/
/* SWC		 : LCD					*/
/* Layer	 : HAL					*/
/* Version	 : 1.0					*/
/* Date		 : October 5, 2023		*/
/* Last Edit : A/N					*/
/************************************/

#ifndef _HLCD_INTERFACE_H_
#define _HLCD_INTERFACE_H_

#define HLCD_DATA_PORT 	MDIO_PORTC
#define HLCD_CTRL_PORT 	MDIO_PORTD
#define HLCD_RS_PIN		5
#define HLCD_RW_PIN		6
#define HLCD_EN_PIN		7

void  HLCD_voidInit(void);
void  HLCD_voidWriteChar(const char ARG_ccharChar);
void  HLCD_voidWriteCmd(const u8 ARG_cu8Cmd);
void  HLCD_voidClearScreen(void);
void  HLCD_voidSetCursor(u8 ARG_u8Row, u8 ARG_u8Col);
void  HLCD_voidWriteString(const char* ARG_ccharpString);
void  HLCD_voidShifting(char ARG_charChar);
#endif
