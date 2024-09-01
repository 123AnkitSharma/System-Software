/*
============================================================================
Name : 3.c
Author : ANKIT SHARMA
Description : 
        3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call
          
Date: 31st Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

    fd=creat("myfile.txt",0744);
    printf("fd: %d\n",fd);
    if(fd==-1)
    {
        perror("creat call error!");
        return 1;
    }
    close(fd);
    return 0;
}


/*

Output:-
ankit-sharma@ankit-sharma:~/Practicals/3$ ./3
fd: 3


*/