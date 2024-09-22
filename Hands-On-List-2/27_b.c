/*
============================================================================
Name : 27_b.c
Author : ANKIT SHARMA
Description : 
        Write a program to receive messages from the message queue.
            a. with 0 as a flag
            b. with IPC_NOWAIT as a flag

Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// Define the msg buffer structure
struct buffer_message {
    long msg_type;
    char msg_text[1000];
};



int main() {
    key_t queue_key;
    int queue_id;
    struct buffer_message msg;

    // Generate the same unique queue_key as before
    queue_key = ftok(".", 'Y');

    // Access the msg queue using the same queue_key
    queue_id = msgget(queue_key, 0666 | IPC_CREAT);

    // Receive the msg from the queue
    if(msgrcv(queue_id, &msg, sizeof(msg.msg_text), 0, IPC_NOWAIT)==-1)
    {
         if (errno == ENOMSG){
            printf("message queue is currently empty.\n");
        }

         else{
            printf("msgrcv() error!");
        }
        exit(0);
        
    }

    // Display the received msg
    printf("message received: %s\n", msg.msg_text);

    // Destroy the msg queue after use
    msgctl(queue_id, IPC_RMID, NULL);

    return 0;
}

/*
Output: ./27_b
message queue is currently empty.

*/
