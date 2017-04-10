//
// Created by jyc on 17-3-10.
//
#include "Async_queue.h"
#include <stdlib.h>
#include <stdio.h>
Async_queue* Async_queue_create()
{
    Async_queue* async_queue = NULL;
    async_queue = (Async_queue*)malloc(sizeof(Async_queue));
    pthread_mutex_init(&async_queue->queue_mutex,NULL);
    pthread_cond_init(&async_queue->queue_cond,NULL);
    async_queue->queue = init_queue();
    return async_queue;
}

void queue_push(Async_queue* async_queue,int data)
{
    if(async_queue == NULL)
    {
        perror("the queue is closed");
        return;
    }
    pthread_mutex_lock(&async_queue->queue_mutex);
    push(async_queue->queue,data);
    pthread_mutex_unlock(&async_queue->queue_mutex);
    if(async_queue->pthread_wait_num>0)
    {
        pthread_cond_signal(&async_queue->queue_cond);
    }
}


int queue_pop(Async_queue* async_queue)
{
    if(async_queue == NULL)
    {
        perror("the queue is closed");
        return NULL;
    }
    pthread_mutex_lock(&async_queue->queue_mutex);
    while(isempty(async_queue->queue))
    {
        async_queue->pthread_wait_num++;
        pthread_cond_wait(&async_queue->queue_cond,&async_queue->queue_mutex);
        async_queue->pthread_wait_num--;
    }
    Node* node = pop(async_queue->queue);
    int temp_data = node->data;
    free(node);
    pthread_mutex_unlock(&async_queue->queue_mutex);
    return temp_data;
}

void broadcast(Async_queue* async_queue)
{
    pthread_cond_broadcast(&async_queue->queue_cond);
}

void delete_queue(Async_queue* async_queue)
{
    if(async_queue == NULL)
        return;
    destroy(async_queue->queue);
    pthread_cond_destroy(&async_queue->queue_cond);
    pthread_mutex_destroy(&async_queue->queue_mutex);
    free(async_queue);
}

int queue_empty(Async_queue* async_queue)
{
    return isempty(async_queue->queue);
}

