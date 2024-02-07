/*
 * stm32f103c6_EXTI_driver.c
 *
 *  Created on: Jan 10, 2024
 *      Author: MR.ROBOT
 */


#include "STD_TYPES.h"
#include "stm32f103c6.h"
#include "stm32f103c6_gpio_driver.h"
#include  "stm32f103c6_EXTI_driver.h"


//====================================================
//===========Generic Macros And Variables=============
//====================================================

#define AFIO_PORT_CHOOSING(x)			((x==GPIOA)?0:\
		(x==GPIOB)?1:\
				(x==GPIOC)?2:\
						(x==GPIOD)?3:0)


void (*GP_EXTI_Ptr_Function_CallBack[16])(void);
//============================================
//===========Generic Function=================
//============================================

void Enable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Enable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Enable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Enable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Enable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Enable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Enable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Enable;
		break;


	}

}



void Disable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Disable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Disable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Disable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Disable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Disable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Disable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Disable;
		break;


	}

}


void update_EXTI(EXTI_PIN_CONFIG_t* EXTI_Pin_Config)
{

	//Set Required Pin To Be Input Floating
	GPIO_PinConfig_t PinConfig;
	PinConfig.GPIO_PinNumber=EXTI_Pin_Config->EXTI_PIN.EXTI_GPIO_PIN;
	PinConfig.GPIO_Mode=GPIO_MODE_INPUT_FL;
	MCAL_GPIO_Init(EXTI_Pin_Config->EXTI_PIN.EXTI_GPIO_PORT,&PinConfig);

	//Route GPIO Pin To EXTI Line
	uint8_t AFIO_EXTICR_Index=(uint8_t)EXTI_Pin_Config->EXTI_PIN.EXTI_INPUT_LINE/4;
	uint8_t AFIO_EXTICR_Position=((uint8_t)EXTI_Pin_Config->EXTI_PIN.EXTI_INPUT_LINE%4)*4;

	//Reset the value of the register before writing
	AFIO->AFIO_EXTICR[AFIO_EXTICR_Index] &=~(0xF<<AFIO_EXTICR_Position);
	//write The value to choose the the port
	uint8_t Value=AFIO_PORT_CHOOSING(EXTI_Pin_Config->EXTI_PIN.EXTI_GPIO_PORT);
	AFIO->AFIO_EXTICR[AFIO_EXTICR_Index] |=(Value<<AFIO_EXTICR_Position);

	//Set trigger Rising or falling edge
	//Reset registers first
	EXTI->EXTI_RTSR &=~(1<<EXTI_Pin_Config->EXTI_PIN.EXTI_INPUT_LINE);
	EXTI->EXTI_FTSR &=~(1<<EXTI_Pin_Config->EXTI_PIN.EXTI_INPUT_LINE);

	if(EXTI_Pin_Config->EXTI_Trigger_Sense == EXTI_Trigger_Rising_edge)
	{
		EXTI->EXTI_RTSR |= (1<<EXTI_Pin_Config->EXTI_PIN.EXTI_INPUT_LINE);

	}
	else if(EXTI_Pin_Config->EXTI_Trigger_Sense == EXTI_Trigger_falling_edge)
	{
		EXTI->EXTI_FTSR |= (1<<EXTI_Pin_Config->EXTI_PIN.EXTI_INPUT_LINE);
	}
	else if(EXTI_Pin_Config->EXTI_Trigger_Sense == EXTI_Trigger_Rising_falling_edge)
	{
		EXTI->EXTI_RTSR |= (1<<EXTI_Pin_Config->EXTI_PIN.EXTI_INPUT_LINE);
		EXTI->EXTI_FTSR |= (1<<EXTI_Pin_Config->EXTI_PIN.EXTI_INPUT_LINE);
	}

	//Set CallBack Function
	GP_EXTI_Ptr_Function_CallBack[EXTI_Pin_Config->EXTI_PIN.EXTI_INPUT_LINE]=EXTI_Pin_Config->EXTI_Ptr_Function_CallBack;

	//Enable/Disable IRQ In EXTI and NVIC
	if(EXTI_Pin_Config->EXTI_IRQ_EN==EXTI_IRQ_Enable)
	{
		EXTI->EXTI_IMR |= 1<<EXTI_Pin_Config->EXTI_PIN.EXTI_INPUT_LINE;
		Enable_NVIC(EXTI_Pin_Config->EXTI_PIN.EXTI_INPUT_LINE);
	}
	else if(EXTI_Pin_Config->EXTI_IRQ_EN==EXTI_IRQ_Disable)
	{
		EXTI->EXTI_IMR &= ~(1<<EXTI_Pin_Config->EXTI_PIN.EXTI_INPUT_LINE);
		Disable_NVIC(EXTI_Pin_Config->EXTI_PIN.EXTI_INPUT_LINE);
	}
	else
	{
		//MISRA
	}
}




