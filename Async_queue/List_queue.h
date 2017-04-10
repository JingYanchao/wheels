//
// Created by jyc on 17-3-11.
//

#ifndef ASYNC_QUEUE_LIST_QUEUE_H
#define ASYNC_QUEUE_LIST_QUEUE_H

#endif //ASYNC_QUEUE_LIST_QUEUE_H
typedef struct Node
{
    int data;
    struct Node* next;
}Node;

typedef struct List_queue
{
    Node* front;
    Node* tail;
}List_queue;

List_queue* init_queue();
void push(List_queue* queue,int data);
Node* pop(List_queue* queue);
void destroy(List_queue* queue);
int isempty(List_queue* queue);

