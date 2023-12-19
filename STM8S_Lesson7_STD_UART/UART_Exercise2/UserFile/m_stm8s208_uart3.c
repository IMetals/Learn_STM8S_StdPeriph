/*******************************************
*          _____ _    _ _   _              *
*         / ____| |  | | \ | |             *
*        | (___ | |  | |  \| |             *
*         \___ \| |  | | . ` |             *
*         ____) | |__| | |\  |             *
*        |_____/ \____/|_| \_|             *
*                                          *
********************************************
*   Tilte:          m_stm8s208_uart3.c     *
*   Author:         Metals                 *
*   Date:           17.3.2023              *
*   Description:    Library for uart3      *
*******************************************/

#include "m_stm8s208_uart3.h"
#include "stm8s.h"

int m_uart3_configuration(void)
{
   UART3_DeInit();
   UART3_Init((u32)9600, UART3_WORDLENGTH_8D, UART3_STOPBITS_1, UART3_PARITY_NO, UART3_MODE_TXRX_ENABLE);
   UART3_Cmd(ENABLE);
   return 0;
}

void m_uart3_send_string(char *str)
{
   char *ch = str;
   while (*ch)
   {
      UART3_SendData8((unsigned char) *ch);
      while (UART3_GetFlagStatus(UART3_FLAG_TXE) == RESET);
      ch++;
   }
}
