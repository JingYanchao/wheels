//
// Created by jyc on 17-3-11.
//
#include <zconf.h>
#include "ThreadPool.h"
int main()
{
    ThreadPool pool;
    int i = 1;
    while(1)
    {
        sleep(0.1);
        pool.Addwork(i);
    }
}
