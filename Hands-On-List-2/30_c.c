/*
============================================================================
Name : 30_c.c
Author : ANKIT SHARMA
Description : 
        Write a program to create a shared memory.
            a. write some data to the shared memory
            b. attach with O_RDONLY and check whether you are able to overwrite.
            c. detach the shared memory
            d. remove the shared memory

Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/shm.h>

int main() {
int key, shmid;
char *data;
key = ftok(".", 'b');
// Create shared memory of size 1024 bytes
shmid = shmget(key, 1024, IPC_CREAT|0744);
// Return value of shmat is pointer to start of shared memory which
//we can just as char* pointer for reading and writing
data = shmat(shmid, 0, 0);
printf("Shared memory attached press any key to detach it\n");
    getchar();
    printf("Detaching pointer to shared memory\n");
    shmdt(data);

    return 0;

}

/*
Output: ./30_c
Shared memory attached press any key to detach it

Detaching pointer to shared memory

*/