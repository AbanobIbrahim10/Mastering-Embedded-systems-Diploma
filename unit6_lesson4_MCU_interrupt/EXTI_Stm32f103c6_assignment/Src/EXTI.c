/*
 * EXTI.c
 *
 *  Created on: Nov 18, 2023
 *      Author: MR.ROBOT
 */


#include "STD_TYPES.h"
#include "EXTI.h"


void EXTI_init()
{
	//EXTI0 rising edge
	SET_BIT(EXTI_RTSR_uint32_REG,0);
	//EXTIO interrupt Enable
	SET_BIT(EXTI_IMR_uint32_REG,0);

}
