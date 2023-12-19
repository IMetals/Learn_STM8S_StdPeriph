/*******************************************                                       
*          _____ _    _ _   _              *
*         / ____| |  | | \ | |             *
*        | (___ | |  | |  \| |             *
*         \___ \| |  | | . ` |             *
*         ____) | |__| | |\  |             *
*        |_____/ \____/|_| \_|             *
*                                          * 
********************************************                                                      
*   Tilte:          m_stm8s208_tim2.c      *
*   Author:         Metals                 *
*   Date:           16.3.2023              *
*   Description:    Library for timer2     *
*******************************************/
#include "m_stm8s208_tim2.h"
#include "stm8s.h"

int TIM2_config(void)
{
  TIM2_DeInit();
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER2, ENABLE); //CLK for TIMER2
  /****f = 24.000.000/512 = 46875******
  ************T = 1/f******************
  ***TIM2_Period + 1 = time/T = time x f */
  TIM2_TimeBaseInit(TIM2_PRESCALER_512, 46874); //1s
  TIM2_ARRPreloadConfig(ENABLE); //Auto Reload
  TIM2_ClearFlag(TIM2_FLAG_UPDATE);
  TIM2_ITConfig(TIM2_IT_UPDATE, ENABLE);//Enable Interrupt
  TIM2_Cmd(ENABLE);
  return 0;
}