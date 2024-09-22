/*
============================================================================
Name : 21_b.c
Author : ANKIT SHARMA
Description : 
        Write two programs so that both can communicate by FIFO -Use two way communications.

Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
   int fd1,fd2;
    char buf1[100],buf2[100];

    while(1)
    {
    fd1=open("myfifo1",O_RDONLY);
    read(fd1,buf1,sizeof(buf1));
    printf("Message received from 21_a: %s\n",buf1);
    close(fd1);

    printf("Enter message to send to 21_a: ");
    scanf(" %[^\n]", buf2);
    fd2=open("myfifo2",O_WRONLY);
    write(fd2, buf2, sizeof(buf2));
    close(fd2);
    }
}

/*
Output: ./21_b.c
Message received from 21_a: I am 21_a program
Enter message to send to 21_a: I am 21_b program
Message received from 21_a: I am 21_a program
Enter message to send to 21_a: I am 21_b program


*/