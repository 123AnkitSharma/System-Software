/*
============================================================================
Name : 1_b.c
Author : ANKIT SHARMA 
Description : 
        1. Create the following types of a files using (ii) system call
                b. hard link (link system call)

Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    if (link("1_org.txt", "1_org_hardlink_using_c_file")) {
        perror("Hardlink error !");
        return 1;
    }

    printf("Hardlink created successfully.\n");
    return 0;
}

/*

Output:-
-rw-rw-r-- 3 ankit-sharma ankit-sharma    36 Aug 27 17:19 1_org_hardlink_using_c_file

*/