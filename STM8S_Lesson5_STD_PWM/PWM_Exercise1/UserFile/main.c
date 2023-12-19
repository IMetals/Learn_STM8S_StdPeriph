/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "m_stm8s208_clk.h"
#include "m_stm8s208_tim1.h"
#include "m_stm8s208_tim4.h"
/* Private defines -----------------------------------------------------------*/
/* Variable ------------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
int GPIO_config(void);

/* Private functions ---------------------------------------------------------*/
int GPIO_config(void)
{
  GPIO_DeInit(GPIOD);
  /*Config PD0 as output for LED*/
  GPIO_Init(GPIOD, GPIO_PIN_0, GPIO_MODE_OUT_PP_HIGH_FAST);
  return 0;
}


void main(void)
{
  while(CLK_CONFIG_24MHZ_HSE());
  //while(GPIO_config());
  while(TIM4_config());
  while(TIM1_PWM_Configuration());
  //TIM1_SetCompare4(100);
  /* Infinite loop */
  while (1)
  {
    TIM1_SetCompare4(7);
    delay_ms_TIM4(1000);
    TIM1_SetCompare4(23);
    delay_ms_TIM4(1000);
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
