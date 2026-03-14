#include <stdio.h>
#include "uart.h"

void uart_init(void)
{
    printf("[UART] Init done\n");
}

void uart_send(const char *msg)
{
    printf("%s", msg);
}