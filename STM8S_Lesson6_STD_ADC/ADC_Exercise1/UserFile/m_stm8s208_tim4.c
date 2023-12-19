/*******************************************                                       
*          _____ _    _ _   _              *
*         / ____| |  | | \ | |             *
*        | (___ | |  | |  \| |             *
*         \___ \| |  | | . ` |             *
*         ____) | |__| | |\  |             *
*        |_____/ \____/|_| \_|             *
*                                          * 
********************************************                                                      
*   Tilte:          m_stm8s208_tim4.c      *
*   Author:         Metals                 *
*   Date:           16.3.2023              *
*   Description:    Library for timer4     *
*******************************************/

#include "m_stm8s208_tim4.h"
#include "stm8s.h"

int TIM4_config(void)
{
  TIM4_DeInit();
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER4, ENABLE); //CLK for TIMER2
  /****f = 24.000.000/128 = 187500******
  ************T = 1/f******************
  ***TIM4_Period + 1 = time/T = time x f */
  TIM4_TimeBaseInit(TIM4_PRESCALER_128, 187); //1ms
  TIM4_ARRPreloadConfig(ENABLE); //Auto Reload
  TIM4_ClearFlag(TIM4_FLAG_UPDATE);
  TIM4_ITConfig(TIM4_IT_UPDATE, DISABLE);//Disable Interrupt
  TIM4_Cmd(ENABLE);
  return 0;
}

void delay_ms_TIM4(uint16_t time_delay)
{
  while (time_delay--)
  {
    while (TIM4_GetFlagStatus(TIM4_FLAG_UPDATE) == 0); //wait flag 
    TIM4_ClearFlag(TIM4_FLAG_UPDATE);
  }
}