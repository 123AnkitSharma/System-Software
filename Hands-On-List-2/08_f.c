/*
============================================================================
Name : 08_f.c
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
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

void function() {
    printf("SIGVTALRM signal is caught!\n");
    exit(0);
}

int main() {
    struct itimerval timer;
 
    signal(SIGVTALRM, function);

    // Set the timer for 3 seconds
    timer.it_interval.tv_sec = 0; // Alarm cannot repeat after 3 seconds
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_sec = 3;
    timer.it_value.tv_usec = 0;

    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("error in executing setitimer()");
        return 1;
    }

    printf("SIGVTALRM signal gets invoked after 3 seconds\n");

        for(;;);

    return 0;
}


/*
Output: ./08_f
SIGVTALRM signal gets invoked after 3 seconds
SIGVTALRM signal is caught!

*/