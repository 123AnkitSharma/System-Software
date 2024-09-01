/*
============================================================================
Name : 25.c
Author : ANKIT SHARMA
Description : 
        25. Write a program to create three child processes. The parent should wait for a particular child (use
            waitpid system call).
          
Date: 31st Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int child1, child2, child3;

    // to fetch parent process id
    printf("Parent: PID = %d\n", getpid());

    //Three child process to be created
    
     if((child1 = fork()) == 0) 
     {
        // Child process 1 will enter this branch
        printf("Child 1: PID = %d\n", getpid());
        return 0;
    }
    
     if((child2 = fork()) == 0) 
     {
        // Child process 2 will enter this branch
        printf("Child 2: PID = %d\n", getpid());
        return 0;
    }
    
     if((child3 = fork()) == 0) 
     {
        // Child process 3 will enter this branch
        printf("Child 3: PID = %d\n", getpid());
        return 0;
    }



    // parent process is waiting for the 2nd child process
    int waited_pid = waitpid(child2, NULL, 0);

    if (waited_pid == -1) 
    {
        perror("failure in waitpid");
        return 1;
    }

    printf("Parent: Waited for child with PID = %d\n", waited_pid);

    return 0;
}


/*
Output:
ankit-sharma@ankit-sharma:~/Practicals/25$ ./25
Parent: PID = 14813
Child 1: PID = 14814
Child 2: PID = 14815
Parent: Waited for child with PID = 14815
Child 3: PID = 14816


*/