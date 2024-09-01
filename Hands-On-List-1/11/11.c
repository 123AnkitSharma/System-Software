/*
============================================================================
Name : 11.c
Author : ANKIT SHARMA
Description : 
        11. Write a program to open a file, duplicate the file descriptor and append the file with both the
            descriptors and check whether the file is updated properly or not.
            a. use dup
            b. use dup2
            c. use fcntl
          
Date: 31st Aug, 2024.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
    int fd1,fd2,fd3,fd4;
    fd1=open("dummy.txt",O_WRONLY|O_APPEND);
    printf("Old fd: %d\n",fd1);
    fd2=dup(fd1);
    printf("New fd using dup(): %d\n",fd2);
    fd3=dup2(fd1,8);
    printf("New fd using dup2(): %d\n",fd3);
    fd4=fcntl(fd1,F_DUPFD,6); //creates duplicate fd >=6 
    printf("New fd using fcntl(): %d\n",fd4);
    write(fd1,"fd1 helped me to write down!\n",29);   
    write(fd2,"fd2 helped me to write down using dup()!\n",41);
    write(fd3,"fd3 helped me to write down dup2()!\n",36);
    write(fd4,"fd4 helped me to write down fcntl()!",36);
    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);

    return 0;
    
}


/*
Output:-
ankit-sharma@ankit-sharma:~/Practicals/11$ ./11
Old fd: 3
New fd using dup(): 4
New fd using dup2(): 8
New fd using fcntl(): 6

dummy.txt file content:-
fd1 helped me to write down!
fd2 helped me to write down using dup()!
fd3 helped me to write down dup2()!
fd4 helped me to write down fcntl()!



*/