#include "ring_buffer.h"

void rb_init(RingBuffer *rb)
{
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

int rb_is_empty(RingBuffer *rb)
{
    return rb->count == 0;
}

int rb_is_full(RingBuffer *rb)
{
    return rb->count == RB_SIZE;
}

int rb_push(RingBuffer *rb, char c)
{
    if (rb_is_full(rb))
    {
        return -1;
    }

    rb->data[rb->head] = c;
    rb->head = (rb->head + 1) % RB_SIZE;
    rb->count++;

    return 0;
}

int rb_pop(RingBuffer *rb, char *c)
{
    if (rb_is_empty(rb))
    {
        return -1;
    }

    *c = rb->data[rb->tail];
    rb->tail = (rb->tail + 1) % RB_SIZE;
    rb->count--;

    return 0;
}