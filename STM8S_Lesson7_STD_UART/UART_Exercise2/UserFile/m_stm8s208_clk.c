/*******************************************                                       
*          _____ _    _ _   _              *
*         / ____| |  | | \ | |             *
*        | (___ | |  | |  \| |             *
*         \___ \| |  | | . ` |             *
*         ____) | |__| | |\  |             *
*        |_____/ \____/|_| \_|             *
*                                          * 
********************************************                                                      
*   Tilte:          m_stm8s208_clk.c       *
*   Author:         Metals                 *
*   Date:           16.3.2023              *
*   Description:    Library for clock stm8s*
*******************************************/

#include "m_stm8s208_clk.h"
#include "stm8s_clk.h"

int CLK_CONFIG_16MHZ_HSI(void)
{
    CLK_DeInit();
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
    return 0;
}

int CLK_CONFIG_24MHZ_HSE(void)
{
    CLK_DeInit();
    /*Enable HSE and wait HSE ready*/
    CLK_HSECmd(ENABLE);
    while (CLK_GetFlagStatus(CLK_FLAG_HSERDY) != SET);
    /*Switch CLK Source to HSE and Disable HSI (Auto Mode)*/
    CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSE, DISABLE/*Interrupt event*/, CLK_CURRENTCLOCKSTATE_DISABLE/*off old clk source*/);
    while(CLK_GetSYSCLKSource() != CLK_SOURCE_HSE);
    /*Stop clock switch*/
    CLK_ClockSwitchCmd(DISABLE);
    /*Prescale*/
    CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1); /*Fcpu = Fmaster*/
    return 0;
}
