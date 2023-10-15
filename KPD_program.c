#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "KPD_config.h"
#include "KPD_interface.h"


u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8Key=0;
	u8 Local_u8Row=0;
	u8 Local_u8Col=0;
	u8 Local_u8Reading;
	u8 arr[4][4]=
	{
			{1,2,3,'+'},
			{4,5,6,'-'},
			{7,8,9,'*'},
			{'/',0,'=','&'}
	};
	for(Local_u8Col=0;Local_u8Col<4;Local_u8Col++)
	{
		DIO_voidSetPinVal(KPD_PORT,Local_u8Col,PIN_VAL_LOW);
		for(Local_u8Row=0;Local_u8Row<4;Local_u8Row++)
		{

			if(DIO_u8GetPinVal(KPD_PORT,Local_u8Row+4)==PIN_VAL_LOW)
			{
				Local_u8Key=arr[Local_u8Row][Local_u8Col];
				_delay_ms(10);
				while(DIO_u8GetPinVal(KPD_PORT,Local_u8Row+4)==PIN_VAL_LOW)
				{
					asm("NOP");
				}
			}

	}
		DIO_voidSetPinVal(KPD_PORT,Local_u8Col,PIN_VAL_HIGH);
	}
return Local_u8Key;

}
