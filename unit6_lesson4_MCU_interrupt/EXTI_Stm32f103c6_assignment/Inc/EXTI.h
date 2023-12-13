/*
 * EXTI.h
 *
 *  Created on: Nov 16, 2023
 *      Author: MR.ROBOT
 */

#ifndef EXTI_H_
#define EXTI_H_

#define EXTI_BASE 0x40010400

#define EXTI_RTSR_uint32_REG 	*((volatile uint32 *)(EXTI_BASE+0x08))
#define EXTI_IMR_uint32_REG 	*((volatile uint32 *)(EXTI_BASE+0x00))
#define EXTI_PR_uint32_REG 		*((volatile uint32 *)(EXTI_BASE+0x14))

void EXTI_init();

#endif /* EXTI_H_ */
