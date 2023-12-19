/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "m_stm8s208_clk.h"
/* Private defines -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void delay(uint32_t time);

uint8_t prior1_pre = 10;
uint8_t prior2_pre = 10;
uint8_t prior1 = 10;
uint8_t prior2 = 10;

void main(void)
{
  CLK_CONFIG_24MHZ_HSE();
  /*Config PD0 as output for LED*/
  GPIO_Init(GPIOD, GPIO_PIN_0, GPIO_MODE_OUT_PP_HIGH_FAST);

  /*Config PA3 as input PULL UP for EXTI*/
  GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_IN_PU_IT);
  GPIO_Init(GPIOB, GPIO_PIN_3, GPIO_MODE_IN_PU_IT);
  EXTI_DeInit();
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOA, EXTI_SENSITIVITY_FALL_ONLY);
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOB, EXTI_SENSITIVITY_FALL_ONLY);
  
  prior1_pre = ITC_GetSoftwarePriority(ITC_IRQ_PORTA);
  prior2_pre = ITC_GetSoftwarePriority(ITC_IRQ_PORTB);
  
  ITC_SetSoftwarePriority(ITC_IRQ_PORTA, ITC_PRIORITYLEVEL_1);
  ITC_SetSoftwarePriority(ITC_IRQ_PORTB, ITC_PRIORITYLEVEL_2);
  
  enableInterrupts();
  
  prior1 = ITC_GetSoftwarePriority(ITC_IRQ_PORTA);
  prior2 = ITC_GetSoftwarePriority(ITC_IRQ_PORTB);
  /* Infinite loop */
  while (1)
  {
  }
  
}

void delay(uint32_t time)
{
  while(time--);
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
