#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "DMA.h"
uint8_t DataA[]={0x00,0x01,0x02,0x03};
uint8_t DataB[]={0,0,0,0};
int main(void)
{
	OLED_Init();
	DMA_Initilize((uint32_t)DataA,(uint32_t)DataB,4);
	OLED_ShowString(1,1,"DataA:");
	OLED_ShowString(3,1,"DataB:");
	OLED_ShowHexNum(2,1,DataA[0],2);
	OLED_ShowHexNum(2,3,DataA[1],2);
	OLED_ShowHexNum(2,5,DataA[2],2);
	OLED_ShowHexNum(2,7,DataA[3],2);
	OLED_ShowHexNum(4,1,DataB[0],2);
	OLED_ShowHexNum(4,3,DataB[1],2);
	OLED_ShowHexNum(4,5,DataB[2],2);
	OLED_ShowHexNum(4,7,DataB[3],2);
	while(1)
	{
		DataA[0]++;
		DataA[1]++;
		DataA[2]++;
		DataA[3]++;
		OLED_ShowHexNum(2,1,DataA[0],2);
		OLED_ShowHexNum(2,3,DataA[1],2);
		OLED_ShowHexNum(2,5,DataA[2],2);
		OLED_ShowHexNum(2,7,DataA[3],2);
		Delay_ms(1000);
		DMA_Transfer();
		OLED_ShowHexNum(4,1,DataB[0],2);
		OLED_ShowHexNum(4,3,DataB[1],2);
		OLED_ShowHexNum(4,5,DataB[2],2);
		OLED_ShowHexNum(4,7,DataB[3],2);
	}
}
