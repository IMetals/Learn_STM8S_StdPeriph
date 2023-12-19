/*******************************************                                       
*          _____ _    _ _   _              *
*         / ____| |  | | \ | |             *
*        | (___ | |  | |  \| |             *
*         \___ \| |  | | . ` |             *
*         ____) | |__| | |\  |             *
*        |_____/ \____/|_| \_|             *
*                                          * 
********************************************                                                      
*   Tilte:          m_stm8s208_adc2.c      *
*   Author:         Metals                 *
*   Date:           16.3.2023              *
*   Description:    Library for adc2 stm8s *
*******************************************/

#include "m_stm8s208_adc2.h"
#include "stm8s_adc2.h"

int ADC2_config(void)
{
   ADC2_DeInit();
   /*ADC2_Pressel_FCPU fast --> more power and less exactly*/
   ADC2_Init(ADC2_CONVERSIONMODE_SINGLE, ADC2_CHANNEL_0,
         ADC2_PRESSEL_FCPU_D18, ADC2_EXTTRIG_TIM, DISABLE, ADC2_ALIGN_RIGHT,
         ADC2_SCHMITTTRIG_CHANNEL0, DISABLE);
   /*ADC2 End of conversasion Interrupt*/
   ADC2_ITConfig(DISABLE);
   ADC2_Cmd(ENABLE);
   return 0;
}