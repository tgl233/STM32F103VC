#include "stm32f10x.h"

/*******************************************************
GPIO�����������̣�
1��RCC�д򿪹ܽŶ�Ӧ�Ķ˿�ʱ��
2�����ö�Ӧ������
3����������״̬
********************************************************/

void LED_Init()
{
    GPIO_InitTypeDef initstruct;
	//����GPIOAʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
    initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    initstruct.GPIO_Pin = GPIO_Pin_1;
	//�����ϲ�����ʼ������
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
