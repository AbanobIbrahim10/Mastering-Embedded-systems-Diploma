/*
 * NVIC.h
 *
 *  Created on: Nov 16, 2023
 *      Author: MR.ROBOT
 */

#ifndef NVIC_H_
#define NVIC_H_

#define NVIC_SETENA_uint32_REG 	*((volatile uint32 *)(0xE000E100))

void NVIC_init();

#endif /* NVIC_H_ */
