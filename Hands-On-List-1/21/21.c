/*
============================================================================
Name : 21.c
Author : ANKIT SHARMA
Description : 
        21. Write a program, call fork and print the parent and child process id.
          
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    
    int pid=getpid();
    printf("Parent_pid: %d\n",pid);

    int child_pid = fork();

    if (pid < 0) {
        perror("fork failure!");
        return 1;
    } 

    if(child_pid!=0){  
         printf("Child pid: %d\n",child_pid);
    }

    return 0;
}


/*
Output:
ankit-sharma@ankit-sharma:~/Practicals/21$ ./21
Parent_pid: 14120
Child pid: 14121


*/