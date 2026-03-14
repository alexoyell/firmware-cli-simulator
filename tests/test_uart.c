#include "../drivers/uart.h"

int main(void)
{
    uart_init();
    uart_send("Hello UART\n");
    return 0;
}