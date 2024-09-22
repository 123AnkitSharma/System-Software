/*
============================================================================
Name : 08_a.c
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

void function() {
    printf("SIGSEGV signal is caught!\n");
    exit(0);
}

int main() {
    signal(SIGSEGV, function);

    //to trigger a segmentation fault
    int *x = NULL;
    *x = 0;

    return 0;
}

/*
Output: ./08_a
SIGSEGV signal is caught!

*/