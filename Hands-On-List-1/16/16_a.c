/*
============================================================================
Name : 16_a.c
Author : ANKIT SHARMA
Description : 
        16. Write a program to perform mandatory locking.
            a. Implement write lock
          
Date: 31st Aug, 2024.
============================================================================
*/

#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
int main(){
    struct flock lock;
    int fd;
    fd = open("samplefile.txt",O_RDWR);
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    printf("Before critical section\n");
    fcntl(fd,F_SETLKW,&lock);
    printf("Inside critical section...\n");
    printf("Enter to unlock\n");
    getchar();
    printf("Unlocked\n");
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLK,&lock);
    printf("Finish\n");
}


/*
Output:
Process1:
ankit-sharma@ankit-sharma:~/Practicals/16$ ./16_a
Before critical section
Inside critical section...
Enter to unlock

Process2:
ankit-sharma@ankit-sharma:~/Practicals/16$ ./16_a
Before critical section


*/