/*
============================================================================
Name : 08_d.c
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
#include <stdlib.h>
#include <unistd.h>

void function() {
    printf("SIGALRM signal is caught!\n");
    exit(0);
}

int main() {
    signal(SIGALRM, function);
  
    alarm(4); // This alarm will go off after 4 seconds

    printf("SIGALRM signal gets invoked after 4 seconds\n");
    
    for(;;);

    return 0;
}


/*
Output: ./08_d
SIGALRM signal gets invoked after 4 seconds
SIGALRM signal is caught!

*/