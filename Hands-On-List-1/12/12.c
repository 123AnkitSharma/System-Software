/*
============================================================================
Name : 12.c
Author : ANKIT SHARMA
Description : 
        12. Write a program to find out the opening mode of a file. Use fcntl.
          
Date: 31st Aug, 2024.
============================================================================
*/
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd, flags;

    // Open a file for reading, writing, and appending
    // fd = open("myfile.txt", O_RDWR | O_CREAT | O_APPEND,0700);
    fd = open("my_file.txt", O_WRONLY);

    // Get the current file status flags
    flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl");
        return 1;
    }

    // Check for various opening modes
    if (flags & O_RDONLY) {
        printf("File is opened for reading only\n");
    }
    else if (flags & O_WRONLY) {
        printf("File is opened for writing only\n");
    }
    else if (flags & O_RDWR) {
        printf("File is opened for both reading and writing\n");
    }
    else if (flags & O_CREAT) {
        printf("File is created if it doesn't exist\n");
    }
    else if (flags & O_TRUNC) {
        printf("File is truncated to zero length if it exists\n");
    }
    else if (flags & O_APPEND) {
        printf("Data is appended to the end of the file\n");
    }
    else if (flags & O_NONBLOCK) {
        printf("Non-blocking mode is set for file operations\n");
    }
    else if (flags & O_SYNC) {
        printf("Data is synchronized with the underlying storage device\n");
    }
    else if (flags & O_ASYNC) {
        printf("Asynchronous notification is enabled for I/O operations\n");
    }
    else{
        printf("Not in any mode");
    }
    close(fd);
    return 0;
}

/*
Output:
ankit-sharma@ankit-sharma:~/Practicals/12$ ./12
File is opened for writing only


*/