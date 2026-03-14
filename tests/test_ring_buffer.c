#include <stdio.h>
#include "../kernel/ring_buffer.h"

int main(void)
{
    RingBuffer rb;
    char ch;

    rb_init(&rb);

    rb_push(&rb, 'A');
    rb_push(&rb, 'B');
    rb_push(&rb, 'C');

    while (!rb_is_empty(&rb))
    {
        if (rb_pop(&rb, &ch) == 0)
        {
            printf("%c\n", ch);
        }
    }

    return 0;
}