/*
 * EVM.c
 *
 * Created: 3/4/2020 7:51:41 PM
 * Author : ASUS
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LCD_4bit_h_file.h"

uint8_t pressed=0,confirm=1,try=0;
int p=0,r=0,threshold=100,i=0,j=0,k=0,l=0;
int main(void)
{
	DDRC &= ~(1<<DDC0 | 1<<DDC1 | 1<<DDC2 | 1<<DDC3| 1<<DDC4| 1<<DDC5);
	PORTC |= 1<<PINC0| 1<<PINC1 | 1<<PINC2 | 1<<PINC3 | 1<<PINC4 | 1<<PINC5;
	DDRB &= ~(1<<DDB6| 1<<DDB7);
	DDRB |= 1<<DDB1;
	PORTB |= 1<<PINB6 | 1<<PINB7 | 1<< PINB1;
    LCD_Init();
	LCD_String_xy(0,0,"*****EVM is*****");
	LCD_String_xy(1,0,"****LOCKED!*****");	
    while (1) 
    {
		while(confirm)
		{
			if(bit_is_clear(PINB,7))
			{
				p++;
				if(p>threshold)
				{
					if(pressed ==0)
					{
						PORTB &= ~(1<<PINB1);
						LCD_Clear();
						LCD_String_xy(0,0,"-----EVM is-----");
						LCD_String_xy(1,0,"---UNLOCKED!----");
						_delay_ms(2000);
						LCD_Clear();
						LCD_String_xy(0,0,"A:");
						LCD_String_xy(0,8,"B:");
						LCD_String_xy(1,0,"C:");
						LCD_String_xy(1,8,"D:");
						confirm=0;
						break;
					}
					p=0;
				}
			}
			else
			{
				r++;
				if(r>threshold)
				{
					pressed=0;
					r=0;
				}
				
			}
		}
		
		if(bit_is_clear(PINC,0))//PINC & (1<<PC0) == 1
		{
			p++;
			if(p>threshold)
			{
				if(pressed ==0)
				{
// 					i++;
// 					LCD_Decimal_xy(0,3,i);
					pressed =4;
				}
				p=0;
			}
		}
		 else if(bit_is_clear(PINC,1))
		{
			p++;
			if(p>threshold)
			{
				if(pressed ==0)
				{
					//j++;
					//LCD_Decimal_xy(0,11,j);
					pressed =3;
				}
				p=0;
			}
		}
		else if(bit_is_clear(PINC,2))
		{
			p++;
			if(p>threshold)
			{
				if(pressed ==0)
				{
					//k++;
					//LCD_Decimal_xy(1,3,k);
					pressed =2;
				}
				p=0;
			}
		}
		else if(bit_is_clear(PINC,3))
		{
			p++;
			if(p>threshold)
			{
				if(pressed ==0)
				{
					//l++;
					//LCD_Decimal_xy(1,11,l);
					pressed =1;
				}
				p=0;
			}
		}
		else if(bit_is_clear(PINB,6))
		{
			p++;
			if(p>threshold)
			{
				if(pressed ==0)
				{
					LCD_Clear();
					LCD_String_xy(0,0," ### Voting ### ");
					LCD_String_xy(1,0," ### Finished ### ");
					_delay_ms(2000);
					LCD_Clear();
					LCD_String_xy(0,0,"A:");
					LCD_String_xy(0,8,"B:");
					LCD_String_xy(1,0,"C:");
					LCD_String_xy(1,8,"D:");
					LCD_Decimal_xy(0,3,i);
					LCD_Decimal_xy(0,11,j);
					LCD_Decimal_xy(1,3,k);
					LCD_Decimal_xy(1,11,l);			
					break;
					
				}
				p=0;
			}
		}
		else
		{
			r++;
			if(r>threshold)
			{
				pressed=0;
				r=0;
			}
			
		}
		
		
		if(pressed !=0 && pressed !=25 && pressed !=5)
		{
			LCD_Clear();
			switch(pressed)
			{
				case 1:
				LCD_String_xy(0,0,"Mr. A");
				LCD_String_xy(1,0,"Confirm? Yes/No");
				pressed=0;
				while(1)
				{
					if(bit_is_clear(PINC,5))
					{
						p++;
						if(p>threshold)
						{
							if(pressed ==0)
							{
								LCD_Clear();
								LCD_String_xy(0,0,"You voted for");
								LCD_String_xy(1,0,"Mr.A!!");
								pressed =25;
								i++;
								_delay_ms(2000);
								break;
							}
							p=0;
						}
					}
					else if(bit_is_clear(PINC,4))
					{
						p++;
						if(p>threshold)
						{
							if(pressed ==0)
							{
								LCD_Clear();
								LCD_String_xy(0,0,"Try again...");
								pressed =25;
								try =1;
								_delay_ms(2000);
								break;
							}
							p=0;
						}
					}
					else
					{
						r++;
						if(r>threshold)
						{
							pressed=0;
							r=0;
						}
						
					}
				}
				LCD_Clear();
				if(try)
				{
					LCD_String_xy(0,0,"A:");
					LCD_String_xy(0,8,"B:");
					LCD_String_xy(1,0,"C:");
					LCD_String_xy(1,8,"D:");
					try =0;
					break;
				}
				LCD_String_xy(0,0,"*****EVM is*****");
				LCD_String_xy(1,0,"****LOCKED!*****");
				PORTB |= 1<<PINB1;
				confirm =1;
				break;
				case 2:
				LCD_String_xy(0,0,"Voted for B!");
				LCD_String_xy(1,0,"Confirm? Yes/No");
				pressed=0;
				while(1)
				{
					if(bit_is_clear(PINC,5))
					{
						p++;
						if(p>threshold)
						{
							if(pressed ==0)
							{
								LCD_Clear();
								LCD_String_xy(0,0,"You voted for");
								LCD_String_xy(1,0,"Mr.B!!");
								pressed =25;
								j++;
								_delay_ms(2000);
								break;
							}
							p=0;
						}
					}
					else if(bit_is_clear(PINC,4))
					{
						p++;
						if(p>threshold)
						{
							if(pressed ==0)
							{
								LCD_Clear();
								LCD_String_xy(0,0,"Try again...");
								pressed =25;
								
								try=1;
								_delay_ms(2000);
								break;
							}
							p=0;
						}
					}
					else
					{
						r++;
						if(r>threshold)
						{
							pressed=0;
							r=0;
						}
						
					}
				}
				LCD_Clear();
				if(try)
				{
					LCD_String_xy(0,0,"A:");
					LCD_String_xy(0,8,"B:");
					LCD_String_xy(1,0,"C:");
					LCD_String_xy(1,8,"D:");
					try =0;
					break;
				}
				LCD_String_xy(0,0,"*****EVM is*****");
				LCD_String_xy(1,0,"****LOCKED!*****");
				PORTB |= 1<<PINB1;
				confirm=1;
				break;
				case 3:
				LCD_String_xy(0,0,"Voted for C");
				LCD_String_xy(1,0,"Confirm? Yes/No");
				pressed=0;
				while(1)
				{
					if(bit_is_clear(PINC,5))
					{
						p++;
						if(p>threshold)
						{
							if(pressed ==0)
							{
								LCD_Clear();
								LCD_String_xy(0,0,"You voted for");
								LCD_String_xy(1,0,"Mr.C!!");
								pressed =25;
								k++;
								_delay_ms(2000);
								break;
							}
							p=0;
						}
					}
					else if(bit_is_clear(PINC,4))
					{
						p++;
						if(p>threshold)
						{
							if(pressed ==0)
							{
								LCD_Clear();
								LCD_String_xy(0,0,"Try again...");
								pressed =25;
								try =1;
								_delay_ms(2000);
								break;
							}
							p=0;
						}
					}
					else
					{
						r++;
						if(r>threshold)
						{
							pressed=0;
							r=0;
						}
						
					}
				}
				LCD_Clear();
				if(try)
				{
					LCD_String_xy(0,0,"A:");
					LCD_String_xy(0,8,"B:");
					LCD_String_xy(1,0,"C:");
					LCD_String_xy(1,8,"D:");
					try =0;
					break;
				}
				LCD_String_xy(0,0,"*****EVM is*****");
				LCD_String_xy(1,0,"****LOCKED!*****");
				PORTB |= 1<<PINB1;
				confirm=1;
				break;
				case 4:
				LCD_String_xy(0,0,"Voted for D");
				LCD_String_xy(1,0,"Confirm? Yes/No");
				pressed=0;
				while(1)
				{
					if(bit_is_clear(PINC,5))
					{
						p++;
						if(p>threshold)
						{
							if(pressed ==0)
							{
								LCD_Clear();
								LCD_String_xy(0,0,"You voted for");
								LCD_String_xy(1,0,"Mr.D!!");
								pressed =25;
								l++;
								_delay_ms(2000);
								break;
							}
							p=0;
						}
					}
					else if(bit_is_clear(PINC,4))
					{
						p++;
						if(p>threshold)
						{
							if(pressed ==0)
							{
								LCD_Clear();
								LCD_String_xy(0,0,"Try again...");
								pressed =25;
								try =1;
								_delay_ms(2000);
								break;
							}
							p=0;
						}
					}
					else
					{
						r++;
						if(r>threshold)
						{
							pressed=0;
							r=0;
						}
										
					}
				}
				LCD_Clear();
				if(try)
				{
					LCD_String_xy(0,0,"A:");
					LCD_String_xy(0,8,"B:");
					LCD_String_xy(1,0,"C:");
					LCD_String_xy(1,8,"D:");
					try =0;
					break;
				}
				LCD_String_xy(0,0,"*****EVM is*****");
				LCD_String_xy(1,0,"****LOCKED!*****");
				PORTB |= 1<<PINB1;
				confirm=1;
				break;
				
			}
		}
		//pressed=0;
		
		
    }
}

