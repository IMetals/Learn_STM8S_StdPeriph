/*******************************************
*          _____ _    _ _   _              *
*         / ____| |  | | \ | |             *
*        | (___ | |  | |  \| |             *
*         \___ \| |  | | . ` |             *
*         ____) | |__| | |\  |             *
*        |_____/ \____/|_| \_|             *
*                                          *
********************************************
*   Tilte:          m_stm8s208_uart1.c     *
*   Author:         Metals                 *
*   Date:           17.3.2023              *
*   Description:    Library for uart4      *
*******************************************/

#include "m_stm8s208_uart1.h"
#include "stm8s.h"

int m_uart1_configuration(void)
{
   UART1_DeInit();
   UART1_Init((u32)9600, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
   UART1_Cmd(ENABLE);
   return 0;
}
