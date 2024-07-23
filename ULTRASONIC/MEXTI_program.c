/************************************/
/* Author	 : Abdelsalam Mahmoud	*/
/* SWC		 : External Interrupt	*/
/* Layer	 : MCAL					*/
/* Version	 : 1.0					*/
/* Date		 : October 21, 2023		*/
/* Last Edit : N/A					*/
/************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MEXTI_private.h"
#include "MEXTI_interface.h"

static void (*MEXTI_pvoidfUserFunctionINT0)(void)= NULL_POINTER;
static void (*MEXTI_pvoidfUserFunctionINT1)(void)= NULL_POINTER;
static void (*MEXTI_pvoidfUserFunctionINT2)(void)= NULL_POINTER;

void MEXTI_voidInit(u8 ARG_u8InterruptNo, u8 ARG_u8InterruptMode)
{
	switch(ARG_u8InterruptNo)
	{
		case MEXTI_INT0:
		{
			switch(ARG_u8InterruptMode)
			{
			case MEXTI_MODE_LOW:
			{
				CLEAR_BIT(MCUCR,ISC01);
				CLEAR_BIT(MCUCR,ISC00);
				break;
			}
			case MEXTI_MODE_IOC:
			{
				CLEAR_BIT(MCUCR,ISC01);
				SET_BIT(MCUCR,ISC00);
				break;
			}
			case MEXTI_MODE_RISING:
			{
				SET_BIT(MCUCR,ISC01);
				SET_BIT(MCUCR,ISC00);
				break;				
			}
			case MEXTI_MODE_FALLING	:	
			{
				SET_BIT(MCUCR,ISC01);
				CLEAR_BIT(MCUCR,ISC00);
				break;
			}
				default :{/*report error*/break;}
			}
		break;
		}
		case MEXTI_INT1 :
		{
			switch(ARG_u8InterruptMode)
			{
				case MEXTI_MODE_LOW:
				{
					CLEAR_BIT(MCUCR,ISC11);
					CLEAR_BIT(MCUCR,ISC10);
					break;
				}
				case MEXTI_MODE_IOC:
				{
					CLEAR_BIT(MCUCR,ISC11);
					SET_BIT(MCUCR,ISC10);
					break;
				}
				case MEXTI_MODE_RISING:
				{
					SET_BIT(MCUCR,ISC11);
					SET_BIT(MCUCR,ISC10);
					break;
				}
				case MEXTI_MODE_FALLING	:
				{
					SET_BIT(MCUCR,ISC11);
					CLEAR_BIT(MCUCR,ISC10);
					break;
				}
				default :{/*report error*/break;}
			}
			break;
		}


		case MEXTI_INT2:
		{
			switch(ARG_u8InterruptMode)
			{

				case MEXTI_MODE_RISING:
				{
					SET_BIT(MCUCR,ISC2);
					break;
				}
				case MEXTI_MODE_FALLING	:
				{
					CLEAR_BIT(MCUCR,ISC2);
					break;
				}
				default :{/*report error*/break;}
			}
			break;
		}

		default :{break;}
	}
}
void MEXTI_voidEnableInterrupt(u8 ARG_u8InterruptNo)
{
	if(ARG_u8InterruptNo>=5 && ARG_u8InterruptNo<=7)
	{
		SET_BIT(GICR,ARG_u8InterruptNo);
	}
	else
	{
		//report error
	}	
}
void MEXTI_voidDisableInterrupt(u8 ARG_u8InterruptNo)
{
	if(ARG_u8InterruptNo>=5 && ARG_u8InterruptNo<=7)
	{
		CLEAR_BIT(GICR,ARG_u8InterruptNo);
	}
	else
	{
		//report error
	}
}

void MEXTI_voidSetCallback(void(*ARG_pvoidfUserFunction)(void),u8 ARG_u8InterruptNo)
{
		switch(ARG_u8InterruptNo)
	{
		case MEXTI_INT0: MEXTI_pvoidfUserFunctionINT0 = ARG_pvoidfUserFunction; break;
		case MEXTI_INT1: MEXTI_pvoidfUserFunctionINT1 = ARG_pvoidfUserFunction; break;
		case MEXTI_INT2: MEXTI_pvoidfUserFunctionINT2 = ARG_pvoidfUserFunction; break;
		default :/*report error*/ 		break;		

    }
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(MEXTI_pvoidfUserFunctionINT0 != NULL_POINTER)
	{	(*MEXTI_pvoidfUserFunctionINT0)();}
	else
	{	/*misra*/}
		
}
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(MEXTI_pvoidfUserFunctionINT1 != NULL_POINTER)
		{(*MEXTI_pvoidfUserFunctionINT1)();}
	else
	{/*misra*/}
		
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(MEXTI_pvoidfUserFunctionINT2 != NULL_POINTER)
	{	(*MEXTI_pvoidfUserFunctionINT2)();}
	else
	{	/*misra*/}

}

