/*
 * stm32f103c6_gpio_driver.c
 *
 *  Created on: Dec 13, 2023
 *      Author: MR.ROBOT
 */


#include "stm32f103c6_gpio_driver.h"
#include "stm32f103c6.h"
/**================================================================
 * @Fn			-
 * @brief 		-
 * @param[in] 	-
 * @param[out] 	-
 * @retval		-
 * Note			-
 */

//============================================
//===========Generic Function=================
//============================================
uint8_t GET_PSITION(uint16_t pin)
{
	uint8_t cntr=0;
	while(pin !=1)
	{
		cntr++;
		pin=pin>>1;
	}

	return (cntr>7)?(cntr-8):(cntr);
}

void MCAL_GPIO_Init(GPIO_TypeDef_t * GPIOx,GPIO_PinConfig_t * Pin_config)
{

	uint32_t* ptr_config_reg = (Pin_config->GPIO_PinNumber > GPIO_PIN_7)?((uint32_t*)&(GPIOx->GPIOx_CRH)):((uint32_t*)&(GPIOx->GPIOx_CRL));
	uint8_t shift_value = GET_PSITION(Pin_config->GPIO_PinNumber)*4;
	*ptr_config_reg &= ~((uint32_t)0xF) <<shift_value ;

	if (Pin_config->GPIO_Mode==GPIO_MODE_ANALOG || Pin_config->GPIO_Mode==GPIO_MODE_INPUT_FL || Pin_config->GPIO_Mode==GPIO_MODE_INPUT_PU )
	{
		*ptr_config_reg|=((((Pin_config->GPIO_Mode)<<2))<<(shift_value));

	}
	else if(Pin_config->GPIO_Mode==GPIO_MODE_INPUT_PD)
	{
		*ptr_config_reg|=((0b1000)<<(shift_value));

	}
	else
	{

		*ptr_config_reg |=((((Pin_config->GPIO_Mode-4)<<2)|(Pin_config->GPIO_Speed))<<shift_value);
	}
}




void MCAL_GPIO_Write_Pin(GPIO_TypeDef_t * GPIOx,uint16_t GPIO_Pin_Number,uint8_t GPIO_Pin_Value)
{
	GPIOx->GPIOx_BSRR=(GPIO_Pin_Value == GPIO_PIN_VALUE_HIGH )?((uint32_t)GPIO_Pin_Number):((uint32_t)GPIO_Pin_Number<<16);
}

void MCAL_GPIO_Write_Port(GPIO_TypeDef_t * GPIOx,uint32_t GPIO_Port_Value)
{
	GPIOx->GPIOx_ODR=GPIO_Port_Value;
}


uint8_t MCAL_GPIO_Read_Pin(GPIO_TypeDef_t * GPIOx,uint16_t GPIO_Pin_Number)
{
	return ((GPIOx->GPIOx_IDR & GPIO_Pin_Number) == 0)?(0x00U):(0x01U);

}

uint16_t MCAL_GPIO_Read_Port(GPIO_TypeDef_t * GPIOx)
{
	return (uint16_t)GPIOx->GPIOx_IDR;
}
