/*
 * GPIOA.h
 *
 *  Created on: Nov 16, 2023
 *      Author: MR.ROBOT
 */

#ifndef GPIO_H_
#define GPIO_H_
#include "STD_TYPES.h"
#define GPIOA_BASE 0x40010800
#define GPIOA_CRL_uint32_REG 	*((volatile uint32 *)(GPIOA_BASE+0x00))
#define GPIOA_CRH_uint32_REG 	*((volatile uint32 *)(GPIOA_BASE+0x04))
#define GPIOA_ODR_uint32_REG 	*((volatile uint32 *)(GPIOA_BASE+0x0C))


#define GPIOC_BASE 0x40011000
#define GPIOC_CRL_uint32_REG 	*((volatile uint32 *)(GPIOC_BASE+0x00))
#define GPIOC_CRH_uint32_REG 	*((volatile uint32 *)(GPIOC_BASE+0x04))
#define GPIOC_CRL_uint32_REG 	*((volatile uint32 *)(GPIOC_BASE+0x00))
#define GPIOC_ODR_uint32_REG 	*((volatile uint32 *)(GPIOC_BASE+0x0C))

#define GPIO_uint8_PORTA 		0
#define GPIO_uint8_PORTB 		1
#define GPIO_uint8_PORTC 		2
#define GPIO_uint8_PORTD 		3
#define GPIO_uint8_PORTE 		4
#define GPIO_uint8_PORTF 		5

#define GPIO_uint8_PIN0				0
#define GPIO_uint8_PIN1				1
#define GPIO_uint8_PIN2				2
#define GPIO_uint8_PIN3				3
#define GPIO_uint8_PIN4				4
#define GPIO_uint8_PIN5				5
#define GPIO_uint8_PIN6				6
#define GPIO_uint8_PIN7				7
#define GPIO_uint8_PIN8				8
#define GPIO_uint8_PIN9				9
#define GPIO_uint8_PIN10			10
#define GPIO_uint8_PIN11			11
#define GPIO_uint8_PIN12			12
#define GPIO_uint8_PIN13			13
#define GPIO_uint8_PIN14			14
#define GPIO_uint8_PIN15			15


#define AFIO_BASE 0x40010000
#define AFIO_MAPR_uint32_REG 	*((volatile uint32 *)(AFIO_BASE+0x04))
#define AFIO_EXTICR1_uint32_REG 	*((volatile uint32 *)(AFIO_BASE+0x08))


void GPIO_init();
void Toggle_pin_void (uint8 Copy_uint8_PortId,uint8 Copy_uint8_PinId);


#endif /* GPIO_H_ */
