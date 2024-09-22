/*
============================================================================
Name : 09.c
Author : ANKIT SHARMA
Description : 
        Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
        signal - Use signal system call.
          
Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char ch;
    printf("SIGINT is disabled currently, Ctrl+C won't work.\n");
    signal(SIGINT, SIG_IGN);
    printf("Press 1 to enable Interrupt Signal\n");

    while(1)
    {
        ch=getchar();
        if(ch=='1'){
           break;  
        }
    }
    printf("Interrupt Signal is enabled properly, Ctrl+C will terminate the program.\n");
    if(ch=='1'){
    signal(SIGINT, SIG_DFL);
    }

    while(1);

    return 0;
}

/*
Output:
SIGINT is disabled currently, Ctrl+C won't work.
Press 1 to enable Interrupt Signal
^C^C^C
1
Interrupt Signal is enabled properly, Ctrl+C will terminate the program.
^C

*/