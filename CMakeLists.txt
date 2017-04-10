cmake_minimum_required(VERSION 3.7)
project(wheels)

set(CMAKE_CXX_STANDARD 11)

add_executable(Rbtree Rbtree/rbtree_test.cpp
        Rbtree/Rbtree.cpp Rbtree/Rbtree.h)

add_executable(List_queue List_queue/test_queue.c
        List_queue/List_queue.c List_queue/List_queue.h)

add_executable(Async_queue Async_queue/test.c
        Async_queue/Async_queue.c Async_queue/Async_queue.h
        Async_queue/List_queue.c Async_queue/List_queue.h)

add_executable(ThreadPool ThreadPool/test_threadpool.cpp
        ThreadPool/Threadpool.cpp ThreadPool/ThreadPool.h
        ThreadPool/Async_queue.c ThreadPool/Async_queue.h
        ThreadPool/List_queue.c ThreadPool/List_queue.h)

add_executable(Process_lock Process_lock/test_lock.c
        Process_lock/Process_lock.c Process_lock/Process_lock.h)