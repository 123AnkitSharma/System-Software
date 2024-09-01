/*
============================================================================
Name : 1_a.c
Author : ANKIT SHARMA
Description : 
        1. Create the following types of a files using (ii) system call
                a. soft link (symlink system call)
          
Date: 31st Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    if (symlink("1_org.txt", "1_org_softlink_using_c_file")) {
        perror("softlink not created properly !");
        return 1;
    }

    printf("Softlink created successfully.\n");
    return 0;
}

/*

Output:-
lrwxrwxrwx 1 ankit-sharma ankit-sharma     9 Aug 27 18:28 1_org_softlink_using_c_file -> 1_org.txt

*/




