/*
============================================================================
Name : 29.c
Author : ANKIT SHARMA
Description : 
        29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
            SCHED_RR).
          
Date: 31st Aug, 2024.
============================================================================
*/

#include <sched.h>
#include <sys/types.h>
#include <unistd.h>  
#include <stdio.h>    

void main()
{
    int currentPolicy;
    pid_t pid;
    pid = getpid();
    currentPolicy = sched_getscheduler(pid);
    printf("%d\n",currentPolicy);

    switch (currentPolicy)
    {
    case SCHED_FIFO:
        printf("Current policy is FIFO\n");
        break;
    case SCHED_RR:
        printf("Current policy is RR\n");
        break;
    case SCHED_OTHER:
        printf("Current policy is OTHER\n");
        break;
    default:
        perror("Error while getting current policy\n");
    }
    struct sched_param priority;
    priority.sched_priority = 10;
    sched_setscheduler(pid, SCHED_FIFO, &priority);
    currentPolicy = sched_getscheduler(pid);
    printf("%d\n",currentPolicy);
    switch (currentPolicy)
    {
    case SCHED_FIFO:
        printf("New policy is FIFO\n");
        break;
    case SCHED_RR:
        printf("New policy is RR\n");
        break;
    case SCHED_OTHER:
        printf("New policy is OTHER\n");
        break;
    default:
        perror("Error while getting current policy\n");
    }
}

/*
Output:
ankit-sharma@ankit-sharma:~/Practicals/29$ sudo ./29
0
Current policy is OTHER
1
New policy is FIFO

*/