/*
 * ADC_prog.c
 *
 *  Created on: Aug 23, 2021
 *      Author: salem salem
 */

#include"../LIB/STD_Types.h"
#include"../LIB/ATMEGA32_REGISTERS.h"
#include"../LIB/BIT_MATH.h"
#include"ADC.h"

void ADC_vidInit(void)
{
	//ADC Enable
	ADCSRA_REG.Bits.BIT_7 = 1;

	//Pre-scalar Configurations as 128
	ADCSRA_REG.Bits.BIT_0 = 1;
	ADCSRA_REG.Bits.BIT_1 = 1;
	ADCSRA_REG.Bits.BIT_2 = 1;

	//Reference voltage as AVCC with external capacitor
	ADMUX_REG.Bits.BIT_6 = 1;
	ADMUX_REG.Bits.BIT_7 = 0;

	//ADC Data Right Adjustment
	ADMUX_REG.Bits.BIT_5 = 0;


}

u16  ADC_Read(u8 channel)  //Read from ADC channel
{
	u16 Local_Result;

	//ADC channel Selection
	ADMUX_REG.Whole_Register &= ADC_ADMUX_CHANNEL_CLEAR_MASK;
	ADMUX_REG.Whole_Register |= channel;

	//Start Single Conversion
	ADCSRA_REG.Bits.BIT_6 = 1;

	//wait for conversion
	while((ADCSRA_REG.Bits.BIT_6));

	Local_Result = ADCL_REG.Whole_Register;
	Local_Result |= (((u16)ADCH_REG.Whole_Register)<<8);

	return Local_Result;


}
