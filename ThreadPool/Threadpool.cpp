//
// Created by jyc on 17-3-11.
//
#include "ThreadPool.h"
#include<unistd.h>

int ThreadPool::bshutdown = 0;
int ThreadPool::cur_num_thread = THREAD_NUM;
Async_queue* ThreadPool::queue = NULL;
std::map<pthread_t,int> ThreadPool::thread_id_map;

ThreadPool::ThreadPool()
{
    bshutdown = 0;
    for(int i=0;i<THREAD_NUM;i++)
    {
        pthread_t new_thread;
        pthread_create(&new_thread, NULL, (void *(*)(void *)) ThreadPool::Process, NULL);
        thread_id_map[new_thread] = 0;
    }
    queue = Async_queue_create();
}

ThreadPool::~ThreadPool()
{
    DestroyPool(2);
}

void ThreadPool::Process()
{
    //线程如果即将关闭
    std::string cmd_str;
    while(true)
    {
        if(1 == thread_id_map[pthread_self()])
        {
            printf("thread %u will exit\n", pthread_self());
            pthread_exit(NULL);
        }

        //线程池如果即将关闭
        if(1 == bshutdown)
        {
            printf("thread %u will exit\n", pthread_self());
            pthread_exit(NULL);
        }
        int res = queue_pop(queue);
            //否则取出一个数据
        //处理得到的数据
        printf("thread %d: %d\n",pthread_self(),res);
    }

}

void ThreadPool::Addwork(int data)
{
    //向队列里面添加新的数据
    if(!bshutdown)
    {
        queue_push(queue,data);
    }
}

void ThreadPool::AddThread()
{
    if(cur_num_thread<=2*THREAD_NUM-2&&!bshutdown)
    {
        for(int i=0;i<=2;i++)
        {
            pthread_t new_thread;
            pthread_create(&new_thread, NULL, (void *(*)(void *)) ThreadPool::Process, NULL);
            thread_id_map[new_thread] = 0;
            cur_num_thread+=THREAD_NUM;
        }
    }
}

void ThreadPool::DeleteThread()
{
    int size = cur_num_thread - THREAD_NUM;
    for(auto iterator = thread_id_map.begin();iterator!=thread_id_map.end();iterator++)
    {
        iterator->second = 1;
    }
}

void ThreadPool::DestroyPool(int iwait)
{
    //如果还有剩余工作没做完，让子弹飞一会儿
    if(!queue_empty(queue))
    {
        sleep(iwait);
    }
    bshutdown = 1;
    void* status;
    //将所有睡觉的线程唤醒
    broadcast(queue);
    for(auto iterator = thread_id_map.begin();iterator!=thread_id_map.end();iterator++)
    {
        pthread_join(iterator->first,&status);
    }
    delete(queue);
    printf("closed pool\n");

}
