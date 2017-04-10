//
// Created by jyc on 17-3-11.
//
#include "Process_lock.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
int main()
{
    int i;
    pid_t pid;
    init_process_mutex();
    int* count = mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
    for(i=0;i<5;i++)
    {
        pid = fork();
        if(pid>0)
        {
            sleep(0.5);
        }
        else if(pid ==0)
        {
            break;
        }
        else
        {
            perror("fork is failed");
        }
    }
    if(pid>0)
    {
        sleep(1);
        trylock_process_mutex();
        printf("%d\n",*count);
        unlock_process_mutex();

    }
    else
    {
        trylock_process_mutex();
        int flag = 10;
        while(flag>0&&*count<20)
        {
            (*count) = (*count)+1;
            flag--;
        }
        unlock_process_mutex();
    }
}