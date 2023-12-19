/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "m_stm8s208_clk.h"
/* Private defines -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void delay(uint32_t time);
int GPIO_config(void);
int TIM1_config(void);
int TIM4_config(void);
void delay_ms_TIM4(uint16_t time_delay);

/* Private functions ---------------------------------------------------------*/
void delay(uint32_t time)
{
  while(time--);
}

int GPIO_config(void)
{
  GPIO_DeInit(GPIOD);
  /*Config PD0 as output for LED*/
  GPIO_Init(GPIOD, GPIO_PIN_0, GPIO_MODE_OUT_PP_HIGH_FAST);
  return 0;
}

int TIM1_config(void)
{
  TIM1_DeInit();
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER1, ENABLE); //CLK for TIMER2
  /****f = 24.000.000/24000 = 1000******
  ************T = 1/f******************
  ***TIM2_Period + 1 = time/T = time x f */
  TIM1_TimeBaseInit(23999, TIM1_COUNTERMODE_UP, 1000, 0); //1s
  TIM1_ARRPreloadConfig(ENABLE); //Auto Reload
  TIM1_ClearFlag(TIM1_FLAG_UPDATE);
  TIM1_ITConfig(TIM1_IT_UPDATE, ENABLE);//Enable Interrupt
  TIM1_Cmd(ENABLE);
  return 0;
}

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

void main(void)
{
  while(CLK_CONFIG_24MHZ_HSE());
  while(GPIO_config());
  while(TIM1_config());
  //while(TIM4_config());
  enableInterrupts();
  /* Infinite loop */
  while (1)
  {
    //GPIO_WriteReverse(GPIOD, GPIO_PIN_0);
    //delay_ms_TIM4(500);
  }
  
}



#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
