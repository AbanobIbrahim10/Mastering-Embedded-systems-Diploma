/*
 * RCC.h
 *
 *  Created on: Nov 16, 2023
 *      Author: MR.ROBOT
 */

#ifndef RCC_H_
#define RCC_H_

#define RCC_BASE 0x40021000


#define RCC_CR_uint32_REG *((volatile uint32 *)(RCC_BASE+0x00))
#define RCC_CFGR_uint32_REG *((volatile uint32 *)(RCC_BASE+0x04))
#define RCC_APB2ENR_uint32_REG *((volatile uint32 *)(RCC_BASE+0x18))

void RCC_init();
#endif /* RCC_H_ */
