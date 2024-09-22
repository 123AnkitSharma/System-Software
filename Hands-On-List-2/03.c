/*
============================================================================
Name : 03.c
Author : ANKIT SHARMA
Description : 
        Write a program to set (any one) system resource limit. Use setrlimit system call.
          
Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit Resource_Limit;

    if (getrlimit(RLIMIT_NOFILE, &Resource_Limit) == 0) {
        printf("Maximum number of file descriptors a process can have simultaneously, softlimit=%ld, hardlimit=%ld\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    }
    else {
        printf("RLIMIT_NOFILE error!");
    }

    //setting soft and hard limit for RLIMIT_NOFILE
    Resource_Limit.rlim_cur = 10;
    Resource_Limit.rlim_max = 50;

    if (setrlimit(RLIMIT_NOFILE, &Resource_Limit) == 0) {
        printf("RLIMIT_NOFILE limits set successfully.\n");
    } else {
        printf("setrlimit error!");
    }
    printf("After setting soft and hard limits for fds a process can have simultaneously\n");
    if (getrlimit(RLIMIT_NOFILE, &Resource_Limit) == 0) {
        printf("New Value of max file descriptors a process can have simultaneously, softlimit=%ld, hardlimit=%ld\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    }
    else {
        printf("RLIMIT_NOFILE error!");
    }   

    return 0;
}

/*
Output: ./03.c
Maximum number of file descriptors a process can have simultaneously, softlimit=1048576, hardlimit=1048576
RLIMIT_NOFILE limits set successfully.
After setting soft and hard limits for fds a process can have simultaneously
New Value of max file descriptors a process can have simultaneously, softlimit=10, hardlimit=50

*/