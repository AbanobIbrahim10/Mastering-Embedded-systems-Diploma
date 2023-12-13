/*
 * RCC.c
 *
 *  Created on: Nov 16, 2023
 *      Author: Abanoub Yanni
 */


#include "RCC.h"
#include "STD_TYPES.h"

void RCC_init()
{
	/*Advanced "using PLL"*/
//	//use a crystal not an external clock
//	CLR_BIT(RCC_CR_uint32_REG,18);
//
//
//	//Enable HSE clock
//	SET_BIT(RCC_CR_uint32_REG,16);
//
//	//check if HSE clock is ready
//	while(!GET_BIT(RCC_CR_uint32_REG,17));
//
//	/******adjust PLL configuration******/
//
//	//PLLXTPRE MUX not divide by 2
//	CLR_BIT(RCC_CFGR_uint32_REG,17);
//
//	//PLL SRC choose SHE as an input to PLL MUX
//	SET_BIT(RCC_CFGR_uint32_REG,16);
//
//	//PLL multiplication x2
//	CLR_BIT(RCC_CFGR_uint32_REG,18);
//	CLR_BIT(RCC_CFGR_uint32_REG,19);
//	CLR_BIT(RCC_CFGR_uint32_REG,20);
//	CLR_BIT(RCC_CFGR_uint32_REG,21);
//
//
//	//Adjust AHB prescaler to be not divided
//	CLR_BIT(RCC_CFGR_uint32_REG,7);
//
//	//APB2 Bus Prescaler to be x1
//	CLR_BIT(RCC_CFGR_uint32_REG,13);
//
//
//	//APB1 Bus Prescaler divided by 2
//	CLR_BIT(RCC_CFGR_uint32_REG,8);
//	CLR_BIT(RCC_CFGR_uint32_REG,9);
//	SET_BIT(RCC_CFGR_uint32_REG,10);
//
//	//ADC prescaler to divided by 2
//	CLR_BIT(RCC_CFGR_uint32_REG,14);
//	CLR_BIT(RCC_CFGR_uint32_REG,15);
//
//	//Enable PLL circuit
//	SET_BIT(RCC_CR_uint32_REG,24);
//
//	//switch system clock to the PLL circuit
//	CLR_BIT(RCC_CFGR_uint32_REG,0);
//	SET_BIT(RCC_CFGR_uint32_REG,1);
//
//	//turn off internal clock to save power
//	CLR_BIT(RCC_CR_uint32_REG,0);


/******provide clock To some peripherals******/
	//provide clock to GPIOA
	SET_BIT(RCC_APB2ENR_uint32_REG,2);
	//provide clock to GPIOC
	SET_BIT(RCC_APB2ENR_uint32_REG,4);
	//provide clock to AFIO
	SET_BIT(RCC_APB2ENR_uint32_REG,0);



}
