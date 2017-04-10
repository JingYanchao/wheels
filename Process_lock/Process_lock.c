//
// Created by jyc on 17-3-11.
//
#include "Process_lock.h"
#include <assert.h>
#include <sys/mman.h>
#include <stdio.h>
#include <memory.h>
#include <errno.h>

int init_process_mutex()
{
    pthread_mutexattr_t attr;
    process_lock = mmap(NULL,sizeof(pthread_mutex_t),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
    if(process_lock == MAP_FAILED)
    {
        perror("mmap error");
    }
    (void) pthread_mutexattr_init(&attr);
    if (pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED) != 0)
    {
        (void) pthread_mutexattr_destroy(&attr);
        return ERROR;
    }
    (void) pthread_mutex_init(process_lock, &attr);
    (void) pthread_mutexattr_destroy(&attr);
    return OK;
}

int trylock_process_mutex()
{
    int err;
    assert(!mutex_held);
    err = pthread_mutex_trylock(process_lock);
    if(err == 0)
    {
        mutex_held = 1;
        return OK;
    }
    else if(err == EBUSY)
    {
        return BUSY;
    }
    else
    {
        return ERROR;
    }

}

int unlock_process_mutex()
{
    int err;

    assert(mutex_held);

    err = pthread_mutex_unlock(process_lock);
    if (err != 0)
    {
        return ERROR;
    }
    mutex_held = 0;
    return OK;
}
