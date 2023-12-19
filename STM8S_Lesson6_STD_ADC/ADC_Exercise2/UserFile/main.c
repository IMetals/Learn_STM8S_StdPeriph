/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "m_stm8s208_clk.h"
#include "m_stm8s208_tim4.h"

/* Private defines -----------------------------------------------------------*/
/* Variable ------------------------------------------------------------------*/
volatile uint16_t adc_value = 0;
/* Private function prototypes -----------------------------------------------*/
int GPIO_config(void);
int ADC2_config(void);

/* Private functions ---------------------------------------------------------*/
int GPIO_config(void)
{
   GPIO_DeInit(GPIOD);
   /*Config PD0 as output for LED*/
   GPIO_Init(GPIOD, GPIO_PIN_0, GPIO_MODE_OUT_PP_HIGH_FAST);
   /*Init GPIO for ADC IN0*/
   GPIO_Init(GPIOB, GPIO_PIN_0, GPIO_MODE_IN_FL_NO_IT);
   return 0;
}

int ADC2_config(void)
{
   ADC2_DeInit();
   /*ADC2_Pressel_FCPU fast --> more power and less exactly*/
   ADC2_Init(ADC2_CONVERSIONMODE_CONTINUOUS, ADC2_CHANNEL_0,
         ADC2_PRESSEL_FCPU_D18, ADC2_EXTTRIG_TIM, DISABLE, ADC2_ALIGN_RIGHT,
         ADC2_SCHMITTTRIG_CHANNEL0, DISABLE);
   /*ADC2 End of conversasion Interrupt*/
   ADC2_ITConfig(ENABLE);
   enableInterrupts();
   ADC2_StartConversion();
   return 0;
}

void main(void)
{
   while (CLK_CONFIG_24MHZ_HSE());
   while (TIM4_config());
   while (GPIO_config());
   while (ADC2_config());
   /* Infinite loop */
   while (1)
   {
      GPIO_WriteReverse(GPIOD, GPIO_PIN_0);
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
