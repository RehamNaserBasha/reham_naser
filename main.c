#include  "BIT_MATH.h"
#include  "STD_TYPES.h"
#include <util/delay.h>
#include  "DIO_interface.h"
#include  "GIE_interface.h"
#include  "TIMER0_interface.h"
#include "Timer2_interface.h"
#include "CLCD_interface.h"

void led (void);
void seg (void);
u8 car[8]={
		 0x00,
		  0x00,
		  0x1F,
		  0x15,
		  0x1F,
		  0x11,
		  0x11,
		  0x00
};
u8 stop[8]=
{
		  0x00,
		  0x04,
		  0x1F,
		  0x0E,
		  0x04,
		  0x0E,
		  0x15,
		  0x00
};
u8 people[8]=
{
		  0x0E,
		  0x0E,
		  0x04,
		  0x0E,
		  0x15,
		  0x04,
		  0x0A,
		  0x0A

};

u8 SSD_arr [10]=
{
		0b11101111,     /*9*/
		0b11111111,     /*8*/
		0b11000111,     /*7*/
		0b11111101,     /*6*/
		0b11101101,     /*5*/
		0b11100110,     /*4*/
		0b11001111,     /*3*/
		0b11011011,     /*2*/
		0b10000110,     /*1*/
		0b10111111      /*0*/
};

void main (void)
{
//LED
	DIO_voidSetPinDir(PORTB_REG,PIN0,PIN_DIR_OUT);
	DIO_voidSetPinDir(PORTB_REG,PIN1,PIN_DIR_OUT);
	DIO_voidSetPinDir(PORTB_REG,PIN2,PIN_DIR_OUT);
	 //TIMER0
	    TIMER0_voidSetOCRValue(125);
	    TIMER0_voidInit();
	    //TIMER2
	    TIMER2_voidSetOCRValue(125);
	    TIMER2_voidInit();

    //CLCD
    DIO_voidSetPortDir(PORTA_REG,PORT_DIR_OUT);
    DIO_voidSetPortDir(PORTC_REG,PORT_DIR_OUT);
    CLCD_voidInit();
    //SSD
        DIO_voidSetPortDir(PORTD_REG,PORT_DIR_OUT);
        DIO_voidSetPortVal(PORTD_REG,PORT_VAL_HIGH);
    TIMER0_u8SetCallBack(led);
    TIMER2_u8SetCallBack(seg);
    GIE_VoidEnable();

    while (1)
    {

    }

}
void led (void)
{
	static u32 Local_u16counter=0;
	Local_u16counter++;

	if (Local_u16counter == 300)
	{
		CLCD_voidSendCommand(Clear);
		CLCD_voidSendString(" Car Can Go");
		CLCD_voidWriteSpecialCharacter(car,0,1,10);
		for (u8 i=0 ; i<8 ; i++)
		{
			CLCD_voidSendData(car[i]);
		}

		DIO_voidSetPinVal(PORTB_REG,PIN0,PIN_VAL_HIGH);
		DIO_voidSetPinVal(PORTB_REG,PIN1,PIN_VAL_LOW);
		DIO_voidSetPinVal(PORTB_REG,PIN2,PIN_VAL_LOW);
	}

	else if (Local_u16counter == 5300)
		{
			CLCD_voidSendCommand(Clear);
			CLCD_voidSendString("    ALL Stop");
			CLCD_voidWriteSpecialCharacter(stop,0,1,10);
			for (u8 j=0 ; j<8 ; j++)
			{
				CLCD_voidSendData(stop[j]);
			}

			DIO_voidSetPinVal(PORTB_REG,PIN0,PIN_VAL_LOW);
			DIO_voidSetPinVal(PORTB_REG,PIN1,PIN_VAL_HIGH);
			DIO_voidSetPinVal(PORTB_REG,PIN2,PIN_VAL_LOW);
		}
	else if (Local_u16counter == 7800)
		{
			CLCD_voidSendCommand(Clear);
			CLCD_voidSendString(" People Can GO");
			CLCD_voidWriteSpecialCharacter(people,0,1,10);
			for (u8 k=0 ; k<8 ; k++)
			{
				CLCD_voidSendData(people[k]);
			}
			DIO_voidSetPinVal(PORTB_REG,PIN0,PIN_VAL_LOW);
			DIO_voidSetPinVal(PORTB_REG,PIN1,PIN_VAL_LOW);
			DIO_voidSetPinVal(PORTB_REG,PIN2,PIN_VAL_HIGH);

		}
}
void seg (void)
{
	static u32 Local_u16counter2=0;
	Local_u16counter2++;
	if(Local_u16counter2==1000)
	{
		DIO_voidSetPortDir(PORTD_REG,SSD_arr[0]);
	}
	else if(Local_u16counter2==2000)
		{
			DIO_voidSetPortDir(PORTD_REG,SSD_arr[1]);
		}
	else if(Local_u16counter2==3000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[2]);
			}

	else if(Local_u16counter2==4000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[3]);
			}
	else if(Local_u16counter2==5000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[4]);
			}
	else if(Local_u16counter2==6000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[5]);
			}
	else if(Local_u16counter2==7000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[6]);
			}
	else if(Local_u16counter2==8000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[7]);
			}
	else if(Local_u16counter2==9000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[8]);
			}
	else if(Local_u16counter2==10000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[9]);
			}
	else if(Local_u16counter2==12000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[6]);
			}
	else if(Local_u16counter2==13000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[7]);
			}
	else if(Local_u16counter2==14000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[8]);
			}
	else if(Local_u16counter2==15000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[9]);
			}
	else if(Local_u16counter2==16000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[0]);
			}
	else if(Local_u16counter2==17000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[1]);
			}
	else if(Local_u16counter2==18000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[2]);
			}
	else if(Local_u16counter2==19000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[3]);
			}
	else if(Local_u16counter2==20000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[4]);
			}
	else if(Local_u16counter2==21000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[5]);
			}
	else if(Local_u16counter2==22000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[6]);
			}
	else if(Local_u16counter2==23000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[7]);
			}
	else if(Local_u16counter2==24000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[8]);
			}
	else if(Local_u16counter2==25000)
			{
				DIO_voidSetPortDir(PORTD_REG,SSD_arr[9]);
			}
	else if(Local_u16counter2==26000)
			{
		Local_u16counter2=0;
			}
}
