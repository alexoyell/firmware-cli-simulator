#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#define RB_SIZE 256

typedef struct
{
    char data[RB_SIZE];
    int head; //下次寫入位置
    int tail; //下次讀取位置
    int count; //目前有幾個
} RingBuffer;

void rb_init(RingBuffer *rb); //初始化
int rb_is_empty(RingBuffer *rb); //判斷是否為空
int rb_is_full(RingBuffer *rb); //判斷滿了沒
int rb_push(RingBuffer *rb, char c); //往裡面放
int rb_pop(RingBuffer *rb, char *c); //從裡面拿

#endif