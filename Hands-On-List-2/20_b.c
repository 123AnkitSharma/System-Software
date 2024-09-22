/*
============================================================================
Name : 20_b.c
Author : ANKIT SHARMA
Description : 
        Write two programs so that both can communicate by FIFO -Use one way communication.

Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd,p;
    char buf[100];
    fd=open("my_namedpipe",O_RDONLY);
    read(fd,buf,sizeof(buf));
    printf("Message received: %s\n",buf);
    close(fd);
}

/*
Output:
./20_b
Message received: I am sender program

*/