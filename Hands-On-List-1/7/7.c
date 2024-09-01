/*
============================================================================
Name : 7.c
Author : ANKIT SHARMA
Description : 
        7. Write a program to copy file1 into file2 ($cp file1 file2).
          
Date: 31st Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int file1 = open(argv[1], O_RDONLY);
    if (file1 < 0)
    {
        perror("program");
        exit(0);
    }
    int file2 = open(argv[2], O_WRONLY | O_CREAT, 0600);
    if (file2 < 0)
    {
        perror("program");
        exit(0);
    }
    char buffer[100];
    int size_read;

    while ((size_read = read(file1, buffer, sizeof(buffer)))> 0)
    {
        write(file2, buffer, size_read);
    }

    close(file1);
    close(file2);

    return 0;
}


/*

ankit-sharma@ankit-sharma:~/Practicals/7$ ./7 source.txt dest.txt 

Source file text: 
A Glimpse into the Abyss: The Dark Side of Artificial Intelligence

Artificial Intelligence (AI) has emerged as one of the most transformative technologies of our time.

Destination file text:
A Glimpse into the Abyss: The Dark Side of Artificial Intelligence

Artificial Intelligence (AI) has emerged as one of the most transformative technologies of our time.

*/