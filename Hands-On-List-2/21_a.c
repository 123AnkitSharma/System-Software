/*
============================================================================
Name : 21_a.c
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
    mkfifo("myfifo1",0777);
    mkfifo("myfifo2",0777);
    while(1)
    {
        printf("Enter message to send to 21_b: ");
        scanf(" %[^\n]", buf1);
        fd1=open("myfifo1",O_WRONLY);
        write(fd1, buf1, sizeof(buf1));
        close(fd1);

        fd2=open("myfifo2",O_RDONLY);
        read(fd2,buf2,sizeof(buf2));
        printf("Message received from 21_b: %s\n",buf2);
        close(fd2);
    }
}


/*
Output: ./21_a.c
Enter message to send to 21_b: I am 21_a program
Message received from 21_b: I am 21_b program
Enter message to send to 21_b: I am 21_a program
Message received from 21_b: I am 21_b program
Enter message to send to 21_b:

*/