/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abanoub Yanni
 * @brief          : configure the RCC, NVIC, EXTI and GPIOA peripherals to make LED toggling project controlled by a push button
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "STD_TYPES.h"
#include "RCC.h"
#include "GPIO.h"
#include "EXTI.h"
#include "NVIC.h"

void EXTI0_IRQHandler();
volatile int x=0;
int main(void)
{


	RCC_init();
	GPIO_init();
	EXTI_init();
	NVIC_init();


    /* Loop forever */
	while(1);
	return 0;
}


void EXTI0_IRQHandler()
{
			for(x=0;x<100000;x++);
	Toggle_pin_void(GPIO_uint8_PORTC,GPIO_uint8_PIN13);
	SET_BIT(EXTI_PR_uint32_REG,0);

}
