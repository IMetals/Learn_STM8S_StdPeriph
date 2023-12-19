# NOTE: ALL PROJECT USE STM8S208C8T6 WITH DISCOVERY BOARD. CODE PROGRAMING: IAR Embedded Workbench
See detail in this project: https://github.com/IMetals/Template_IAR_STM8S.git
# Lesson 2: STD_STM8S_CLOCK
## Master clock source
### HSE (high-speed external) clock signal (Max 24MHz)
  - HSE external crystal/ceramic resonator
  - HSE user external clock
### HSI (high-speed internal) clock signal (16MHz RC clock)  
At startup the master clock source is automatically selected as HSI RC clock output divided
by 8 (fHSI/8).
  - Fast wakeup feature
  - Calibration
### LSI (low-speed internal) clock signal (128kHz RC)
For the independent watchdog (IWDG) and auto-wakeup unit (AWU).

## Master clock switching
### System startup
For fast system startup, after a reset the clock controller configures the master clock source
as HSI RC clock output divided by 8 (HSI/8).
### Master clock switching procedures
- Automatic switching
- Manual switching

## Exercise: Create USER LIBRRARY - function config CLOCK HSE & HSI.
Create file *m_stm8s208_clk.c* and *m_stm8s208_clk.h* include FUNCTIONS:
```c
void CLK_CONFIG_16MHZ_HSI(void)
void CLK_CONFIG_24MHZ_HSE(void)
```
Add file to group ***User***
Debug with variable **clk**
```c
clk = CLK_GetClockFreq();
```
1. HSI Clock
Case 1: DIV1
![Imgur](https://imgur.com/eTaCswd.png)
Case 2: DIV2
![Imgur](https://imgur.com/VgZLW3Z.png)
Other: DIV4, DIV8.
2. HSE Clock
![Imgur](https://imgur.com/tmvJIOT.png)
