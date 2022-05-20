/*
 * DCFANASS.c
 *
 *  Created on: Aug 24, 2021
 *      Author: salem salem
 */

#include"../LIB/STD_Types.h"
#include"../LIB/ATMEGA32_REGISTERS.h"
#include"../LIB/BIT_MATH.h"
#include"DIO_int.h"
#include"ADC.h"


int main(void)
{
	//Initializing our ADC
	ADC_vidInit();

	u16 ADC_result = 0;

	u16 Temp = 0;


	//Setting the ADC port to input
	DIO_vidSetPinDirection(u8PORTA,DIO_u8PIN_2,DIO_u8INPUT);

	//Setting the pin0 of port B to output and low
	DIO_vidSetPinDirection(u8PORTB,DIO_u8PIN_0,DIO_u8OUTPUT);
	DIO_vidSetPinVal(u8PORTB,DIO_u8PIN_0,DIO_u8LOW);

	//Setting portc direction as output
	DIO_vidSetPortDirection(u8PORTC,0b00000011);

	while(1)
	{
		//This allows us to read the digital signal of the sensor
		ADC_result = ADC_Read(ADC_ADMUX_CHANNEL_ADC2);
		//This helps us translate digital to analog
		ADC_result = (u16)(((u32)ADC_result*5000)/1024);

		//When we divide the result over 10 we will get the value in Celsius and store in Temp
		Temp = ADC_result/10;


		if(Temp <= 30)
		{
			//Set the direction of PORTC to input so that the fan stops
			DIO_vidSetPortDirection(u8PORTC,0b00000000);
		}
		else if( (Temp > 30) && (Temp <= 60) )
		{
			//Set the direction of PORTC to output to turn on the fan
			DIO_vidSetPortDirection(u8PORTC,0b00000011);

			//Making the fan tur clockwise
			DIO_vidSetPortVal(u8PORTC,0b00000001);

			//Incase the red light was on due to temperature turn it off
			DIO_vidSetPinVal(u8PORTB,DIO_u8PIN_0,DIO_u8LOW);
		}

		else
		{
			//Set the direction of PORTC to input so that the fan stops
			DIO_vidSetPortDirection(u8PORTC,0b00000000);

			//Turn the Red light on
			DIO_vidSetPinVal(u8PORTB,DIO_u8PIN_0,DIO_u8HIGH);

		}
	}



	return 0;

}
