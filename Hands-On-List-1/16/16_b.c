/*
============================================================================
Name : 16_b.c
Author : ANKIT SHARMA
Description : 
        16. Write a program to perform mandatory locking.
            b. Implement read lock
          
Date: 31st Aug, 2024.
============================================================================
*/
#include <unistd.h>
#include <fcntl.h>  
#include <sys/types.h>
#include <sys/stat.h> 
#include <stdio.h>


int main() {
struct flock lock;
int fd;
fd = open("samplefile.txt", O_RDWR);
lock.l_type = F_RDLCK;
lock.l_whence = SEEK_SET;
lock.l_start = 0;
lock.l_len = 0;
lock.l_pid = getpid();
printf("Before entering into critical section\n");
fcntl(fd, F_SETLKW, &lock);
printf("Inside the critical section\n");
printf("Press enter to unlock: ");

getchar();
lock.l_type = F_UNLCK;
fcntl(fd, F_SETLK, &lock);
printf("File unlocked\n");
close(fd);
}


/*
Output:
Process1:
ankit-sharma@ankit-sharma:~/Practicals/16$ ./16_b
Before entering into critical section
Inside the critical section
Press enter to unlock: 

Process2:
ankit-sharma@ankit-sharma:~/Practicals/16$ ./16_b
Before entering into critical section
Inside the critical section
Press enter to unlock: 

*/