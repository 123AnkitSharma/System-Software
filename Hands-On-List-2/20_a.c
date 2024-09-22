/*
============================================================================
Name : 20_a.c
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

    printf("Enter message to send: ");
    mkfifo("my_namedpipe",0777);
    scanf(" %[^\n]", buf);
    fd=open("my_namedpipe",O_WRONLY);
    write(fd, buf, sizeof(buf));
    close(fd);
}

/*
Output:
./20_a
Enter message to send: I am sender program

*/