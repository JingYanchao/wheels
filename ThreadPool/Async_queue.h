//
// Created by jyc on 17-3-10.
//

#ifndef INC_148_ASYNC_QUEUE_H
#define INC_148_ASYNC_QUEUE_H

#endif //INC_148_ASYNC_QUEUE_H
#include "List_queue.h"
#include <pthread.h>

typedef struct Async_queue
{
    pthread_mutex_t queue_mutex;
    pthread_cond_t queue_cond;
    size_t pthread_wait_num;
    List_queue* queue;
}Async_queue;


Async_queue *Async_queue_create();
void queue_push(Async_queue *async_queue, int data);
int queue_pop(Async_queue *async_queue);
void delete_queue(Async_queue *async_queue);
void broadcast(Async_queue *async_queue);
int queue_empty(Async_queue *async_queue);
