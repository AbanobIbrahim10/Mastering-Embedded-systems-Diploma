################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103c6_Drivers/EXTI/stm32f103c6_EXTI_driver.c 

OBJS += \
./stm32f103c6_Drivers/EXTI/stm32f103c6_EXTI_driver.o 

C_DEPS += \
./stm32f103c6_Drivers/EXTI/stm32f103c6_EXTI_driver.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103c6_Drivers/EXTI/%.o stm32f103c6_Drivers/EXTI/%.su stm32f103c6_Drivers/EXTI/%.cyclo: ../stm32f103c6_Drivers/EXTI/%.c stm32f103c6_Drivers/EXTI/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/workspace/Drivers_stm32f103c6/HAL/Inc" -I"D:/workspace/Drivers_stm32f103c6/stm32f103c6_Drivers" -I"D:/workspace/Drivers_stm32f103c6/stm32f103c6_Drivers/Inc" -include"D:/workspace/Drivers_stm32f103c6/stm32f103c6_Drivers/Inc/stm32f103c6_gpio_driver.h" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-stm32f103c6_Drivers-2f-EXTI

clean-stm32f103c6_Drivers-2f-EXTI:
	-$(RM) ./stm32f103c6_Drivers/EXTI/stm32f103c6_EXTI_driver.cyclo ./stm32f103c6_Drivers/EXTI/stm32f103c6_EXTI_driver.d ./stm32f103c6_Drivers/EXTI/stm32f103c6_EXTI_driver.o ./stm32f103c6_Drivers/EXTI/stm32f103c6_EXTI_driver.su

.PHONY: clean-stm32f103c6_Drivers-2f-EXTI

