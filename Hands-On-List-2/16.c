/*
============================================================================
Name : 16.c
Author : ANKIT SHARMA
Description : 
        Write a program to send and receive data from parent to child vice versa. Use two way
        communication. 

Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    char s1[80],s2[80];
    int fd1[2],fd2[2];

    pipe(fd1);
    pipe(fd2);

    if (!fork()) 
    {
            close(fd1[0]); // Close read-end of fd1 for child
            close(fd2[1]); // Close write-end of fd2 for child
            printf("Enter message which child wants to send to parent: ");
            scanf(" %[^\n]", s1);
            write(fd1[1], s1, sizeof(s1));
            read(fd2[0], s2, sizeof(s2));
            printf("Message received from parent in child: %s\n", s2);
    }

    else 
    {
            close(fd1[1]); // Close read-end of fd1 for parent
            close(fd2[0]); // Close read-end of fd2 for parent
            // Child wrote into fd1 first, so read from fd1 first
            read(fd1[0], s1, sizeof(s1));

            printf("Message received from child in parent: %s\n", s1);
            printf("Enter message which parent wants to send to child: ");
            scanf(" %[^\n]", s2);
            write(fd2[1], s2, sizeof(s2));
    }
    wait(0);
}

/*
Output: ./16
Enter message which child wants to send to parent: Hi I am child process
Message received from child in parent: Hi I am child process
Enter message which parent wants to send to child: Hi I am parent process
Message received from parent in child: Hi I am parent process

*/