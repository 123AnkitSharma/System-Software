/*
============================================================================
Name : 26.c
Author : ANKIT SHARMA
Description : 
        Write a program to send messages to the message queue. Check $ipcs -q

Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

// Define the msg buffer structure
struct buffer_message {
    long msg_type;
    char msg_text[1000];
};


int main() {
    key_t queue_key;
    int queue_id;
    struct buffer_message msg;

    queue_key = ftok(".", 'Y'); // 'progfile' is any file in your system

    // Create a msg queue and return the id
    queue_id = msgget(queue_key, 0666 | IPC_CREAT);

    // Prepare the msg to be sent
    
    printf("Enter a text\n");
    msg.msg_type = 2;  // Every msg has a type
    fgets(msg.msg_text, 100, stdin);

    // Send the msg to the queue
    msgsnd(queue_id, &msg, sizeof(msg.msg_text), 0);

    printf("queue_key: %d\n",queue_key);
    printf("queue_id: %d\n",queue_id);

    printf("msg sent: %s\n", msg.msg_text);

    return 0;
}

/*
Output:  ./26
Enter a text
Hello there I am ANKIT 
queue_key: 1493570395
queue_id: 0
msg sent: Hello there I am ANKIT

ipcs -q
------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x5906135b 0          ankit-shar 666        1000         1  

*/
