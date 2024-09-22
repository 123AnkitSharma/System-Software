/*
============================================================================
Name : 30_d.c
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
shmid = shmget(key, 1024, IPC_CREAT|0744);
printf("shared memory ID :%d\n",shmid);


printf("press any key to delete shared memory\n");
    getchar();
    printf("Deleting shared memory\n");
    shmctl(shmid, IPC_RMID, NULL);

}

/*
Output: ./30_d
shared memory ID :262166
press any key to delete shared memory

Deleting shared memory

*/