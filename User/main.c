#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"

int main(void)
{
	OLED_Init();
	OLED_ShowHexNum(2, 1, (uint32_t)&ADC1->DR, 8);
	//ADC1是结构体指针，指向ADC1外设的基地址，访问结构体成员就是加一个地址偏移，即指定的寄存器
	while (1)
	{
		
	}
}
