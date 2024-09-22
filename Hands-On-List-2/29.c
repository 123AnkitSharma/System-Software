/*
============================================================================
Name : 29.c
Author : ANKIT SHARMA
Description : 
        Write a program to remove the message queue.

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

    // Generate the same unique queue_key as before
    queue_key = ftok(".", 'Y');

    // Message queue is accessed
    queue_id = msgget(queue_key, 0666 | IPC_CREAT);

    // Message queue is destroyed
    msgctl(queue_id, IPC_RMID, NULL);

    return 0;
}

/*
Output: 

ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x5906135b 0          ankit-shar 666        0            0  

./29
ipcs -q
------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages

*/