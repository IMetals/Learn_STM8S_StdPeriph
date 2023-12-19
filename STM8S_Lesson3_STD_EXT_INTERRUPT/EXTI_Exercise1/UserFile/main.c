/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "m_stm8s208_clk.h"
/* Private defines -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void delay(uint32_t time);

//uint8_t prior1 = 10;
//uint8_t prior2 = 10;

void main(void)
{
  CLK_CONFIG_24MHZ_HSE();
  /*Config PD0 as output for LED*/
  GPIO_Init(GPIOD, GPIO_PIN_0, GPIO_MODE_OUT_PP_HIGH_FAST);

  /*Config PA3, PD7 as input PULL UP for EXTI*/
  GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_IN_PU_IT);
  GPIO_Init(GPIOD, GPIO_PIN_7, GPIO_MODE_IN_PU_IT);
  EXTI_DeInit();
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOA, EXTI_SENSITIVITY_FALL_ONLY);
  EXTI_SetTLISensitivity(EXTI_TLISENSITIVITY_FALL_ONLY);
  /*Note: PD7 is TLI, use INTERRUPT_HANDLER(TLI_IRQHandler, 0)*/
  
  enableInterrupts();
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