void MCAL_EXTI_GPIO_init(EXTI_PIN_CONFIG_t* EXTI_Pin_Config)
{
	update_EXTI(EXTI_Pin_Config);
}



void MCAL_EXTI_GPIO_Deinit()
{

	EXTI->EXTI_IMR=0x00000000;
	EXTI->EXTI_EMR=0x00000000;
	EXTI->EXTI_FTSR=0x00000000;
	EXTI->EXTI_RTSR=0x00000000;
	EXTI->EXTI_SWIER=0x00000000;
	EXTI->EXTI_PR=0xFFFFFFFF;
	//Disable NVIC IRQs
	NVIC_IRQ6_EXTI0_Disable;
	NVIC_IRQ7_EXTI1_Disable;
	NVIC_IRQ8_EXTI2_Disable;
	NVIC_IRQ9_EXTI3_Disable;
	NVIC_IRQ10_EXTI4_Disable;
	NVIC_IRQ23_EXTI5_9_Disable;
	NVIC_IRQ40_EXTI10_15_Disable;


}
void MCAL_EXTI_GPIO_update(EXTI_PIN_CONFIG_t* EXTI_Pin_Config)
{
	update_EXTI(EXTI_Pin_Config);
}

void EXTI0_IRQHandler()
{
	GP_EXTI_Ptr_Function_CallBack[0]();
}
void EXTI1_IRQHandler()
{
	EXTI->EXTI_PR |= 1<<0;
	GP_EXTI_Ptr_Function_CallBack[1]();
}
void EXTI2_IRQHandler()
{
	EXTI->EXTI_PR |= 1<<1;
	GP_EXTI_Ptr_Function_CallBack[2]();
}
void EXTI3_IRQHandler()
{
	EXTI->EXTI_PR |= 1<<2;
	GP_EXTI_Ptr_Function_CallBack[3]();
}
void EXTI4_IRQHandler()
{
	EXTI->EXTI_PR |= 1<<3;
	GP_EXTI_Ptr_Function_CallBack[4]();
}
void EXTI9_5_IRQHandler()
{
	if(EXTI->EXTI_PR & (1<<5)){EXTI->EXTI_PR |= 1<<5; GP_EXTI_Ptr_Function_CallBack[5]();}
	if(EXTI->EXTI_PR & (1<<6)){EXTI->EXTI_PR |= 1<<6; GP_EXTI_Ptr_Function_CallBack[6]();}
	if(EXTI->EXTI_PR & (1<<7)){EXTI->EXTI_PR |= 1<<7; GP_EXTI_Ptr_Function_CallBack[7]();}
	if(EXTI->EXTI_PR & (1<<8)){EXTI->EXTI_PR |= 1<<8; GP_EXTI_Ptr_Function_CallBack[8]();}
	if(EXTI->EXTI_PR & (1<<9)){EXTI->EXTI_PR |= 1<<9; GP_EXTI_Ptr_Function_CallBack[9]();}

}
void EXTI15_10_IRQHandler ()
{
	if(EXTI->EXTI_PR & (1<<10)){EXTI->EXTI_PR |= 1<<10; GP_EXTI_Ptr_Function_CallBack[10]();}
	if(EXTI->EXTI_PR & (1<<11)){EXTI->EXTI_PR |= 1<<11; GP_EXTI_Ptr_Function_CallBack[11]();}
	if(EXTI->EXTI_PR & (1<<12)){EXTI->EXTI_PR |= 1<<12; GP_EXTI_Ptr_Function_CallBack[12]();}
	if(EXTI->EXTI_PR & (1<<13)){EXTI->EXTI_PR |= 1<<13; GP_EXTI_Ptr_Function_CallBack[13]();}
	if(EXTI->EXTI_PR & (1<<14)){EXTI->EXTI_PR |= 1<<14; GP_EXTI_Ptr_Function_CallBack[14]();}
	if(EXTI->EXTI_PR & (1<<15)){EXTI->EXTI_PR |= 1<<15; GP_EXTI_Ptr_Function_CallBack[15]();}

}

