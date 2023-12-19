/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "m_stm8s208_clk.h"
/* Private defines -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void delay(uint32_t time);

uint32_t clk = 0;

void main(void)
{
  //CLK_CONFIG_16MHZ_HSI();
  //CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV2);
  CLK_CONFIG_24MHZ_HSE();
  //CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV2);
  clk = CLK_GetClockFreq();

  while (1)
  {
  }
}

void delay(uint32_t time)
{
  while (time--)
    ;
}

#ifdef USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *   where the assert_param error has occurred.
 * @param file: pointer to the source file name
 * @param line: assert_param error line source number
 * @retval : None
 */
void assert_failed(u8 *file, u32 line)
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
