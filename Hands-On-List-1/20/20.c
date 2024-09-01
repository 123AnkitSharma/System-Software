/*
============================================================================
Name : 20.c
Author : ANKIT SHARMA
Description : 
        20. Find out the priority of your running program. Modify the priority with nice command.
          
Date: 31st Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>

int main() {
    int pid;
    pid = getpid();
    int priority = getpriority(PRIO_PROCESS, pid);
    printf("Current Priority: %d\n", priority);

    int new_priority = priority + 5;
    int result = nice(new_priority);
    if (result == -1) {
        perror("nice value error ocurred!");
        return 1;
    }

    priority = getpriority(PRIO_PROCESS, pid); // Get the updated priority
    printf("Modified priority: %d\n", priority);
    return 0;
}

/*
Output:
ankit-sharma@ankit-sharma:~/Practicals/20$ sudo ./20
Current Priority: 0
Modified priority: 5


*/