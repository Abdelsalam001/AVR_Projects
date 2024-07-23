/************************************/
/* Author	 : Abdelsalam Mahmoud	*/
/* SWC		 : Global Interrupt 	*/
/* Layer	 : MCAL					*/
/* Version	 : 1.0					*/
/* Date		 : October 21, 2023		*/
/* Last Edit : N/A					*/
/************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MGIE_private.h"
#include "MGIE_interface.h"

void MGIE_voidEnableGI(void)
{
	SET_BIT(SREG,I);
}
void MGIE_voidDisableGI(void)
{
	CLEAR_BIT(SREG,I);	
}
