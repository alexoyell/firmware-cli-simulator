#include <stdio.h>
#include <string.h>
#include "drivers/uart.h"
#include "kernel/ring_buffer.h"
#include "app/shell.h"

int main(void)
{
    RingBuffer rb;
    char input[128];
    char cmd[128];
    char ch;//ring_buffer 是一個字元一個字元取出
    int cmd_index;
    int should_exit;

    uart_init();
    rb_init(&rb);

    uart_send("MCU Firmware Boot\n");

    while (1)
    {
        printf("> ");

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }

        for (int i = 0; input[i] != '\0'; i++)
        {
            rb_push(&rb, input[i]);
        }

        cmd_index = 0;
        while (!rb_is_empty(&rb))
        {
            if (rb_pop(&rb, &ch) != 0)
            {
                break;
            }

            if (ch == '\n' || ch == '\r')
            {
                break;
            }

            if (cmd_index < (int)sizeof(cmd) - 1)
            {
                cmd[cmd_index++] = ch;
            }
        }

        cmd[cmd_index] = '\0';

        if (strlen(cmd) == 0)
        {
            continue;
        }

        should_exit = shell_execute(cmd);
        if (should_exit)
        {
            break;
        }
    }

    return 0;
}