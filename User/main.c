#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"

int main(void)
{
	OLED_Init();
	OLED_ShowHexNum(2, 1, (uint32_t)&ADC1->DR, 8);
	while (1)
	{
		
	}
}
