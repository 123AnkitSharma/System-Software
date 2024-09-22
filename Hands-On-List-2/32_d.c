/*
============================================================================
Name : 32_d.c
Author : ANKIT SHARMA
Description : 
        Write a program to implement semaphore to protect any critical section.
            a. rewrite the ticket number creation program using semaphore
            b. protect shared memory from concurrent write access
            c. protect multiple pseudo resources ( may be two) using counting semaphore
            d. remove the created semaphore

Date: 21st Sept, 2024.
============================================================================
*/
#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/sem.h>   
#include <unistd.h>    
#include <stdio.h>    

void main(){

    int semctlStatus;

    int key = ftok(".",10);

    int semid = semget(key,1,IPC_CREAT | 0666);



    printf("Press enter to delete the semaphore %d!\n",semid);
    getchar();

    int semctlflag= semctl(semid,0,IPC_RMID);


    printf("Semaphore deleted successfully!!");
}

/*
Output:
ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x0a06135b 3          ankit-shar 666        1 

ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./32_d
Press enter to delete the semaphore 3!

Semaphore deleted successfully!!

ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems  

*/