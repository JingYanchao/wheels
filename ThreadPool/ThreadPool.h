//
// Created by jyc on 17-3-11.
//

#ifndef ASYNC_QUEUE_THREADPOOL_H
#define ASYNC_QUEUE_THREADPOOL_H

#endif //ASYNC_QUEUE_THREADPOOL_H
const int THREAD_NUM = 5;
//extern "C"
//{
    #include "Async_queue.h"
//}
#include <pthread.h>
#include <string>
#include<deque>
#include <map>


class ThreadPool
{
public:
    ThreadPool();
    ~ThreadPool();
    static int cur_num_thread;
    static int bshutdown;
    static Async_queue* queue;
    void Addwork(int data);
    void DestroyPool(int iwait);
    void AddThread();
    void DeleteThread();
    static void Process();
    static std::map<pthread_t,int> thread_id_map;
};

