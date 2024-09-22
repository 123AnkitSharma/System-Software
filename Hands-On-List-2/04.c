/*
============================================================================
Name : 04.c
Author : ANKIT SHARMA
Description : 
        Write a program to measure how much time is taken to execute 100 getppid( ) system call. Use time stamp counter.
          
Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned long long rdtsc() {
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc":"=A" (dst));
    return dst;
}

int main (void) {
    int i=1, nano;
    unsigned long long int start, end;
    start = rdtsc();
    while(i<=100)
    {
        getppid();
        i++;
    }
            
    end= rdtsc();
    nano=(end-start)/2.5;
    printf("The function takes %d nano sec\n",nano);

}

/*
Output: ./04
The function takes 59678 nano sec


*/
