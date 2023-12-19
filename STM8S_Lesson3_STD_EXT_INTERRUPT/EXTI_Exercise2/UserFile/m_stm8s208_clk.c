#include "m_stm8s208_clk.h"
#include "stm8s_clk.h"

void CLK_CONFIG_16MHZ_HSI(void)
{
    CLK_DeInit();
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
}

void CLK_CONFIG_24MHZ_HSE(void)
{
    CLK_DeInit();
    CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV2);
    CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSE, DISABLE, CLK_CURRENTCLOCKSTATE_DISABLE);
}
