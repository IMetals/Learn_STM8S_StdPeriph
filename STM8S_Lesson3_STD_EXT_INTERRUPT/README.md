# NOTE: ALL PROJECT USE STM8S208C8T6 WITH DISCOVERY BOARD. CODE PROGRAMING: IAR Embedded Workbench
See detail in this project: https://github.com/IMetals/Template_IAR_STM8S.git
# Lesson 3: STD_STM8S_EXT_INTERRUPT
## Introduce
Nested or concurrent interrupt management with flexible interrupt priority and level
management:  
– Up to 4 software programmable nesting levels  
– Up to 32 interrupt vectors fixed by hardware  
– 2 non maskable events: RESET, TRAP  
– 1 non-maskable top level hardware interrupt (TLI)  
Management of software interrupt (TRAP)  
## Interrupt masking
The interrupt masking is managed by bits I1 and I0 of the CCR register and by the
ITC_SPRx registers which set the software priority level of each interrupt vector
![Imgur](https://imgur.com/T5tjEBy.png)
## Vector Ext.Interrupt
5 lines on Port A: PA[6:2].  
8 lines on Port C:PB[7:0].  
8 lines on Port C: PC[7:0].  
7 lines on Port D: PD[6:0].  
8 lines on Port E : PE[7:0].  
PD7 is the Top Level Interrupt source (TLI), except for 20-pin packages on which the Top
Level Interrupt source (TLI) can be available on the PC3 pin using an alternate function
remapping option bit. Refer to option bytes section in the product datasheet for more details.

## Exercise 1: Use External Interrupt on PA3 and PD7 (TLI). When press button PA3 --> LED High and press button PD7 --> LED Low.
First, config PD0 (LED) as output and PA3, PD7 as input PULL UP for External Interrupt. Then config EXTI Sensitivity on PORTA and TLI. Need use function enableInterrupts().
```c
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
  ```

In file stm8s_it.c, edit in function INTERRUPT_HANDLER(EXTI_PORTA_IRQHandler, 3) and INTERRUPT_HANDLER(TLI_IRQHandler, 0)
```c
INTERRUPT_HANDLER(TLI_IRQHandler, 0)
{
  if(GPIO_ReadInputPin(GPIOD, GPIO_PIN_7) == 0)
  {
    GPIO_WriteLow(GPIOD, GPIO_PIN_0);
  }
}

INTERRUPT_HANDLER(EXTI_PORTA_IRQHandler, 3)
{
  if(GPIO_ReadInputPin(GPIOA, GPIO_PIN_3) == 0)
  {
    GPIO_WriteHigh(GPIOD, GPIO_PIN_0);
  }
}
 ```

Can use breakpoint to debug program.

## Exercise 2: Use External Interrupt on PA3 and PA4. When press button PA3 --> LED High and press button PA4 --> LED Low.
Config same as exercise 1. But in function INTERRUPT_HANDLER(EXTI_PORTA_IRQHandler, 3) will write as below:
```c
INTERRUPT_HANDLER(EXTI_PORTA_IRQHandler, 3)
{
  if(GPIO_ReadInputPin(GPIOA, GPIO_PIN_3) == 0)
  {
    GPIO_WriteHigh(GPIOD, GPIO_PIN_0);
  }
  if(GPIO_ReadInputPin(GPIOA, GPIO_PIN_4) == 0)
  {
    GPIO_WriteLow(GPIOD, GPIO_PIN_0);
  }
}
```

## Exercise 3: Use External Interrupt on PA3 and PB3. When press button PA3 --> LED High and press button PB3 --> LED Low. Condition: priority on pin PB3 is higher than pin PA3.
Default: In table Interrupt mapping: EXTI port A will higher than port B.
We can change software priority to priority on pin PB3 is higher than pin PA3. (Use file stm8s_itc.c)
```c
  ITC_SetSoftwarePriority(ITC_IRQ_PORTA, ITC_PRIORITYLEVEL_1);
  ITC_SetSoftwarePriority(ITC_IRQ_PORTB, ITC_PRIORITYLEVEL_2);
  ```

Results:
![Imgur](https://imgur.com/xSS2b7a.png)
Before config: priority on port A same as port B. [I1I0] = 0x11 --> Level 3 (Highest).
At this time, EXTI port A will higher than port B (Fixed Hardware).

After config: priority on port A [I1I0] = 0x01 --> Level 1. Priority on port B [I1I0] = 0x00 --> Level 2. Priority on pin PB3 is higher than pin PA3.