# NOTE: ALL PROJECT USE STM8S208C8T6 WITH DISCOVERY BOARD. CODE PROGRAMING: IAR Embedded Workbench
See detail in this project: https://github.com/IMetals/Template_IAR_STM8S.git
# Lesson1: STD_STM8S_GPIO
## GPIO Main Feature:
• Selectable input modes: floating input or input with pull-up  
• Selectable output modes: push-pull output or pseudo-open-drain  
• External interrupts can be enabled and disabled individually  
## Function in ST Library
- GPIO_Init(x1,x2,x3)
- GPIO_Write(x1,x2)
- GPIO_WriteHigh(x1,x2)
- GPIO_WriteLow(x1,x2)
- GPIO_WriteReverse(x1,x2)
- GPIO_ReadOutputData(x1)
- GPIO_ReadInputData(x1)
- GPIO_ReadInputPin(x1,x2)

## Exercise 1: Blink LED PD0
***GPIO_Exercise1***  
This Project will Blink LED **Port D pin 0** on STM8S Discovery board (Relative Frequency) 

## Exercise 2: On/off LED PD0 follow button on PIN PA3
***GPIO_Exercise2***
LED PD0 will ON if button at pin PA3 pressed.
External Hardware  
![Imgur](https://imgur.com/r4h78al.png)  
