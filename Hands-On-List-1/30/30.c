/*
============================================================================
Name : 30.c
Author : ANKIT SHARMA
Description : 
        30. Write a program to run a script at a specific time using a Daemon process.
          
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/stat.h>

void makeDaemon(time_t now, time_t actual) {
        setsid();
        chdir("/");
        umask(0);
        printf("Childs pid is: %d and parents id is: %d\n", getpid(), getppid());
        printf("It is going to wait until correct time\n");
        do {
                time(&now);
        } while (difftime(actual, now) != 0);
        printf("Time matched\n");
        printf("Task complete");
        exit(0);
}

int main() {
        time_t now, actual;
        struct tm *deadline;
        time(&now);
        deadline = localtime(&now);

        deadline->tm_hour = 22;
        deadline->tm_min = 03;
        deadline->tm_sec = 50;
        actual = mktime(deadline);
        if(!fork()) {
                makeDaemon(now, actual);
        }
        else {
                printf("Parent %d is going to exit\n", getpid());
        }
        return 0; 
}


/*
Output:
ankit-sharma@ankit-sharma:~/Practicals/30$ ./30
Parent 15938 is going to exit
Childs pid is: 15939 and parents id is: 15938
It is going to wait until correct time
ankit-sharma@ankit-sharma:~/Practicals/30$ Time matched
Task complete


*/