#include "stm32f10x.h"

/*******************************************************
GPIO操作操作流程：
1、RCC中打开管脚对应的端口时钟
2、配置对应的引脚
3、设置引脚状态
********************************************************/

void LED_Init()
{
    GPIO_InitTypeDef initstruct;
	//开启GPIOA时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
    initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    initstruct.GPIO_Pin = GPIO_Pin_1;
	//用以上参数初始化引脚
    GPIO_Init(GPIOA, &initstruct);
}

void LED_Triggre()
{
    int i;
    GPIO_SetBits(GPIOA, GPIO_Pin_1);

    for(i = 0; i < 10000; i++);

    GPIO_ResetBits(GPIOA, GPIO_Pin_1);

    for(i = 0; i < 10000; i++);
}

int main()
{
    LED_Init();

    while(1) {
        LED_Triggre();
    }
}
