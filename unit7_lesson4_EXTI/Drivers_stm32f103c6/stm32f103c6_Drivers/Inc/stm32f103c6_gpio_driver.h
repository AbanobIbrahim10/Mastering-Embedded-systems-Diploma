/*
 * stm32f103c6_gpio_driver.h
 *
 *  Created on: Dec 13, 2023
 *      Author: MR.ROBOT
 */

#ifndef INC_STM32F103C6_GPIO_DRIVER_H_
#define INC_STM32F103C6_GPIO_DRIVER_H_


//-----------------------------
//Includes
//-----------------------------

#include "stm32f103c6.h"


//-----------------------------
//User type definitions (structures)
//-----------------------------

typedef struct
{
	uint16_t GPIO_PinNumber;			//specifies the GPIO pins to be configured
										//this parameter can be a value of @ref GPIO_PIN_Define

	uint8_t GPIO_Mode;					//specifies the GPIO Mode (input-output-etc...)
										//this parameter can be a value of @ref GPIO_MODE_Define

	uint8_t GPIO_Speed;					//specifies the speed of the selected output pin
										//this parameter can be a value of @ref GPIO_SPEED_Define


}GPIO_PinConfig_t;

//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref GPIO_PIN_Define

#define GPIO_PIN_0						0x01
#define GPIO_PIN_1						0x02
#define GPIO_PIN_2						0x04
#define GPIO_PIN_3						0x08
#define GPIO_PIN_4						0x10
#define GPIO_PIN_5						0x20
#define GPIO_PIN_6						0x40
#define GPIO_PIN_7						0x80
#define GPIO_PIN_8						0x100
#define GPIO_PIN_9						0x200
#define GPIO_PIN_10						0x400
#define GPIO_PIN_11						0x800
#define GPIO_PIN_12						0x1000
#define GPIO_PIN_13						0x2000
#define GPIO_PIN_14						0x4000
#define GPIO_PIN_15						0x8000

//@ref GPIO_MODE_Define
//in several modes:
//• Input floating
//• Input pull-up
//• Input-pull-down
//• Analog
//• Output open-drain
//• Output push-pull
//• Alternate function push-pull
//• Alternate function open-drain

#define GPIO_MODE_ANALOG				0X00
#define GPIO_MODE_INPUT_FL				0X01
#define GPIO_MODE_INPUT_PU				0X02
#define GPIO_MODE_INPUT_PD				0X03
#define GPIO_MODE_OUTPUT_PP				0X04
#define GPIO_MODE_OUTPUT_OD				0X05
#define GPIO_MODE_ALTERNATIVE_PP		0X06
#define GPIO_MODE_ALTERNATIVE_OD		0X07


//@ref GPIO_SPEED_Define
#define GPIO_SPEED_10M					1
#define GPIO_SPEED_2M					2
#define GPIO_SPEED_50M					3

#define GPIO_PIN_VALUE_HIGH					1
#define GPIO_PIN_VALUE_LOW					0


/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/


void MCAL_GPIO_Init(GPIO_TypeDef_t * GPIOx,GPIO_PinConfig_t * Pin_config);

void MCAL_GPIO_Write_Pin(GPIO_TypeDef_t * GPIOx,uint16_t GPIO_Pin_Number,uint8_t GPIO_Pin_Value);
void MCAL_GPIO_Write_Port(GPIO_TypeDef_t * GPIOx,uint32_t GPIO_Port_Value);

uint8_t MCAL_GPIO_Read_Pin(GPIO_TypeDef_t * GPIOx,uint16_t GPIO_Pin_Number);
uint16_t MCAL_GPIO_Read_Port(GPIO_TypeDef_t * GPIOx);

#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */
