#include "stm32f10x.h"

uint16_t DMASize;
void DMA_Initilize(uint32_t A,uint32_t B,uint16_t Size)
{
    DMASize=Size;
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    DMA_InitTypeDef DMA_InitStructure;
    DMA_InitStructure.DMA_PeripheralBaseAddr = A;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Enable;
    DMA_InitStructure.DMA_MemoryBaseAddr = B;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_MemoryInc=DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_DIR=DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize=Size;
    DMA_InitStructure.DMA_Mode=DMA_Mode_Normal;
    DMA_InitStructure.DMA_M2M=DMA_M2M_Enable;
    DMA_InitStructure.DMA_Priority=DMA_Priority_Medium;
    DMA_Init(DMA1_Channel1, &DMA_InitStructure);//软件触发，通道可以任意选择
    DMA_Cmd(DMA1_Channel1, DISABLE);
}
void DMA_Transfer(void)
{
    DMA_Cmd(DMA1_Channel1, DISABLE);//在修改DMA1_Channel1->CNDTR寄存器前，必须先让DMA1_Channel1失能
    DMA_SetCurrDataCounter(DMA1_Channel1, DMASize);
    DMA_Cmd(DMA1_Channel1, ENABLE);
    while(DMA_GetFlagStatus(DMA1_FLAG_TC1)==RESET);//没转运完就等待
    DMA_ClearFlag(DMA1_FLAG_TC1);//转运完了就清除标志位
}