/*****************************Exercise 1***************************************/
/***************************Blink LED PD0**************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

/* Private defines -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void delay(uint32_t time);

void main(void)
{
  GPIO_DeInit(GPIOD);
  GPIO_Init(GPIOD, GPIO_PIN_0, GPIO_MODE_OUT_PP_HIGH_FAST); //LED on PORTD, PIN0
  /* Infinite loop */
  while (1)
  {
    GPIO_WriteReverse(GPIOD, GPIO_PIN_0);
    delay(30000);
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

