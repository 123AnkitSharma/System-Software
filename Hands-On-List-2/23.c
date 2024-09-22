/*
============================================================================
Name : 23.c
Author : ANKIT SHARMA
Description : 
        Write a program to print the maximum number of files can be opened within a process and
        size of a pipe (circular buffer).

Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    struct rlimit Resource_Limit;
    int fd;

     if (getrlimit(RLIMIT_NOFILE, &Resource_Limit) == 0) {
        printf("Maximum number of file descriptors a process can have simultaneously, softlimit=%ld, hardlimit=%ld\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    }
    else {
        printf("Failed to get file descriptor limit!");
    }

    fd=open("myfifo1",O_RDONLY | O_NONBLOCK);

    long pipe_size = fpathconf(fd, _PC_PIPE_BUF);
    if (pipe_size != -1) {
        printf("Pipe buffer size: %ld bytes\n", pipe_size);
    } else {
        perror("Failed to get pipe buffer size");
    }


}

/*
Output:
./23
Maximum number of file descriptors a process can have simultaneously, softlimit=1048576, hardlimit=1048576
Pipe buffer size: 4096 bytes


*/