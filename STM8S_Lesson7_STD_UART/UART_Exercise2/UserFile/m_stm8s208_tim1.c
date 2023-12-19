/*******************************************                                       
*          _____ _    _ _   _              *
*         / ____| |  | | \ | |             *
*        | (___ | |  | |  \| |             *
*         \___ \| |  | | . ` |             *
*         ____) | |__| | |\  |             *
*        |_____/ \____/|_| \_|             *
*                                          * 
********************************************                                                      
*   Tilte:          m_stm8s208_tim1.c      *
*   Author:         Metals                 *
*   Date:           16.3.2023              *
*   Description:    Library for timer1     *
*******************************************/

#include "m_stm8s208_tim1.h"
#include "stm8s.h"

int TIM1_config(void)
{
  TIM1_DeInit();
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER1, ENABLE); //CLK for TIMER2
  /****f = 24.000.000/24000 = 1000******
  ************T = 1/f******************
  ***TIM1_Period + 1 = time/T = time x f */
  TIM1_TimeBaseInit(2399, TIM1_COUNTERMODE_UP, 200, 0); //20ms
  TIM1_ARRPreloadConfig(ENABLE); //Auto Reload
  TIM1_ClearFlag(TIM1_FLAG_UPDATE);
  TIM1_ITConfig(TIM1_IT_UPDATE, ENABLE);//Enable Interrupt
  TIM1_Cmd(ENABLE);
  return 0;
}

int TIM1_PWM_Configuration(void)
{
  TIM1_DeInit();
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER1, ENABLE);
  TIM1_TimeBaseInit(2399, TIM1_COUNTERMODE_UP, 200, 0); //20ms
  /*Config mode PWM1, TIM1_CH1 duty 20%, Disable TIM1_CH1N*/
  TIM1_OC4Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, 0, TIM1_OCPOLARITY_HIGH, TIM1_OCIDLESTATE_SET);

  TIM1_ARRPreloadConfig(ENABLE);
  TIM1_OC4PreloadConfig(ENABLE); //Enable reload at mode Output Compare - TIM1_CMMR1
  TIM1_Cmd(ENABLE);
  TIM1_CtrlPWMOutputs(ENABLE);
  return 0;
}