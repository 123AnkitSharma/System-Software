/*
============================================================================
Name : 4.c
Author : ANKIT SHARMA
Description : 
        4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
          
Date: 31st Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd;
    fd=open("info.txt",O_RDWR|O_CREAT|O_EXCL,0744);
    if(fd==-1)
    {
        perror("Failure!");
        return 1;
    }
    write(fd,"Hey There!",10);
    return 0;
}

/*
Output:-
ankit-sharma@ankit-sharma:~/Practicals/4$ ./4
Failure!: File exists

*/