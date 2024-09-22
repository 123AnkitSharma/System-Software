/*
============================================================================
Name : 32_b.c
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
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>
void main()
{
    key_t shaKey = ftok(".", 666);
    int shmid = shmget(shaKey, 1024, IPC_CREAT | 0744);
    char *shmPointer;
    shmPointer = shmat(shmid, (void *)0, 0);
    key_t semKey;
    int semIdentifier;
    int semctlStatus;
    int semopStatus;

    // Defines a semaphore's structure
    union semun
    {
        int val;               // Value of the semaphore
        struct semid_ds *buf;  /* Buffer for IPC_STAT, IPC_SET */
        unsigned short *array; /* Array for GETALL, SETALL */
    } semSet;

    // semaphore key
    semKey = ftok(".", 332);
    if (semKey == -1)
    {
        perror("Error while computing key!");
        _exit(1);
    }

    semIdentifier = semget(semKey, 1, 0); // Get the semaphore if it exists
    if (semIdentifier == -1)
    {
        semIdentifier = semget(semKey, 1, IPC_CREAT | 0700); // Create a new semaphore
        if (semIdentifier == -1)
        {
            perror("Error while creating semaphore!");
            _exit(1);
        }

        semSet.val = 1; // Set a binary semaphore
        semctlStatus = semctl(semIdentifier, 0, SETVAL, semSet);
        if (semctlStatus == -1)
        {
            perror("Error while initializing a binary sempahore!");
            _exit(1);
        }
    }

    struct sembuf semOp; // Defines the operation on the semaphore
    semOp.sem_num = 0;
    semOp.sem_flg = 0;

    printf("Press enter to obtain lock on the critical section\n");
    getchar();
    printf("entering to obtain lock on the critical section\n");

    // Use semaphore to lock the critical section
    semOp.sem_op = -1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error while operating on semaphore!");
        _exit(1);
    }

    printf("Obtained lock on critical section!\n");
    printf("Now entering critical section!\n");
    // =========== Start of Critical Section ===========

    printf("write in shared memory\n");
    scanf("%[^\n]", shmPointer);
    printf("data from shared memory : %s\n", shmPointer);
    printf("Press enter to exit from critical section!\n");
    getchar();
    printf("exiting from critical section!\n");

    // =========== End of Critical Section =============

    // Use semaphore to unlock the critical section
    semOp.sem_op = 1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error while operating on semaphore!");
        _exit(1);
    }
}


/*
Output:

Process1
ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./32_b
Press enter to obtain lock on the critical section

entering to obtain lock on the critical section
Obtained lock on critical section!
Now entering critical section!
write in shared memory

Process2
ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./32_b
Press enter to obtain lock on the critical section

entering to obtain lock on the critical section

Process1
ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./32_b
Press enter to obtain lock on the critical section

entering to obtain lock on the critical section
Obtained lock on critical section!
Now entering critical section!
write in shared memory
Hi, there how are you ?
data from shared memory : Hi, there how are you ?
Press enter to exit from critical section!
exiting from critical section!

Process2
ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./32_b
Press enter to obtain lock on the critical section

entering to obtain lock on the critical section


Obtained lock on critical section!
Now entering critical section!
write in shared memory
data from shared memory : Hi, there how are you ?
Press enter to exit from critical section!
exiting from critical section!
*/