#include <string.h>
#include "../drivers/uart.h"
#include "shell.h"

int shell_execute(const char *cmd)
{
    if (strcmp(cmd, "HELP") == 0)
    {
        uart_send("Commands: HELP LED_ON LED_OFF TEMP STATUS EXIT\n");
        return 0;
    }
    else if (strcmp(cmd, "LED_ON") == 0)
    {
        uart_send("LED ON OK\n");
        return 0;
    }
    else if (strcmp(cmd, "LED_OFF") == 0)
    {
        uart_send("LED OFF OK\n");
        return 0;
    }
    else if (strcmp(cmd, "TEMP") == 0)
    {
        uart_send("TEMP = 25C\n");
        return 0;
    }
    else if (strcmp(cmd, "STATUS") == 0)
    {
        uart_send("SYSTEM OK\n");
        return 0;
    }
    else if (strcmp(cmd, "EXIT") == 0)
    {
        uart_send("Bye\n");
        return 1;
    }
    else
    {
        uart_send("Unknown command\n");
        return 0;
    }
}