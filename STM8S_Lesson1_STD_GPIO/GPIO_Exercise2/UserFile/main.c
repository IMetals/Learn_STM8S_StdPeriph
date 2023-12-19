/********************************Exercise 2************************************/
/*******************On - Off LED follow state of button************************/


/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

/* Private defines -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void delay(uint32_t time);


void main(void)
{
  GPIO_DeInit(GPIOA);
  GPIO_DeInit(GPIOD);
  GPIO_Init(GPIOD, GPIO_PIN_0, GPIO_MODE_OUT_PP_HIGH_FAST);//Output_Push-pull_High_10MHz
  GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_IN_PU_NO_IT);//Input_Pull-up_NoInterrupt
  /* Infinite loop */
  while (1)
  {
    if(GPIO_ReadInputPin(GPIOA,GPIO_PIN_3) == 0x08) //button not press
    {
      GPIO_WriteHigh(GPIOD, GPIO_PIN_0);
    }
    else //press button
    {
      GPIO_WriteLow(GPIOD, GPIO_PIN_0);
      delay(1000);
    }
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
