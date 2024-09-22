/*
============================================================================
Name : 02.c
Author : ANKIT SHARMA
Description : 
        Write a program to print the system resource limits. Use getrlimit system call.
          
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit Resource_Limit;

    printf("Resource Limits are as follows:\n");

    if (getrlimit(RLIMIT_AS, &Resource_Limit) == 0) {
        printf("Process's virtual memory max size, softlimit=%ld bytes, hardlimit=%ld bytes\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    } 
    else {
        printf("RLIMIT_AS error!");
    }

    if (getrlimit(RLIMIT_CORE, &Resource_Limit) == 0) {
        printf("maximum size of a core file, softlimit=%ld bytes, hardlimit=%ld bytes\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    }
    else {
        printf("RLIMIT_CORE error!");
    }

    if (getrlimit(RLIMIT_CPU, &Resource_Limit) == 0) {
        printf("Maximum CPU Time a process consumes, softlimit=%ld sec, hardlimit=%ld sec\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    }
    else {
        printf("RLIMIT_CPU error!");
    }

    if (getrlimit(RLIMIT_DATA, &Resource_Limit) == 0) {
        printf("maximum size of the process's data segment, softlimit=%ld bytes, hardlimit=%ld bytes\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    }
    else {
        printf("RLIMIT_DATA error!");
    }

    if (getrlimit(RLIMIT_FSIZE, &Resource_Limit) == 0) {
        printf("maximum size of files that the process may create, softlimit=%ld bytes, hardlimit=%ld bytes\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    }
    else {
        printf("RLIMIT_FSIZE error!");
    }

    if (getrlimit(RLIMIT_LOCKS, &Resource_Limit) == 0) {
        printf("ax number of locks that a process may establish, softlimit=%ld , hardlimit=%ld\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    }
    else {
        printf("RLIMIT_LOCKS error!");
    }

    if (getrlimit(RLIMIT_MEMLOCK, &Resource_Limit) == 0) {
        printf("Max number of bytes of memory that may be locked into RAM, softlimit=%ld bytes, hardlimit=%ld bytes\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    }
    else {
        printf("RLIMIT_MEMLOCK error!");
    }

    if (getrlimit(RLIMIT_MSGQUEUE, &Resource_Limit) == 0) {
        printf("Max number of bytes of that can be allocated for POSIX message queues, softlimit=%ld bytes, hardlimit=%ld bytes\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    }
    else {
        printf("RLIMIT_MSGQUEUE error!");
    }

    if (getrlimit(RLIMIT_NICE, &Resource_Limit) == 0) {
        printf("Ceiling of the process's nice value, softlimit=%ld, hardlimit=%ld\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    }
    else {
        printf("RLIMIT_NICE error!");
    }

    if (getrlimit(RLIMIT_NOFILE, &Resource_Limit) == 0) {
        printf("Maximum number of file descriptors a process can have simultaneously, softlimit=%ld, hardlimit=%ld\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    }
    else {
        printf("RLIMIT_NOFILE error!");
    }

    if (getrlimit(RLIMIT_NPROC, &Resource_Limit) == 0) {
        printf("Maximum number of threads a user can have running simultaneously, softlimit=%ld, hardlimit=%ld\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    }
    else {
        printf("RLIMIT_NPROC error!");
    }

    if (getrlimit(RLIMIT_RSS, &Resource_Limit) == 0) {
        printf("Limit on number of virtual pages resident in RAM, softlimit=%ld, hardlimit=%ld\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    }
    else {
        printf("RLIMIT_RSS error!");
    }

    if (getrlimit(RLIMIT_RTPRIO, &Resource_Limit) == 0) {
        printf("ceiling on the real-time priority for a process, softlimit=%ld, hardlimit=%ld\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    }
    else {
        printf("RLIMIT_RTPRIO error!");
    }

    if (getrlimit(RLIMIT_RTTIME, &Resource_Limit) == 0) {
        printf("maximum amount of CPU time that a process can use under real-time scheduling, softlimit=%ld microseconds, hardlimit=%ld microseconds\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    }
    else {
        printf("RLIMIT_RTTIME error!");
    }

    if (getrlimit(RLIMIT_SIGPENDING, &Resource_Limit) == 0) {
        printf("number of signals that may be queued for the real user ID of the calling process, softlimit=%ld, hardlimit=%ld\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    }
    else {
        printf("RLIMIT_SIGPENDING error!");
    }

    if (getrlimit(RLIMIT_STACK, &Resource_Limit) == 0) {
        printf("maximum size of process stack, softlimit=%ld bytes, hardlimit=%ld bytes\n", Resource_Limit.rlim_cur, Resource_Limit.rlim_max);
    }
    else {
        printf("RLIMIT_STACK error!");
    }
    return 0;
}


/*
Output:
Resource Limits are as follows:
Process's virtual memory max size, softlimit=-1 bytes, hardlimit=-1 bytes
maximum size of a core file, softlimit=0 bytes, hardlimit=-1 bytes
Maximum CPU Time a process consumes, softlimit=-1 sec, hardlimit=-1 sec
maximum size of the process's data segment, softlimit=-1 bytes, hardlimit=-1 bytes
maximum size of files that the process may create, softlimit=-1 bytes, hardlimit=-1 bytes
ax number of locks that a process may establish, softlimit=-1 , hardlimit=-1
Max number of bytes of memory that may be locked into RAM, softlimit=1023266816 bytes, hardlimit=1023266816 bytes
Max number of bytes of that can be allocated for POSIX message queues, softlimit=819200 bytes, hardlimit=819200 bytes
Ceiling of the process's nice value, softlimit=0, hardlimit=0
Maximum number of file descriptors a process can have simultaneously, softlimit=1048576, hardlimit=1048576
Maximum number of threads a user can have running simultaneously, softlimit=30949, hardlimit=30949
Limit on number of virtual pages resident in RAM, softlimit=-1, hardlimit=-1
ceiling on the real-time priority for a process, softlimit=0, hardlimit=0
maximum amount of CPU time that a process can use under real-time scheduling, softlimit=-1 microseconds, hardlimit=-1 microseconds
number of signals that may be queued for the real user ID of the calling process, softlimit=30949, hardlimit=30949
maximum size of process stack, softlimit=8388608 bytes, hardlimit=-1 bytes


*/