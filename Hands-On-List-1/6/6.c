/*
============================================================================
Name : 6.c
Author : ANKIT SHARMA
Description : 
        6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
          
Date: 31st Aug, 2024.
============================================================================
*/


#include<unistd.h>

int main()
{
    int n;
    char buf[100];
    n=read(0,buf,50);
    write(1,buf,n);
}


/*
Output:
ankit-sharma@ankit-sharma:~/Practicals/6$ ./6
I am standard input terminal
I am standard input terminal

*/