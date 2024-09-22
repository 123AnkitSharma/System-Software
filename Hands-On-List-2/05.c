/*
============================================================================
Name : 05.c
Author : ANKIT SHARMA
Description : 
        Write a program to print the system limitation of
            a. maximum length of the arguments to the exec family of functions.
            b. maximum number of simultaneous process per user id.
            c. number of clock ticks (jiffy) per second.
            d. maximum number of open files
            e. size of a page
            f. total number of pages in the physical memory
            g. number of currently available pages in the physical memory.

Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {

    long value = sysconf(_SC_ARG_MAX);

    /* maximum length of the arguments to the exec family of functions. */
    if(value == -1){
        perror("Error while getting _SC_ARG_MAX!");
    }
    else{
        printf("maximum length of the arguments to the exec family of functions: %ld\n", value);
    }

    /*  _SC_CHILD_MAX -  Maximum number of simultaneous process per user id. */
    value = sysconf(_SC_CHILD_MAX);
    if(value == -1){
        perror("Error while getting _SC_CHILD_MAX!");
    }
    else{ 
        printf("Maximum number of simultaneous process per user id: %ld\n", value);
    }

    /*  _SC_CLK_TCK -  Number of clock ticks (jiffy) per second. */
    value = sysconf(_SC_CLK_TCK);
    if(value == -1){
        perror("Error while getting _SC_CLK_TCK!");
    }
    else{ 
        printf("Number of clock ticks (jiffy) per second: %ld\n", value);
    }
        
    /*  _SC_OPEN_MAX -  Maximum number of open files */
    value = sysconf(_SC_OPEN_MAX);
    if(value == -1){
        perror("Error while getting _SC_OPEN_MAX!");
    }
    else{ 
        printf("Maximum number of open files: %ld\n", value);
    }

    /*  _SC_PAGESIZE -  Size of a page */
    value = sysconf(_SC_PAGESIZE);
    if(value == -1){
        perror("Error while getting _SC_PAGESIZE!");
    }
    else{ 
        printf("Size of a page: %ld\n", value);
    }

    /*  _SC_PHYS_PAGES -  Total number of pages in the physical memory */
    value = sysconf(_SC_PHYS_PAGES);
    if(value == -1){
        perror("Error while getting _SC_PHYS_PAGES!");
    }
    else{ 
        printf("Total number of pages in the physical memory: %ld\n", value);
    }

    /*  _SC_AVPHYS_PAGES -  Number of  currently available pages in the physical memory. */
    value = sysconf(_SC_AVPHYS_PAGES);
    if(value == -1){
        perror("Error while getting _SC_AVPHYS_PAGES!");
    }
    else{ 
        printf("Number of  currently available pages in the physical memory: %ld\n", value);
    }

    return 0;
    
}


/*
Output:  ./05
maximum length of the arguments to the exec family of functions: 2097152
Maximum number of simultaneous process per user id: 30949
Number of clock ticks (jiffy) per second: 100
Maximum number of open files: 1048576
Size of a page: 4096
Total number of pages in the physical memory: 1998575
Number of  currently available pages in the physical memory: 932780

*/