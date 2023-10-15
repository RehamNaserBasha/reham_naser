#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include <util/delay.h>
#include "CALC_config.h"
#include "CALC_private.h"
#include "CALC_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
    u16 Copy_FirstNum;
	u16 Copy_SecondNum;
	u8 Copy_Operation;
	u8 Key,Flag;
	f32 Local_Result;

void CALC_voidInit(void)
{
	     CLCD_voidInit();
		_delay_ms(5);
		CLCD_voidSendString("Welcome to ");
		CLCD_voidSendPos(1,0);
		CLCD_voidSendString("Calculator");
		_delay_ms(1000);
		CLCD_voidInit();
}
void CALC_voidCalculation(void)
{
		Key=KPD_u8GetPressedKey();
	if((Key!=ADD || Key!=SUB|| Key!=MUL ||Key!=DIV || Key!=EQL || Key!=CLC) &&Flag==0)
	{
		switch(Key)
		{
		case one:Copy_FirstNum=1;CLCD_voidSendNum(1);Flag=1;break;
		case two:Copy_FirstNum=2;CLCD_voidSendNum(2);Flag=1;break;
		case three:Copy_FirstNum=3;CLCD_voidSendNum(3);Flag=1;break;
		case four:Copy_FirstNum=4;CLCD_voidSendNum(4);Flag=1;break;
		case five:Copy_FirstNum=5;CLCD_voidSendNum(5);Flag=1;break;
		case six:Copy_FirstNum=6;CLCD_voidSendNum(6);Flag=1;break;
		case seven:Copy_FirstNum=7;CLCD_voidSendNum(7);Flag=1;break;
		case eight:Copy_FirstNum=8;CLCD_voidSendNum(8);Flag=1;break;
		case nine:Copy_FirstNum=9;CLCD_voidSendNum(9);Flag=1;break;
		case zero:Copy_FirstNum=0;CLCD_voidSendNum(0);Flag=1;break;
		}
	}
	if(Key==ADD || Key==SUB|| Key==MUL ||Key==DIV  )
	{
		switch(Key)
		{
		case one:Copy_Operation=ADD;CLCD_voidSendData('+');Flag=3;break;
		case two:Copy_Operation=SUB;CLCD_voidSendData('-');Flag=3;break;
		case three:Copy_Operation=MUL;CLCD_voidSendData('*');Flag=3;break;
		case four:Copy_Operation=DIV;CLCD_voidSendData('/');Flag=3;break;
		}
	}
	if((Key!=ADD || Key!=SUB|| Key!=MUL ||Key!=DIV || Key!=EQL || Key!=CLC ) &&Flag==3)
		{
			switch(Key)
			{
			case one:Copy_SecondNum=1;CLCD_voidSendNum(1);Flag=2;break;
			case two:Copy_SecondNum=2;CLCD_voidSendNum(2);Flag=2;break;
			case three:Copy_SecondNum=3;CLCD_voidSendNum(3);Flag=2;break;
			case four:Copy_SecondNum=4;CLCD_voidSendNum(4);Flag=2;break;
			case five:Copy_SecondNum=5;CLCD_voidSendNum(5);Flag=2;break;
			case six:Copy_SecondNum=6;CLCD_voidSendNum(6);Flag=2;break;
			case seven:Copy_SecondNum=7;CLCD_voidSendNum(7);Flag=2;break;
			case eight:Copy_SecondNum=8;CLCD_voidSendNum(8);Flag=2;break;
			case nine:Copy_SecondNum=9;CLCD_voidSendNum(9);Flag=2;break;
			case zero:Copy_SecondNum=0;CLCD_voidSendNum(0);Flag=2;break;
			}
		}
	if(Key==EQL)
	{
		CLCD_voidSendData('=');

  switch (Copy_Operation)
  {
  case ADD :
	  Local_Result=Copy_FirstNum+Copy_SecondNum;
	  CLCD_voidSendNum(Local_Result);
	  break;
  case SUB:
	  if(Copy_FirstNum > Copy_SecondNum)
	  {
		  Local_Result= Copy_FirstNum-Copy_SecondNum;
	  }
	  else
	  {
		  Local_Result=Copy_SecondNum-Copy_FirstNum;
		 CLCD_voidSendData('-');
	  }
	  CLCD_voidSendNum(Local_Result);
	  break;
  case MUL:
	  Local_Result=Copy_FirstNum*Copy_SecondNum;
	  CLCD_voidSendNum(Local_Result);
	  break;

  case DIV:
	 if(Copy_SecondNum !=0)
	 {
		 Local_Result= Copy_FirstNum/Copy_SecondNum;
		 CLCD_voidSendNum(Local_Result);
	 }
	 else
	 {
		CLCD_voidSendString("ERROR");
     }
    break;
  }
}
    if (Key== CLC)
    {
         CLCD_voidInit();
    	Copy_FirstNum=0;
    	Copy_Operation=0;
    	Copy_FirstNum=0;
    	Flag=0;
    }

}


