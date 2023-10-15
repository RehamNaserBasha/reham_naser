#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

void CLCD_voidSendData(u8 Copy_u8Data)
{
	//RS -> 1 SEND DATA
	DIO_voidSetPinVal(CTRL_PORT,RS,PIN_VAL_HIGH);
	//RW -> 0 SEND DATA
	DIO_voidSetPinVal(CTRL_PORT,RW,PIN_VAL_LOW);
	//SET COMMAND TO DATA PORT
	DIO_voidSetPortVal(DATA_PORT,Copy_u8Data);  // DATA
	DIO_voidSetPinVal(CTRL_PORT,E,PIN_VAL_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(CTRL_PORT,E,PIN_VAL_LOW);
}

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	//RS -> 0 SEND COMMAND
	DIO_voidSetPinVal(CTRL_PORT,RS,PIN_VAL_LOW);
	//RW -> 0 SEND COMMAND
	DIO_voidSetPinVal(CTRL_PORT,RW,PIN_VAL_LOW);
	//SET COMMAND TO DATA PORT
	DIO_voidSetPortVal(DATA_PORT,Copy_u8Command);

	DIO_voidSetPinVal(CTRL_PORT,E,PIN_VAL_HIGH);  //FALLING EDGE
	_delay_ms(1);
	DIO_voidSetPinVal(CTRL_PORT,E,PIN_VAL_LOW);
}

void CLCD_voidInit(void)    //CLCD ON 8 BITS
{
	_delay_ms(40);
	CLCD_voidSendCommand(0b00111000);
	_delay_ms(1);
	CLCD_voidSendCommand(0b00001100);
	_delay_ms(1);
	CLCD_voidSendCommand(0b00000001);
	_delay_ms(2);
}
void CLCD_voidSendString(char* Copy_PvString)
{

	u8 i=0;
	while(Copy_PvString[i]!='\0') // Copy_PvString[i]!=NULL
	{
		CLCD_voidSendData(Copy_PvString[i]);
		i++;
	}
}
void CLCD_voidSendNum(u16 Copy_u16Num){
	u8 i =0;
	u8 j=0;
	u8 arr[10];
	if (Copy_u16Num==0)
	{
		CLCD_voidSendData('0');
	}
	else
	{
		do
		{
			arr[i] =Copy_u16Num%10 +'0';
					Copy_u16Num/=10;
					i++;
		}
		while(Copy_u16Num);
	}
	for(j=i;j>0;j--)
	{
		CLCD_voidSendData(arr[j-1]);
	}
}
void CLCD_voidSendPos(u8 Copy_u8X,u8 Copy_u8Y)
{

	u8 Local_u8Pos;
	if(Copy_u8X==0)   //first row
	{
		Local_u8Pos=Copy_u8Y;
	}
	else if (Copy_u8X==1)

	{
		Local_u8Pos=Copy_u8Y+0x40; //second row
	}
	CLCD_voidSendCommand(Local_u8Pos+128);
}
void CLCD_voidWriteSpecialCharacter(u8 *Copy_Pattern,u8 Copy_u8Loc,u8 Copy_u8X,u8 Copy_u8Y){

	u8 Local_u8CGRAMAdress,Local_u8Iterator=0;

	Local_u8CGRAMAdress=Copy_u8Loc*8; // address  8 indicate no of LOC IN CGRAM
	CLCD_voidSendCommand(Local_u8CGRAMAdress+64);  //data in CGRAM ->ACESS AC
   for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++) //STORE in CGRAM
   {
	   CLCD_voidSendData(Copy_Pattern[Local_u8Iterator]);
   }
   CLCD_voidSendPos( Copy_u8X, Copy_u8Y); // DDRAM
   CLCD_voidSendData(Copy_u8Loc); // Display
}
