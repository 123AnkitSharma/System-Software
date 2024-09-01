/*
============================================================================
Name : 14.c
Author : ANKIT SHARMA
Description : 
        14 Write a program to find the type of a file.
            a. Input should be taken from command line.
            b. program should be able to identify any type of a file.
          
Date: 31st Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("please provide exactly one filename");
        return 1;
    }

    struct stat fileinfo;
    if (stat(argv[1], &fileinfo) == -1) {
        perror("stat() error occured");
        return 1;
    }

    if (S_ISREG(fileinfo.st_mode)) {
        printf("regular file\n");
    } else if (S_ISDIR(fileinfo.st_mode)) {
        printf("directory\n");
    } else if (S_ISCHR(fileinfo.st_mode)) {
        printf("character device\n");
    } else if (S_ISBLK(fileinfo.st_mode)) {
        printf("block file\n");
    } else if (S_ISFIFO(fileinfo.st_mode)) {
        printf("fifo file\n");
    } else if (S_ISLNK(fileinfo.st_mode)) {
        printf("symbolic link\n");
    } else if (S_ISSOCK(fileinfo.st_mode)) {
        printf("socket\n");
    } else {
        printf("unknown file\n");
    }

    return 0;
}

/*
Output:
ankit-sharma@ankit-sharma:~/Practicals/14$ ./14 a
directory
ankit-sharma@ankit-sharma:~/Practicals/14$ ./14 a.txt 
regular file

*/