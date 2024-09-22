/*
============================================================================
Name : 10_c.c
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

    printf("SIGFPE signal is caught!\n");
    exit(0);

}

int main() {
    struct sigaction sg;
    int status;
    
    //Custom handler is set
    sg.sa_handler = function;
    sg.sa_flags = 0;
    
    status=sigaction(SIGFPE, &sg, NULL);

    if (status== -1) {
        perror("sigaction");
        return 1;
    }

    int x,y;
    float z=0;
    x=4;
    y=0;
    z=x/y;


    return 0;
}

/*
Output: ./10_c
SIGFPE signal is caught!

*/
