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
	volatile uint32_t AFIO_EXTICR1;
	volatile uint32_t AFIO_EXTICR2;
	volatile uint32_t AFIO_EXTICR3;
	volatile uint32_t AFIO_EXTICR4;
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
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA			((GPIO_TypeDef_t *)(GPIOA_BASE))
#define GPIOB			((GPIO_TypeDef_t *)(GPIOB_BASE))
#define GPIOC			((GPIO_TypeDef_t *)(GPIOC_BASE))
#define GPIOD			((GPIO_TypeDef_t *)(GPIOD_BASE))
#define GPIOE			((GPIO_TypeDef_t *)(GPIOE_BASE))
#define GPIOF			((GPIO_TypeDef_t *)(GPIOF_BASE))


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



#endif /* INC_STM32F103C6_H_ */
