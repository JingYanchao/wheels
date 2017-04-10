//
// Created by jyc on 17-3-11.
//

#ifndef PROCESS_LOCK_PROCESS_LOCK_H
#define PROCESS_LOCK_PROCESS_LOCK_H

#endif //PROCESS_LOCK_PROCESS_LOCK_H
#include <pthread.h>

#define OK      0
#define ERROR   -1
#define BUSY   1
#define AGAIN   EAGAIN

pthread_mutex_t* process_lock;
static int mutex_held = 0;

int init_process_mutex();
int trylock_process_mutex();
int unlock_process_mutex();



