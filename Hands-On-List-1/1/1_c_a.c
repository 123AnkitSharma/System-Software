/*
============================================================================
Name : 1_c_a.c
Author : ANKIT SHARMA 
Description : 
        1. Create the following types of a files using  (ii) system call
            c. FIFO (mkfifo Library Function or mknod system call)

Date: 31st Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int n,p;
    char buf[100];
    mkfifo("my_namedpipe",0777);
    while(1){
    p=read(0,buf,100);
    n=open("my_namedpipe",O_WRONLY);
    write(n,buf,p);
    close(n);

    n=open("my_namedpipe",O_RDONLY);
    p=read(n,buf,100);
    printf("Programmer2: %s",buf);
    close(n);
    }
}

/*

Output:-
ankit-sharma@ankit-sharma:~/Practicals/1/1_c$ ./1_c_a
How are you prog2 ?
Programmer2: I am fine what about prog1?

*/