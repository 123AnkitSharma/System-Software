/*
============================================================================
Name : 22.c
Author : ANKIT SHARMA
Description : 
        Write a program to wait for data to be written into FIFO within 10 seconds, use select
        system call with FIFO.

Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>

int main() {
    char buff[100];
    int fd, retval;
    fd_set read_fds;
    struct timeval timeover;

    // Set timeout of 10 seconds
    timeover.tv_sec = 10;
    timeover.tv_usec = 0; // microseconds part

    // Open FIFO in non-blocking mode
    fd = open("myfifo1", O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("Error opening FIFO");
        return 1;
    }

    // Clear and set the read file descrip./22tor set
    FD_ZERO(&read_fds);
    FD_SET(fd, &read_fds);

    // Call select() to wait for data on the FIFO or timeout
    retval = select(fd + 1, &read_fds, NULL, NULL, &timeover);

    if (retval == -1) {
        perror("select call error!");
        return 1;
    } 

    else if (retval == 0) {
        printf("No data is available for reading yet\n");
    } 
    
    else {
        
            printf("Data is available now\n");
            read(fd, buff, sizeof(buff));
            printf("Data from FIFO: %s\n", buff);
       
    }

    // Close the FIFO
    close(fd);

    return 0;
}

/*
Output:
./22
No data is available for reading yet

./22
Data is available now
Data from FIFO: hello

*/
