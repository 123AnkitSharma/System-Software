/*
============================================================================
Name : 11.c
Author : ANKIT SHARMA
Description : 
        Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
        use sigaction system call.
          
Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


int main() {
    struct sigaction sg;
    int status;
    char ch;
    
    printf("SIGINT is disabled currently, Ctrl+C won't work.\n");
    
    //Custom handler is set
    sg.sa_handler = SIG_IGN;
    sg.sa_flags = 0;
    
    status=sigaction(SIGINT, &sg, NULL);
     printf("Press 1 to enable Interrupt Signal\n");

    if (status== -1) {
        perror("sigaction");
        return 1;
    }

     while(1)
    {
        ch=getchar();
        if(ch=='1'){
           break;  
        }
    }
    
    printf("Interrupt Signal is enabled properly, Ctrl+C will terminate the program.\n");
    if(ch=='1'){
    sg.sa_handler = SIG_DFL;
    sg.sa_flags = 0;
    status=sigaction(SIGINT, &sg, NULL);
    }
   
    while(1);

    return 0;
}

/*
Output:  ./11
SIGINT is disabled currently, Ctrl+C won't work.
Press 1 to enable Interrupt Signal
^C
^C
1
Interrupt Signal is enabled properly, Ctrl+C will terminate the program.
^C

*/