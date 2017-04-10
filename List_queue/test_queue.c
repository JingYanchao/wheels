//
// Created by jyc on 17-3-11.
//
#include "List_queue.h"
#include <stdio.h>
int main()
{
    int i;
    List_queue* queue = init_queue();
//    for(i=1;i<10;i++)
//    {
//        push(queue,i);
//    }
    Node* node;
    node = pop(queue);
    printf("%d",node->data);
    node = pop(queue);
    printf("%d",node->data);
    node = pop(queue);
    printf("%d",node->data);
    destroy(queue);
}

