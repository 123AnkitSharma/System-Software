/*
============================================================================
Name : 15.c
Author : ANKIT SHARMA
Description : 
        Write a simple program to send some data from parent to the child process.
          
Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd[2];
    char s[100];

    pipe(fd);

    if (fork() == 0) 
    {
        close(fd[1]);
        read(fd[0], s, sizeof(s));
        printf("Message received from parent in the child: %s",s);
    } 
    
    else
    { 
        close(fd[0]);
        printf("Enter message parent wants to send to child\n");
        fgets(s, sizeof(s), stdin);
        write(fd[1], s, sizeof(s));      
    }
    wait(0);

    return 0;
}

/*
Output:  ./15
Enter message parent wants to send to child
Hi I am parent process
Message received from parent in the child: Hi I am parent process

*/