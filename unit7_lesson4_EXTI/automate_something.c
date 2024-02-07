#include <stdio.h>


int main()
{

    for(int i=0;i<16;i++)
    {
        printf("//EXTI%d\n",i);
        printf("#define EXTI%iPA%i	(EXTI_GPIO_MAPPING_t){EXTI%i,GPIOA,GPIO_PIN_%i,EXTI%i_IRQ}\n",i,i,i,i,i);
        printf("#define EXTI%iPB%i	(EXTI_GPIO_MAPPING_t){EXTI%i,GPIOB,GPIO_PIN_%i,EXTI%i_IRQ}\n",i,i,i,i,i);
        printf("#define EXTI%iPC%i	(EXTI_GPIO_MAPPING_t){EXTI%i,GPIOC,GPIO_PIN_%i,EXTI%i_IRQ}\n",i,i,i,i,i);
        printf("#define EXTI%iPD%i	(EXTI_GPIO_MAPPING_t){EXTI%i,GPIOD,GPIO_PIN_%i,EXTI%i_IRQ}\n",i,i,i,i,i);

    }

    return 0;
}