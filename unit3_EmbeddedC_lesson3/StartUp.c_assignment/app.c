#include "STD_TYPES.h"

#define RCC_APB2ENR_uint32_REG      *((volatile uint32*)0x40021018)
#define GPIO_CRH_uint32_REG      *((volatile uint32*)0x40010804)
#define GPIO_ODR_uint32_REG      *((volatile uint32*)0x4001080C)

int g_arr[5]={1,2,3,4,5};
char g_string[]="hello";
int arr[10];
int main()
{
    RCC_APB2ENR_uint32_REG |= (1<<2);
    GPIO_CRH_uint32_REG &= 0xFF0FFFFF;
    GPIO_CRH_uint32_REG |= 0x00200000;
    volatile unsigned int i=0;

    while(1)
    {
        SET_BIT(GPIO_ODR_uint32_REG,13);
        for(i=0;i<500000;i++);
        CLR_BIT(GPIO_ODR_uint32_REG,13);
        for(i=0;i<500000;i++);

    }

    return 0;
}