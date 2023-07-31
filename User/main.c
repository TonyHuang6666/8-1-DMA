#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"

uint8_t i = 0x66;
int main(void)
{
	OLED_Init();
	OLED_ShowHexNum(1, 1, i, 2);
	OLED_ShowHexNum(2, 1, (uint32_t)&i, 8);
	while (1)
	{
		
	}
}
