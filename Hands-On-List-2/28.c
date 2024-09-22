/*
============================================================================
Name : 28.c
Author : ANKIT SHARMA
Description : 
        Write a program to change the existing message queue permission. (use msqid_ds structure)

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

    // for getting message queue information
    if (msgctl(queueId, IPC_STAT, &msgQueueInfo) == -1) {
        perror("msgctl() could not be executed");
        exit(0);
    }

    // To get queue current access permission
   
    printf("Current access permissions: %o\n", msgQueueInfo.msg_perm.mode);

    printf("Press 1 to set new access permission to 0x600\n");
    char ch=getchar();
    if(ch=='1'){
    msgQueueInfo.msg_perm.mode =0600;

    if (msgctl(queueId, IPC_SET, &msgQueueInfo) == -1) {
        printf("permission cannot be set!");
        exit(1);
    }
    }

    printf("New access permissions: %o\n", msgQueueInfo.msg_perm.mode);

    
    return 0;
}

/*
Output:  ./28
Current access permissions: 666
Press 1 to set new access permission to 0x600
1
New access permissions: 600

*/