/*
============================================================================
Name : 08_c.c
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
    printf("SIGFPE signal is caught!\n");
    exit(0);
}

int main() {
    signal(SIGFPE, function);
   
    int x,y,z;
    x=4;
    y=0;
    z=x/y;

    return 0;
}

/*
Output: ./08_c
SIGFPE signal is caught!

*/