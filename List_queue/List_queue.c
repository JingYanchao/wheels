//
// Created by jyc on 17-3-11.
//
#include "List_queue.h"
#include <stdlib.h>
#include <stdio.h>

List_queue* init_queue()
{
    List_queue* queue = (List_queue*)malloc(sizeof(List_queue));
    queue->front = queue->tail = NULL;
    return queue;
}

void push(List_queue* queue,int data)
{
    if(queue == NULL)
    {
        perror("push_step:the queue is NULL");
        return;
    }
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if(queue->front == NULL)
    {
        queue->front = queue->tail = node;
    }
    else if(queue->front ==queue->tail)
    {
        queue->tail->next = node;
        queue->tail = queue->tail->next;
        queue->front->next = queue->tail;
    }
    else
    {
        queue->tail->next = node;
        queue->tail = queue->tail->next;
    }
}

Node* pop(List_queue* queue)
{
    if(queue == NULL)
    {
        perror("pop_step:the queue is NULL");
        return NULL;
    }
    if(queue->front == NULL)
    {
        perror("pop_step:the queue is NULL");
        return NULL;
    }
    else if(queue->front == queue->tail)
    {
        Node* tmp = queue->front;
        queue->front = queue->tail = NULL;
        return tmp;
    }
    else
    {
        Node* tmp = queue->front;
        queue->front = queue->front->next;
        return tmp;
    }
}

void destroy(List_queue* queue)
{
    if(queue == NULL)
        return;
    while(queue->front!=queue->tail)
    {
        Node* tmp = queue->front;
        queue->front = queue->front->next;
        free(queue->front);
    }
    free(queue->front);
    free(queue);
}

int isempty(List_queue* queue)
{
    if(queue->front == NULL)
        return 1;
    else
        return 0;
}