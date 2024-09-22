/*
============================================================================
Name : 14.c
Author : ANKIT SHARMA
Description : 
        Write a simple program to create a pipe, write to the pipe, read from pipe and display on
        the monitor.
          
Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd[2];
    char s[100];

    pipe(fd);

    printf("Enter message to write in pipe: ");
    fgets(s, sizeof(s), stdin);
    write(fd[1], s, strlen(s));
    close(fd[1]);

    printf("Data stored in pipe\n");

    read(fd[0],s,strlen(s));
    write(1,s,strlen(s));
    close(fd[0]);


    return 0;
}

/*
Output: ./14
Enter message to write in pipe: Hello Everyone, Hope you all are fine!
Data stored in pipe
Hello Everyone, Hope you all are fine!

*/