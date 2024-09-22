/*
============================================================================
Name : 34_b_server.c
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
#include <pthread.h>

#define MAX_MESSAGE_LENGTH 100

void *communicate_with_client(void *arg) {
    int client_socket = *((int *)arg);
    ssize_t readBytes, writeBytes;
    char message[MAX_MESSAGE_LENGTH];

    while (1) {
        readBytes = read(client_socket, message, sizeof(message));
        if (readBytes <= 0) {
            perror("Error while reading from the client!");
            break;
        }

        message[readBytes] = '\0'; 
        printf("Received from client: %s\n", message);

        if (strcasecmp(message, "exit") == 0) {
            printf("Client requested to exit. Closing the connection.\n");
            break;
        }

        printf("Enter a response message (type 'exit' to quit): ");
        fgets(message, sizeof(message), stdin);
        message[strlen(message) - 1] = '\0'; 
        writeBytes = write(client_socket, message, strlen(message));
        if (writeBytes <= 0) {
            perror("Error while writing to the client!");
            break;
        }
    }
    close(client_socket);
    pthread_exit(NULL);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_addr_len = sizeof(client_address);
    pthread_t thread_id;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error while creating socket!");
        return 1;
    }
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8083);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error while binding to socket!");
        close(server_socket);
        return 1;
    }

    if (listen(server_socket, 3) == -1) {
        perror("Error while listening for connections!");
        close(server_socket);
        return 1;
    }

    printf("Server listening for connections....\n");

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_addr_len);
        if (client_socket == -1) {
            perror("Error while accepting a connection!");
            continue; 
        }

        if (pthread_create(&thread_id, NULL, communicate_with_client, (void *)&client_socket) != 0) {
            perror("Error while creating thread!");
            close(client_socket);
        }
    }

    close(server_socket);

    return 0;
}

/*
Output:
ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./34_b_server
Server listening for connections....
Received from client: I am client1
Enter a response message (type 'exit' to quit): hello client1
Received from client: i am client2
Enter a response message (type 'exit' to quit): hello client2
Received from client: I am client3
Enter a response message (type 'exit' to quit): hello client3


*/