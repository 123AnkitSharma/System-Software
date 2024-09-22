/*
============================================================================
Name : 31_b.c
Author : ANKIT SHARMA
Description : 
        Write a program to create a semaphore and initialize value to the semaphore.
            a. create a binary semaphore
            b. create a counting semaphore

Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>

typedef union semun
{
    int val;                   // val for set val /* 1 for binary else > 1 for Counting Semaphore */
    struct semid_ds *buf;      // Data structure describing a set of semaphores.
    unsigned short int *array; // array for GETALL, SETALL
} semun;


int main()
{
    int key,semid;
    semun arg;

    key=ftok(".",10);

    semid= semget(key,1,0744|IPC_CREAT);

    arg.val=5;

    semctl(semid,0,SETVAL,arg);

    printf("Counting Semaphore created and initialized successfully!\n");
    printf("Counting Semaphore ID: %d\n",semid);

    return 0;
}

/*
Output:  ./31_b
Counting Semaphore created and initialized successfully!
Counting Semaphore ID: 7

*/