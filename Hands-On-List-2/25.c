/*
============================================================================
Name : 25.c
Author : ANKIT SHARMA
Description : 
        Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
            a. access permission
            b. uid, gid
            c. time of last message sent and received
            d. time of last change in the message queue
            d. size of the queue
            f. number of messages in the queue
            g. maximum number of bytes allowed
            h. pid of the msgsnd and msgrcv
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    key_t queuekey;
    int queueId;
    struct msqid_ds msgQueueInfo;

    queuekey = ftok(".", 'Y');

    if (queuekey == -1) 
    {
        
        perror("queuekey generation error using ftok!");
        exit(0);

    }

    // for creating message queue
    queueId = msgget(queuekey, IPC_CREAT|0666);
    if (queueId == -1) 
    {
        perror("queueId not generated!");
        exit(0);

    }

    // for gettin message queue information
    if (msgctl(queueId, IPC_STAT, &msgQueueInfo) == -1) {
        perror("msgctl() could not be executed");
        exit(0);
    }

    // Print the information contained in the msqid_ds structure
   
    printf("Message Queue Metadata:\n\n");
    printf("Access permissions: %o\n", msgQueueInfo.msg_perm.mode);   
    printf("UID=%d\n", msgQueueInfo.msg_perm.uid);
    printf("GID=%d\n", msgQueueInfo.msg_perm.gid);
    printf("Time of last message sent: %s", ctime(&msgQueueInfo.msg_stime));
    printf("Time of last message received: %s", ctime(&msgQueueInfo.msg_rtime));
    printf("Time of last change in the message queue: %s", ctime(&msgQueueInfo.msg_ctime));
    printf("Size of the queue: %ld bytes\n", msgQueueInfo.msg_qbytes);
    printf("Number of messages in the queue: %ld\n", msgQueueInfo.msg_qnum);
    printf("Maximum number of bytes allowed: %ld\n", msgQueueInfo.msg_qbytes);
    printf("pid of the msgsnd: %d and msgrcv: %d\n", msgQueueInfo.msg_lspid, msgQueueInfo.msg_lrpid);

    return 0;
}

/*
Output:
./25
Message Queue Metadata:

Access permissions: 666
UID=1000
GID=1000
Time of last message sent: Thu Jan  1 05:30:00 1970
Time of last message received: Thu Jan  1 05:30:00 1970
Time of last change in the message queue: Sat Sep 21 21:36:35 2024
Size of the queue: 16384 bytes
Number of messages in the queue: 0
Maximum number of bytes allowed: 16384
pid of the msgsnd: 0 and msgrcv: 0

*/