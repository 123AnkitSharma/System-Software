/*
============================================================================
Name : 33_client.c
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
    int sd=socket(AF_UNIX,SOCK_STREAM,0);
    if(sd==-1){
        perror("Error when creating socket");
    }
    printf("Socket is created successfully\n");

    // assigning server info
    struct sockaddr_in address;
    address.sin_addr.s_addr=htonl(INADDR_ANY);
    address.sin_family=AF_UNIX;
    address.sin_port=htons(5004);

    //make connection to the server
    int connectionS = connect(sd, (struct sockaddr *)&address, sizeof(address));

    if(connectionS==-1){
        perror("Error while establishing Connection");
        exit(0);
    }
    
    printf("Connection with server established\n");

    char buf[100];
     printf("Enter message which client wants to send to server: ");
    scanf("%[^\n]",buf);

    write(sd,buf,sizeof(buf));
    //reading from server
    read(sd,buf,100);
    printf("Data from server: %s\n",buf);

   

    close(sd);
}

/*
Output:
ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./33_client
Socket is created successfully
Connection with server established
Enter message which client wants to send to server: I am client can you accept my connection request server ?
Data from server: Yes client I have accepted your connection request

*/
