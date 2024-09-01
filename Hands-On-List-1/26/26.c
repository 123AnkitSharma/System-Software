/*
============================================================================
Name : 26.c
Author : ANKIT SHARMA
Description : 
        26. Write a program to execute an executable program.
            a. use some executable program
            b. pass some input to an executable program. (for example execute an executable of $./a.out name)
          
Date: 31st Aug, 2024.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>

int main() {
    char* arg[] ={"./26_demo",NULL};

    execvp("./26_demo",arg);

    return 0;
}


/*
Output:
ankit-sharma@ankit-sharma:~/Practicals/26$ ./26 26_demo
Pass two numbers to add
4
7
Sum of two numbers: 11

*/