/*
============================================================================
Name : 34_b_client.c
Author : ANKIT SHARMA
Description : 
        Write a program to create a concurrent server.
            b. use pthread_create

Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_MESSAGE_LENGTH 100

int main() {
    int socketFileDescriptor;
    ssize_t readBytes, writeBytes;
    char dataFromServer[MAX_MESSAGE_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor == -1) {
        perror("Error while creating socket!");
        return 1;
    }

    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(8083);
    address.sin_addr.s_addr = INADDR_ANY;
    if (connect(socketFileDescriptor, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("Error while connecting to the server!");
        close(socketFileDescriptor);
        return 1;
    }

    printf("Connected to the server!\n");

    while (1) {
        printf("Enter a message (type 'exit' to quit): ");
        fgets(message, sizeof(message), stdin);
        message[strlen(message) - 1] = '\0';
        writeBytes = write(socketFileDescriptor, message, strlen(message));
        if (writeBytes == -1) {
            perror("Error while writing to network via socket!");
            break;
        }

        readBytes = read(socketFileDescriptor, dataFromServer, sizeof(dataFromServer));
        if (readBytes == -1) {
            perror("Error while reading from the server!");
            break;
        } else if (readBytes == 0) {
            printf("Server closed the connection.\n");
            break;
        }

        dataFromServer[readBytes] = '\0';
        printf("Received data from the server: %s\n", dataFromServer);
        if (strcasecmp(message, "exit") == 0) {
            printf("Requested to exit. Closing the connection.\n");
            break;
        }
    }

    close(socketFileDescriptor);

    return 0;
}

/*
Output:
ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./34_b_client 
Connected to the server!
Enter a message (type 'exit' to quit): I am client1       
Received data from the server: hello client1
Enter a message (type 'exit' to quit): 


ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./34_b_client 
Connected to the server!
Enter a message (type 'exit' to quit): I am client2
Received data from the server: hello client2
Enter a message (type 'exit' to quit): 


ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./34_b_client 
Connected to the server!
Enter a message (type 'exit' to quit): I am client3
Received data from the server: hello client3
Enter a message (type 'exit' to quit): 
*/