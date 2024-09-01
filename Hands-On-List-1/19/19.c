/*
============================================================================
Name : 19.c
Author : ANKIT SHARMA
Description : 
        19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.
          
Date: 31st Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned long long rdtsc() {
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc":"=A" (dst));
}

int main (void) {
    int i, nano;
    unsigned long long int start, end;
    start = rdtsc();
     getpid();
        
    end= rdtsc();
    nano=(end-start)/2.5;
    printf("The function takes %d nano sec\n",nano);


}

/*
Output:
ankit-sharma@ankit-sharma:~/Practicals/19$ ./19
The function takes 1858 nano sec

*/