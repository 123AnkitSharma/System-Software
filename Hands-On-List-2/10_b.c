/*
============================================================================
Name : 10_b.c
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

    printf("SIGINT signal is caught!\n");
    exit(0);

}

int main() {
    struct sigaction sg;
    int status;
    
    //Custom handler is set
    sg.sa_handler = function;
    sg.sa_flags = 0;
    
    status=sigaction(SIGINT, &sg, NULL);

    if (status== -1) {
        perror("sigaction");
        return 1;
    }
    
    printf("Interrupting me will raise SIGINT signal\n");
  
    for(;;)
    {  }   


    return 0;
}

/*
Output: ./10_b
Interrupting me will raise SIGINT signal
^CSIGINT signal is caught!

*/
