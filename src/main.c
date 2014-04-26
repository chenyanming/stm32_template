#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
GPIO_InitTypeDef GPIO_InitStructure;//声明GPIO_InitStructure  
void LED_Init(void) 
{ 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);   //开GPIOA时钟
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15;  //configure Pin0,1
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;    //推挽输出 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  // 最高输出速率50Hz    
  GPIO_Init(GPIOB, &GPIO_InitStructure);             //初始化GPIOA
}
void Delay(vu32 nCount) 
//延时函数 
{ 
  for(; nCount != 0; nCount--);
} 

int main(void)
{  
  LED_Init();
  while(1)  
  { 
    GPIO_SetBits(GPIOB, GPIO_Pin_14);//set GPIOC.0=1   
    Delay(0x8ffff); 
    GPIO_ResetBits(GPIOB, GPIO_Pin_14);//set GPIOC.0=0   
    Delay(0x8ffff); 
    GPIO_SetBits(GPIOB, GPIO_Pin_15);//set GPIOC.1=1   
    Delay(0x8ffff); 
    GPIO_ResetBits(GPIOB, GPIO_Pin_15);//set GPIOC.1=0   
    Delay(0x8fffe);   
  } 
}