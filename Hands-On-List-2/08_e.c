/*
============================================================================
Name : 08_e.c
Author : ANKIT SHARMA
Description : 
        Write a separate program using signal system call to catch the following signals.
            a. SIGSEGV
            b. SIGINT
            c. SIGFPE
            d. SIGALRM (use alarm system call)
            e. SIGALRM (use setitimer system call)
            f. SIGVTALRM (use setitimer system call)
            g. SIGPROF (use setitimer system call)

Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

void function() {
    printf("SIGALRM signal is caught!\n");
    exit(0);
}

int main() {
    struct itimerval timer;

    signal(SIGALRM, function);

    timer.it_interval.tv_sec = 0; // this ensures no repeating of alarm after 4 seconds
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_sec = 4;
    timer.it_value.tv_usec = 0;

    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("error in executing setitimer()");
        return 1;
    }
    printf("SIGALRM signal gets invoked after 4 seconds\n");

        for(;;);
        

    return 0;
}


/*
Output: ./08_e
SIGALRM signal gets invoked after 4 seconds
SIGALRM signal is caught!

*/