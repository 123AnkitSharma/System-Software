/*
============================================================================
Name : 30_b.c
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
data = shmat(shmid, 0, SHM_RDONLY);
if (data == (char *)-1)
    {
        perror("Shared memory unable to attach");
        return 1;
    }

    printf("Enter text in shared memory\n");
    scanf("%[^\n]", data);

        return 0;
}

/*
Output: ./30_b
Enter text in shared memory
writing in shared memory 2nd time
Segmentation fault (core dumped)

NO overwriting is allowed in readonly mode
*/