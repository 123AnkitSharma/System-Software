/*
============================================================================
Name : 10_a.c
Author : ANKIT SHARMA
Description : 
        Write a separate program using sigaction system call to catch the following signals.
            a. SIGSEGV
            b. SIGINT
            c. SIGFPE
          
Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void function() {

    printf("SIGSEGV signal is caught!\n");
    exit(0);

}

int main() {
    struct sigaction sg;
    int status;
    
    //Custom handler is set
    sg.sa_handler = function;
    sg.sa_flags = 0;
    
    status=sigaction(SIGSEGV, &sg, NULL);

    if (status== -1) {
        perror("sigaction");
        return 1;
    }
     //to trigger a segmentation fault
    int *x = NULL;
    *x = 0; 


    return 0;
}


/*
Output: ./10_a
SIGSEGV signal is caught!

*/