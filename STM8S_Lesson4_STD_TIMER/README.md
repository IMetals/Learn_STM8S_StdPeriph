# NOTE: ALL PROJECT USE STM8S208C8T6 WITH DISCOVERY BOARD. CODE PROGRAMING: IAR Embedded Workbench
See detail in this project: https://github.com/IMetals/Template_IAR_STM8S.git
# Lesson 4: STD_STM8S_TIMER
## Overview
three different timer types: 
Advanced control (TIM1)  
general purpose (TIM2/TIM3/TIM5)  
basic timers (TIM4/TIM6).
## Timer feature comparison
![Imgur](https://imgur.com/EMTj5Sp.png)
## How to calculate
FCK_CLK = FCK_PSC/(PSC+1)
- FCK_CLK: wanted frequency
- FCK_PSC: clock use for timer
- PSC: prescaler register of timer

## Exercise 1: Create delay_ms_TIM4() function. Write program blink LED with frequency f = 1Hz.
First, need create TIM4_config() function to Initilize Timer 4.
```c
int TIM4_config(void)
{
  TIM4_DeInit();
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER4, ENABLE); //CLK for TIMER2
  /****f = 24.000.000/128 = 187500******
  ************T = 1/f******************
  ***TIM4_Period + 1 = time/T = time x f = 1e-3 * 187500 */
  TIM4_TimeBaseInit(TIM4_PRESCALER_128, 187); //1ms
  TIM4_ARRPreloadConfig(ENABLE); //Auto Reload
  TIM4_ClearFlag(TIM4_FLAG_UPDATE);
  TIM4_ITConfig(TIM4_IT_UPDATE, DISABLE);//Disable Interrupt
  TIM4_Cmd(ENABLE);
  return 0;
}
```
This exercise not use Interrupt timer.
Write delay_ms_TIM4() function
```c
void delay_ms_TIM4(uint16_t time_delay)
{
  while (time_delay--)
  {
    while (TIM4_GetFlagStatus(TIM4_FLAG_UPDATE) == 0); //wait flag 
    TIM4_ClearFlag(TIM4_FLAG_UPDATE);
  }
}
```
Result:
Use Logic Analyzer to view pulse of PD0:
![Imgur](https://imgur.com/x5XrUIe.png)

## Exercise 2: Write program blink LED with frequency f = 0.5Hz use TIMER1 Interrupt
First, need create TIM1_config() function to Initilize Timer 1.
```c
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
```
Write program in Interrupt function
```c
INTERRUPT_HANDLER(TIM1_UPD_OVF_TRG_BRK_IRQHandler, 11)
{
    if(TIM1_GetITStatus(TIM1_IT_UPDATE))
    {
      GPIO_WriteReverse(GPIOD, GPIO_PIN_0);
      TIM1_ClearITPendingBit(TIM1_IT_UPDATE);
    }
}
```
Result:
![Imgur](https://imgur.com/DE0uRlD.png)