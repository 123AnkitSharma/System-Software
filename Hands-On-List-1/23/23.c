/*
============================================================================
Name : 23.c
Author : ANKIT SHARMA
Description : 
        23. Write a program to create a Zombie state of the running program.
          
Date: 31st Aug, 2024.
============================================================================
*/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    pid_t childPid;

    if ((childPid = fork()) != 0)
    {
        // Only creator process can enter this branch
        printf("Parent PID: %d\n", getpid());
        printf("Putting parent to sleep for 6s!\n");
        sleep(6); // Put the creator process to sleep for 100s
        printf("Parent is now awake!\n");
    }
    else
    {
        // Only child process can enter this branch
        printf("Child PID: %d\n", getpid());
        printf("Exiting child!\n");
        _exit(0); // Terminate the child process
        // above exit will terminate the child process when parent process is asleep, hence won't be able to send the exit signal to the parent & becomes a zombie
    }
}

/*
Output:
ankit-sharma@ankit-sharma:~/Practicals/23$ ./23
Parent PID: 14518
Putting parent to sleep for 6s!
Child PID: 14519
Exiting child!
Parent is now awake!

*/