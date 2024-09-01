/*
============================================================================
Name : 28.c
Author : ANKIT SHARMA
Description : 
        28. Write a program to get maximum and minimum real time priority.
          
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <sched.h>

int main() {
    int maxpriority, minpriority;

    maxpriority = sched_get_priority_max(SCHED_FIFO);
    if (maxpriority == -1) {
        perror("error in finding max priority!");
    }
    else{
        printf("The max priority using FIFO scheduling policy: %d\n", maxpriority);
    }

    minpriority = sched_get_priority_min(SCHED_FIFO);
    if (minpriority == -1) {
        perror("error in finding min priority");
        return 1;
    }
    else{
        printf("The min priority using FIFO scheduling policy: %d\n", minpriority);
    }

    return 0;
}

/*
Output:
ankit-sharma@ankit-sharma:~/Practicals/28$ ./28
The max priority using FIFO scheduling policy: 99
The min priority using FIFO scheduling policy: 1

*/