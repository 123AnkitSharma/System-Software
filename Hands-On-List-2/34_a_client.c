/*
============================================================================
Name : 34_a_client.c
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
        _exit(0);
    }
    printf("Socket created\n");

    // assigning server info
    struct sockaddr_in address;
    address.sin_addr.s_addr = htonl(INADDR_ANY); // host to network short
    address.sin_family = AF_INET;
    address.sin_port = htons(5002);

    // make connection to the server
    int connectionS = connect(sd, (struct sockaddr *)&address, sizeof(address));

    if (connectionS == -1)
    {
        perror("Error while establishing Connection\n");
        _exit(0);
    }

    printf("Connection of client with server is established successfully\n");

    char buf[100];

    printf("Enter message which client wants to send to server: \n");
    scanf("%[^\n]", buf);
    write(sd, buf, sizeof(buf));

    read(sd, buf, 100);
    printf("Data received from server: %s\n", buf);

  

    close(sd);
}

/*
Output:
ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./34_a_client
Socket created
Connection of client with server is established successfully
Enter message which client wants to send to server: 
I am client1
Data received from server: Hello client1

ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./34_a_client
Socket created
Connection of client with server is established successfully
Enter message which client wants to send to server: 
I am client2
Data received from server: Hello client2

ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./34_a_client
Socket created
Connection of client with server is established successfully
Enter message which client wants to send to server: 
I am client3
Data received from server: Hello client3

*/