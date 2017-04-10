//
// Created by jyc on 17-3-10.
//
#include "Async_queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <zconf.h>

Async_queue* queue;
void routing1()
{
    int i=1;
    while(1)
    {
        sleep(1);
        i++;
        queue_push(queue,i);
    }

};

void routing2()
{
    while(1)
    {
        int tmp = queue_pop(queue);
        printf("%d:%d\n",pthread_self(),tmp);
    }

}

void routing3()
{
    while(1)
    {
        int tmp = queue_pop(queue);
        printf("%d:%d\n",pthread_self(),tmp);
    }

}

int main()
{
    pthread_t tid1;
    pthread_t tid2;
    queue = Async_queue_create();
    pthread_create(&tid1, NULL, (void *(*)(void *)) routing1, NULL);
    pthread_create(&tid2, NULL, (void *(*)(void *)) routing2, NULL);
    pthread_create(&tid2, NULL, (void *(*)(void *)) routing3, NULL);
    while(1)
    {
        sleep(1);
    }

}

