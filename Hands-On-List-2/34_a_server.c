/*
============================================================================
Name : 34_a_server.c
Author : ANKIT SHARMA
Description : 
        Write a program to create a concurrent server.
            a. use fork

Date: 21st Sept, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
void main()
{
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd == -1)
    {
        perror("Error when creating socket");
    }
    printf("Server Socket created\n");

    // server information
    struct sockaddr_in server, client;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_family = AF_INET;
    server.sin_port = htons(5002);

    int bindS = bind(sd, (struct sockaddr *)&server, sizeof(server));
    if (bindS == -1)
    {
        perror("Error while binding name to socket!");
        _exit(0);
    }
    printf("Binding to server socket was successful!\n");

    // listening for client connection
    int listenS = listen(sd, 3);
    if (listenS == -1)
    {
        perror("Error while trying to listen to Connections");
        _exit(0);
    }
    printf("Listening from client connection \n");

    while (1)
    {
        int client_size = (int)sizeof(client);
        int nsd = accept(sd, (struct sockaddr *)&client, &client_size);
        if (nsd == -1)
        {
            perror("Error while accepting Connection\n");
            _exit(0);
        }
        else
        {
            if (fork() == 0)
            {
                // In child
                char buf[100];

                read(nsd, buf, 100);
                printf("Data received from client : %s\n",buf);

                printf("Enter message which server wants to send to client: \n");
                scanf("%[^\n]", buf);
                write(nsd, buf, sizeof(buf));

            }
            else
            {
                // parent
                // close nsd for client
                close(nsd);
            }
        }
    }

    close(sd);
}

/*
Output:
ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./34_a_server 
Server Socket created
Binding to server socket was successful!
Listening from Connection 
Data from client : I am client1
Enter message which server wants to send to client: 
Hello client1
Data from client : I am client2
Enter message which server wants to send to client: 
Hello client2
Data from client : I am client3
Enter message which server wants to send to client: 
Hello client3

*/