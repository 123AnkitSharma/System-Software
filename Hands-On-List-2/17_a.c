/*
============================================================================
Name : 17_a.c
Author : ANKIT SHARMA
Description : 
        Write a program to execute ls -l | wc.
        a. use dup
        b. use dup2
        c. use fcntl 

Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() 
{
    int fd[2];
    pipe(fd);

    if(fork()==0)
    {
        close(1);
        close(fd[0]);
        dup(fd[1]);
        close(fd[1]);
        execlp("ls","ls", "-l", (char *)NULL);
    }

    else
    {
        close(0);
        close(fd[1]);
        dup(fd[0]);
        close(fd[0]);
        execlp("wc","wc",(char *)NULL);
    }

}

/*
Output:
./17_a
    144    1281    9186

*/