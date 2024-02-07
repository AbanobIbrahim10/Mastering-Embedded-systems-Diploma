/*
 * stm32f103c6.h
 *
 *  Created on: Dec 14, 2023
 *      Author: MR.ROBOT
 */

#ifndef INC_STM32F103C6_H_
#define INC_STM32F103C6_H_


//-----------------------------
//Includes
//-----------------------------


#include "STD_TYPES.h"

//-----------------------------
//Base addresses for Memories
//-----------------------------
//-----------------------------
//Base addresses for BUS Peripherals
//-----------------------------

#define GPIOA_BASE			0x40010800
#define GPIOB_BASE			0x40010C00
#define GPIOC_BASE			0x40011000
#define GPIOD_BASE			0x40011400
#define GPIOE_BASE			0x40011800
#define GPIOF_BASE			0x40011C00
#define RCC_BASE			0x40021000
#define AFIO_BASE			0x40010000
#define EXTI_BASE			0x40010400
#define NVIC_BASE			0xE000E100



//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:GPIOx
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t GPIOx_CRL;
	volatile uint32_t GPIOx_CRH;
	volatile uint32_t GPIOx_IDR;
	volatile uint32_t GPIOx_ODR;
	volatile uint32_t GPIOx_BSRR;
	volatile uint32_t GPIOx_BRR;
	volatile uint32_t GPIOx_LCKR;


}GPIO_TypeDef_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t AFIO_EVCR;
	volatile uint32_t AFIO_MAPR;
	volatile uint32_t AFIO_EXTICR[4];
	volatile uint32_t RESERVED;
	volatile uint32_t AFIO_MAPR2;

}AFIO_TypeDef_t;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:EXTI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t EXTI_IMR;
	volatile uint32_t EXTI_EMR;
	volatile uint32_t EXTI_RTSR;
	volatile uint32_t EXTI_FTSR;
	volatile uint32_t EXTI_SWIER;
	volatile uint32_t EXTI_PR;

}EXTI_TypeDef_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:NVIC
//-*-*-*-*-*-*-*-*-*-*-*
//IRQ ENABLE
#define NVIC_ISER0		*(volatile uint32_t *)(NVIC_BASE+0x00)
#define NVIC_ISER1		*(volatile uint32_t *)(NVIC_BASE+0x04)
#define NVIC_ISER2		*(volatile uint32_t *)(NVIC_BASE+0x08)
//IRQ DISABLE
#define NVIC_ICER0		*(volatile uint32_t *)(NVIC_BASE+0x80)
#define NVIC_ICER1		*(volatile uint32_t *)(NVIC_BASE+0x84)
#define NVIC_ICER2		*(volatile uint32_t *)(NVIC_BASE+0x88)


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA			((GPIO_TypeDef_t *)(GPIOA_BASE))
#define GPIOB			((GPIO_TypeDef_t *)(GPIOB_BASE))
#define GPIOC			((GPIO_TypeDef_t *)(GPIOC_BASE))
#define GPIOD			((GPIO_TypeDef_t *)(GPIOD_BASE))
#define GPIOE			((GPIO_TypeDef_t *)(GPIOE_BASE))
#define GPIOF			((GPIO_TypeDef_t *)(GPIOF_BASE))
#define EXTI			((EXTI_TypeDef_t *)(EXTI_BASE))
#define AFIO			((AFIO_TypeDef_t*)(AFIO_BASE))

//-*-*-*-*-*-*-*-*-*-*-*-
//IRQ enable and disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define NVIC_IRQ6_EXTI0_Enable	        (NVIC_ICER0|=1<<6)
#define NVIC_IRQ7_EXTI1_Enable	        (NVIC_ICER0|=1<<7)
#define NVIC_IRQ8_EXTI2_Enable	        (NVIC_ICER0|=1<<8)
#define NVIC_IRQ9_EXTI3_Enable	        (NVIC_ICER0|=1<<9)
#define NVIC_IRQ10_EXTI4_Enable	        (NVIC_ICER0|=1<<10)
#define NVIC_IRQ23_EXTI5_9_Enable     	(NVIC_ICER0|=1<<23)
#define NVIC_IRQ40_EXTI10_15_Enable	    (NVIC_ICER1|=1<<8)

#define NVIC_IRQ6_EXTI0_Disable	        (NVIC_ICER0|=1<<6)
#define NVIC_IRQ7_EXTI1_Disable	        (NVIC_ICER0|=1<<7)
#define NVIC_IRQ8_EXTI2_Disable	        (NVIC_ICER0|=1<<8)
#define NVIC_IRQ9_EXTI3_Disable	        (NVIC_ICER0|=1<<9)
#define NVIC_IRQ10_EXTI4_Disable	    (NVIC_ICER0|=1<<10)
#define NVIC_IRQ23_EXTI5_9_Disable	    (NVIC_ICER0|=1<<23)
#define NVIC_IRQ40_EXTI10_15_Disable	(NVIC_ICER1|=1<<8)

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define AFIO_CLOCK_EN()		SET_BIT(*((volatile uint32_t *)(RCC_BASE+0x18)),0)

#define GPIOA_CLOCK_EN()		SET_BIT(*((volatile uint32_t *)(RCC_BASE+0x18)),2)
#define GPIOB_CLOCK_EN()		SET_BIT(*((volatile uint32_t *)(RCC_BASE+0x18)),3)
#define GPIOC_CLOCK_EN()		SET_BIT(*((volatile uint32_t *)(RCC_BASE+0x18)),4)
#define GPIOD_CLOCK_EN()		SET_BIT(*((volatile uint32_t *)(RCC_BASE+0x18)),5)
#define GPIOE_CLOCK_EN()		SET_BIT(*((volatile uint32_t *)(RCC_BASE+0x18)),6)
#define GPIOF_CLOCK_EN()		SET_BIT(*((volatile uint32_t *)(RCC_BASE+0x18)),7)

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*


/*****************/
/*******IVT*******/
//EXTI
#define EXTI0_IRQ	6
#define EXTI1_IRQ	7
#define EXTI2_IRQ	8
#define EXTI3_IRQ	9
#define EXTI4_IRQ	10
#define EXTI5_IRQ	23
#define EXTI6_IRQ	23
#define EXTI7_IRQ	23
#define EXTI8_IRQ	23
#define EXTI9_IRQ	23
#define EXTI10_IRQ	40
#define EXTI11_IRQ	40
#define EXTI12_IRQ	40
#define EXTI13_IRQ	40
#define EXTI14_IRQ	40
#define EXTI15_IRQ	40


#endif /* INC_STM32F103C6_H_ */
