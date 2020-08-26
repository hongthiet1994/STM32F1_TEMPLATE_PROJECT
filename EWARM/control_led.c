#include "stm32f10x.h"
#include "control_led.h"

GPIO_InitTypeDef GPIO_InitStructure;

void init_led()
{
   /* GPIOC Periph clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

  /* Configure PD0 and PD2 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void turn_off_led_debug()
{
  GPIO_SetBits(GPIOC,GPIO_Pin_13);
}
void turn_on_led_debug()
{
  GPIO_ResetBits(GPIOC,GPIO_Pin_13);
}
 