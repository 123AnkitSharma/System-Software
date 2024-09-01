/*
============================================================================
Name : 9.c
Author : ANKIT SHARMA
Description : 
        9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
          
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat file_info;
    if (stat(argv[1], &file_info) == -1) {
        perror("stat");
        return 1;
    }

    printf("Inode: %ld\n", file_info.st_ino);
    printf("Number of hard links: %ld\n", file_info.st_nlink);
    printf("UID: %d\n", file_info.st_uid);
    printf("GID: %d\n", file_info.st_gid);
    printf("Size: %ld bytes\n", file_info.st_size);
    printf("Block size: %ld bytes\n", file_info.st_blksize);
    printf("Number of blocks: %ld\n", file_info.st_blocks);
    printf("Time of last access: %s", ctime(&file_info.st_atime));
    printf("Time of last modification: %s", ctime(&file_info.st_mtime));
    printf("Time of last change: %s", ctime(&file_info.st_ctime));

    return 0;
}

/*
ankit-sharma@ankit-sharma:~/Practicals/9$ ./9 myfile.txt 
Inode: 1062921
Number of hard links: 1
UID: 1000
GID: 1000
Size: 0 bytes
Block size: 4096 bytes
Number of blocks: 0
Time of last access: Sun Sep  1 19:57:48 2024
Time of last modification: Sun Sep  1 19:57:48 2024
Time of last change: Sun Sep  1 19:57:48 2024

*/