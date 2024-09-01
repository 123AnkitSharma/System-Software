/*
============================================================================
Name : 13.c
Author : ANKIT SHARMA
Description : 
        13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
            verify whether the data is available within 10 seconds or not (check in $man 2 select).
          
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>

int main() {
    fd_set read_fds;
    struct timeval timeover;
    int select_retVal;

    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);

    /* Set the timeout to 10 seconds */
    timeover.tv_sec = 10;
    timeover.tv_usec = 0;

    select_retVal = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeover);

    if (select_retVal == -1)
    {
        perror("select call error!");
        return 1;
    } 
    
    else if (select_retVal == 0) 
    {
        printf("TimeOut occured, No data is received within 10 seconds.\n");
    }
    
     else 
    {
        printf("Data is available within 10 seconds.\n");
    }

    return 0;
}


/*
Output:
ankit-sharma@ankit-sharma:~/Practicals/13$ ./13
TimeOut occured, No data is received within 10 seconds.

ankit-sharma@ankit-sharma:~/Practicals/13$ ./13
Hello Friends
Data is available within 10 seconds.

*/