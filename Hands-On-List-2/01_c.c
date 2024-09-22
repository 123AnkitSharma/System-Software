/*
============================================================================
Name : 01_c.c
Author : ANKIT SHARMA
Description : 
        1. Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
            a. ITIMER_REAL
            b. ITIMER_VIRTUAL
            c. ITIMER_PROF
          
Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

void function()
    {
        printf("ITIMER_PROF timer has expired!\n");
        exit(0);
    }

void main()
{
    struct itimerval timer;

    printf("You have to choose interval times\na:10s\nb:10micros\n");
    signal(SIGPROF, function);

    char type;
    scanf("%c", &type);

    switch(type){

    case 'a':
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 10;
        timer.it_value.tv_usec = 0;
        break;

    case 'b':
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 0;
        timer.it_value.tv_usec = 10;
        break;

    default:
        printf("You have not entered correct choice!");
        exit(0);
        break;
    }

        setitimer(ITIMER_PROF, &timer, NULL);
        
        for(;;);

}

/*
Output: ./01_c
You have to choose interval times
a:10s
b:10micros
a
ITIMER_PROF timer has expired!


*/