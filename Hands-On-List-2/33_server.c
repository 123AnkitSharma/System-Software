/*
============================================================================
Name : 33_server.c
Author : ANKIT SHARMA
Description : 
        Write a program to communicate between two machines using socket.

Date: 21st Sept, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main()
{
    int sd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sd == -1)
    {
        perror("Error when creating socket");
    }
    printf("Server Socket created\n");

    // information about server
    struct sockaddr_in server, client;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_family = AF_UNIX;
    server.sin_port = htons(5004);

    int bindS = bind(sd, (struct sockaddr *)&server, sizeof(server));
    if (bindS == -1)
    {
        perror("Error while binding name to socket!");
        exit(0);
    }
    printf("Binding to server socket was successful!\n");

    // server is listening for client connection
    int listenS = listen(sd, 2);
    if (listenS == -1)
    {
        perror("Error while trying to listen to Connections");
        exit(0);
    }
    printf("server is listening for client connection\n");

    int client_size = (int)sizeof(client);
    int nsd = accept(sd, (struct sockaddr *)&client, &client_size);
    if (nsd == -1)
    {
        perror("Error while accepting Connection");
        exit(0);
    }
    else
    {
        char buf[100];
        read(nsd, buf, 100);
        printf("Data from client: %s\n", buf);
        printf("Write message which server wants to send to client: ");
        scanf("%[^\n]", buf);
        // write fron server to connection fd
        write(nsd, buf, sizeof(buf));

        
    }

    // closing socket
    close(sd);
}


/*
Output:
ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./33_server
Server Socket created
Binding to server socket was successful!
server is listening for client connection
Data from client: I am client can you accept my connection request server ?
Write message which server wants to send to client: Yes client I have accepted your connection request

*/