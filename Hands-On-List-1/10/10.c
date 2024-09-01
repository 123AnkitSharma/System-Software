/*
============================================================================
Name : 10.c
Author : ANKIT SHARMA
Description : 
        10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
            bytes (use lseek) and write again 10 bytes.
            a. check the return value of lseek
            b. open the file with od and check the empty spaces in between the data.
          
Date: 31st Aug, 2024.
============================================================================
*/

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
    int fd,n,offset;
    char p[10]="abcdefghij";
    fd= open("output.txt",O_RDWR|O_CREAT,0744);
    write(fd,p,10);
    offset=lseek(fd,10,SEEK_CUR);
    printf("lseek offset: %d\n",offset);
    write(fd,p,10);
    offset=lseek(fd,0,SEEK_CUR);
    printf("lseek offset: %d\n",offset);
    close(fd);

    return 0;
}


/*
Output:-
ankit-sharma@ankit-sharma:~/Practicals/10$ ./10
lseek offset: 20
lseek offset: 30

ankit-sharma@ankit-sharma:~/Practicals/10$ od -c output.txt 
0000000   a   b   c   d   e   f   g   h   i   j  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   a   b   c   d   e   f   g   h   i   j
0000036

*/