/*
 * NVIC.c
 *
 *  Created on: Nov 18, 2023
 *      Author: MR.ROBOT
 */



#include "NVIC.h"
#include "STD_TYPES.h"
void NVIC_init()
{
	SET_BIT(NVIC_SETENA_uint32_REG,6);
}
