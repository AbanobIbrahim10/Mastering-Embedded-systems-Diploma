/*
 * GPIOA.c
 *
 *  Created on: Nov 17, 2023
 *      Author: MR.ROBOT
 */


#include "GPIO.h"
#include "STD_TYPES.h"
void GPIO_init()
{


	//GPIOA0 SET TO BE INPUT PIN
	CLR_BIT(GPIOA_CRL_uint32_REG,0);
	CLR_BIT(GPIOA_CRL_uint32_REG,1);
	//GPIOA0 SET TO BE INPUT PULLUP/PULDOWN
	CLR_BIT(GPIOA_CRL_uint32_REG,2);
	SET_BIT(GPIOA_CRL_uint32_REG,3);
	//set GPIOA to be input pull-UP
	SET_BIT(GPIOA_ODR_uint32_REG,0);

	//GPIOC13 SET TO BE output PIN
	CLR_BIT(GPIOC_CRH_uint32_REG,20);
	SET_BIT(GPIOC_CRH_uint32_REG,21);
	//GPIOA13 SET TO BE output push pull
	CLR_BIT(GPIOC_CRH_uint32_REG,22);
	CLR_BIT(GPIOC_CRH_uint32_REG,23);
	//set GPIOA to be high voltage output
	SET_BIT(GPIOC_ODR_uint32_REG,13);

	//GPIOA13 SET TO BE output PIN
	CLR_BIT(GPIOA_CRH_uint32_REG,20);
	SET_BIT(GPIOA_CRH_uint32_REG,21);
	//GPIOA13 SET TO BE output push pull
	CLR_BIT(GPIOA_CRH_uint32_REG,22);
	CLR_BIT(GPIOA_CRH_uint32_REG,23);
	//set GPIOA to be high voltage output
	SET_BIT(GPIOA_ODR_uint32_REG,13);



	//attach EXTI0 -> PA0
	CLR_BIT(AFIO_EXTICR1_uint32_REG,0);
	CLR_BIT(AFIO_EXTICR1_uint32_REG,1);
	CLR_BIT(AFIO_EXTICR1_uint32_REG,2);
	CLR_BIT(AFIO_EXTICR1_uint32_REG,3);
}

void Toggle_pin_void (uint8 Copy_uint8_PortId,uint8 Copy_uint8_PinId)
{
	switch(Copy_uint8_PortId)
	{
	case GPIO_uint8_PORTC:
		switch(Copy_uint8_PinId)
		{
		case GPIO_uint8_PIN13:
			TOGGLE_BIT(GPIOC_ODR_uint32_REG,GPIO_uint8_PIN13);
			break;
		}
		break;

	}
}

