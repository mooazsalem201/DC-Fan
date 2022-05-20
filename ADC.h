/*
 * ADC.h
 *
 *  Created on: Aug 23, 2021
 *      Author: salem salem
 */

#ifndef ADC_H_
#define ADC_H_

#define ADC_ADMUX_CHANNEL_CLEAR_MASK  ~(0x1F)
#define ADC_ADMUX_CHANNEL_ADC0   0x00
#define ADC_ADMUX_CHANNEL_ADC1   0x01
#define ADC_ADMUX_CHANNEL_ADC2   0X02
#define ADC_ADMUX_CHANNEL_ADC3   0X03
#define ADC_ADMUX_CHANNEL_ADC4   0X04
#define ADC_ADMUX_CHANNEL_ADC5   0X05
#define ADC_ADMUX_CHANNEL_ADC6   0X06
#define ADC_ADMUX_CHANNEL_ADC7   0X07



extern void ADC_vidInit(void);


extern u16 ADC_Read(u8 channel);

#endif /* ADC_H_ */
