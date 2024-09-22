/*
============================================================================
Name : 13_b.c
Author : ANKIT SHARMA
Description : 
        Write two programs: first program is waiting to catch SIGSTOP signal, the second program
        will send the signal (using kill system call). Find out whether the first program is able to catch
        the signal or not.
          
Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    int status;

    printf("Enter the PID of the process to send SIGSTOP: ");
    scanf("%d", &pid);

    status = kill(pid, SIGSTOP);
    if (status == -1)
    {
        printf("Failed to send SIGSTOP signal to pid: %d\n",pid);
        exit(0);
    }
    
    return 0;
}

/*
Output: ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./13_a
Waiting to catch signals. Process ID: 17400

[1]+  Stopped                 ./13_a

ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./13_b
Enter the PID of the process to send SIGSTOP: 17400

This program sends the SIGSTOP signal to 13_a.c but 13_a.c cannot catch the signal.
*/
