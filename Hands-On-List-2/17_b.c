/*
============================================================================
Name : 17_b.c
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
#include <sys/wait.h>

int main()
{
    int fd[2];
    pipe(fd);

    if(fork()==0)
    {
        close(fd[0]);
        dup2(fd[1],1);
        close(fd[1]);
        execlp("ls","ls","-l",(char *)NULL);
    }

    else
    {
        close(fd[1]);
        dup2(fd[0],0);
        close(fd[0]);
        execlp("wc","wc",(char *)NULL);

        wait(0);
    }
}

/*
Output: 
./17_b
    144    1281    9186

*/