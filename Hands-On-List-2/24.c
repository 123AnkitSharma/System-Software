/*
============================================================================
Name : 24.c
Author : ANKIT SHARMA
Description : 
        Write a program to create a message queue and print the key and message queue id.

Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

int main() {
    key_t queue_key;
    int queue_id;

    queue_key = ftok(".", 'Y');

    queue_id = msgget(queue_key, 0666 | IPC_CREAT);

    printf("queue_key: %d\n",queue_key);
    printf("queue_id: %d\n",queue_id);

    return 0;
}

/*
Output:
./24
queue_key: 1493570395
queue_id: 0

*/
