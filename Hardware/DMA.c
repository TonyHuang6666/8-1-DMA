#include "stm32f10x.h"

void DMA_Initilize(uint32_t A,uint32_t B,uint32_t Size)
{
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    DMA_InitTypeDef DMA_InitStruct;
    DMA_InitStruct.DMA_MemoryBaseAddr=A;
    DMA_InitStruct.DMA_MemoryDataSize=DMA_MemoryDataSize_Byte;
    DMA_InitStruct.DMA_MemoryInc==DMA_MemoryInc_Enable;
    DMA_InitStruct.DMA_PeripheralBaseAddr=B;
    DMA_InitStruct.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Byte;
    DMA_InitStruct.DMA_PeripheralInc=DMA_PeripheralInc_Enable;
    DMA_InitStruct.DMA_BufferSize=Size;
    DMA_InitStruct.DMA_DIR=DMA_DIR_PeripheralDST;
    DMA_InitStruct.DMA_M2M=DMA_M2M_Enable;
    DMA_InitStruct.DMA_Mode=DMA_Mode_Normal;
    DMA_InitStruct.DMA_Priority=DMA_Priority_Medium;
    DMA_Init(DMA1_Channel1, &DMA_InitStruct);//软件触发，通道可以任意选择
    DMA_Cmd(DMA1_Channel1, ENABLE);
}