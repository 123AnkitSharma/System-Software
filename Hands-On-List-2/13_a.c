/*
============================================================================
Name : 13_a.c
Author : ANKIT SHARMA
Description : 
        Write two programs: first program is waiting to catch SIGSTOP signal, the second program
        will send the signal (using kill system call). Find out whether the first program is able to catch
        the signal or not.
          
Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void function() {
    printf("SIGSTOP signal is received\n");
}

int main() {

    printf("Waiting to catch signals. Process ID: %d\n", getpid());
    signal(SIGSTOP,function);

    for(;;);

    return 0;
}

/*
Output: ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./13_a
Waiting to catch signals. Process ID: 17400

[1]+  Stopped                 ./13_a

ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./13_b
Enter the PID of the process to send SIGSTOP: 17400

    Program cannot catch or ignore two signals: SIGSTOP and SIGKILL.
    You can see that custom handler for SIGSTOP signal inside signal() is never executed and instead the program is suspended.

*/
