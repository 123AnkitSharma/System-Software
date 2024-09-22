
/*
============================================================================
Name : 12.c
Author : ANKIT SHARMA
Description : 
        Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
        the parent process from the child process.
          
Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    
    int process_id = fork();

    if (process_id < 0) {

        perror("failure in fork()!");
        exit(0);

    }

    if (process_id == 0) 
    {

        printf("Child process created with pid: %d.\n", getpid());
        printf("Child process sent SIGKILL to current parent process whose id: %d.\n", getppid());
        kill(getppid(), SIGKILL);
        sleep(3);
        printf("Child has become orphan now, adopted by new parent i.e. init with p_id: %d.\n", getppid());
    } 
    
    else 
    {
        printf("Parent process is created with p_id: %d and child process with p_id: %d.\n", getpid(), process_id);
        for(;;); //parent process will not terminate until child sends SIGKILL signal
    }

    return 0;
}

/*
Output: ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./12
Parent process is created with p_id: 17018 and child process with p_id: 17019.
Child process created with pid: 17019.
Child process sent SIGKILL to current parent process whose id: 17018.
Killed
ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ Child has become orphan now, adopted by new parent i.e. init with p_id: 1892.

*/