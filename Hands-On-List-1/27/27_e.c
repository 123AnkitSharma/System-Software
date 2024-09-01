/*
============================================================================
Name : 27_e.c
Author : ANKIT SHARMA
Description : 
        27. Write a program to execute ls -Rl by the following system calls
            e. execvp
          
Date: 31st Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    char *argv[] = {"ls", "-R", "-l", "./27_dir", NULL};
    
    printf("Executing using execvp :\n");
    execvp("/bin/ls", argv);
    return 0;
}


/*
Output:
ankit-sharma@ankit-sharma:~/Practicals/27$ ./27_e
Executing using execvp :
./27_dir:
total 12
drwxrwxr-x 2 ankit-sharma ankit-sharma 4096 Aug 31 20:19 1
drwxrwxr-x 2 ankit-sharma ankit-sharma 4096 Aug 31 20:19 2
drwxrwxr-x 2 ankit-sharma ankit-sharma 4096 Aug 31 20:19 3

./27_dir/1:
total 0
-rw-rw-r-- 1 ankit-sharma ankit-sharma 0 Aug 31 20:19 1.txt

./27_dir/2:
total 0
-rw-rw-r-- 1 ankit-sharma ankit-sharma 0 Aug 31 20:19 2.txt

./27_dir/3:
total 0
-rw-rw-r-- 1 ankit-sharma ankit-sharma 0 Aug 31 20:19 3.txt


*/