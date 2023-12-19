# NOTE: ALL PROJECT USE STM8S208C8T6 WITH DISCOVERY BOARD. CODE PROGRAMING: IAR Embedded Workbench
See detail in this project: https://github.com/IMetals/Template_IAR_STM8S.git
# Lesson 5: STD_STM8S_PWM
## Introduce
Pulse width modulation mode allows you to generate a signal with a frequency determined by the value of the TIM1_ARR register and a duty cycle determined by the value of the
TIM1_CCRi registers.  
![Imgur](https://imgur.com/GZL4iPM.png)

## Exercise 1: Config Timer 1 Channel 1 (TIM1_CH1) set PWM with period T = 20ms (f = 50Hz) and Duty cycle = 50%
First step: config timer 1 use pwm 
```c
int TIM1_PWM_Configuration(void)
{
  TIM1_DeInit();
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER1, ENABLE);
  TIM1_TimeBaseInit(2399, TIM1_COUNTERMODE_UP, 200, 0); //20ms
  /*Config mode PWM1, TIM1_CH1 duty 20%, Disable TIM1_CH1N*/
  TIM1_OC4Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, 0, TIM1_OCPOLARITY_HIGH, TIM1_OCIDLESTATE_SET);

  TIM1_ARRPreloadConfig(ENABLE);
  TIM1_OC4PreloadConfig(ENABLE); //Enable reload at mode Output Compare - TIM1_CMMR1
  TIM1_Cmd(ENABLE);
  TIM1_CtrlPWMOutputs(ENABLE);
  return 0;
}
```
Now, can change duty cycle with function:      
```c
TIM1_SetCompare4(100); //50%
```
Result:
![Imgur](https://imgur.com/BP5eTBC.png)

## Exercise 2: Control Servo motor SG90 use PWM
Check datasheet to known how to control this servo
Feature:
1. Tiny and lightweight with high output power. Servo can rotate approximately 180 degrees (90 in each direction)
2. Position "0" (1.5 ms pulse) is middle, "90" (~2ms pulse) is all the way to the right, "-90" (~1ms pulse) is all the way to the left.  
![Imgur](https://imgur.com/ghiVt4H.png)  
***The pulse width values for different angular positions of this servo are provided in the table below. Remember that the repetition rate of the pulse should be 50 Hz (period of 20 ms).***  
![Imgur](https://imgur.com/SKZOJlF.png)  
Use function created above, in while loop main.c, write code below
```c
  while (1)
  {
    TIM1_SetCompare4(7);
    delay_ms_TIM4(1000);
    TIM1_SetCompare4(23);
    delay_ms_TIM4(1000);
  }
```

This code will control Servo motor rotate 0 - 180 degree, Frequency f = 0.5Hz  
