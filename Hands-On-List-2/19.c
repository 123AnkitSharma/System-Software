/*
============================================================================
Name : 19.c
Author : ANKIT SHARMA
Description : 
        Create a FIFO file by
            a. mknod command
            b. mkfifo command
            c. use strace command to find out, which command (mknod or mkfifo) is better.
            d. mknod system call
            e. mkfifo library function

Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
int main()
{
    int result_1 = mkfifo("myfifo1", 0744);
    if (result_1 == 0)
    {
        printf("fifo special file has been created using mkfifo\n");
    }

    int result_2 = mknod("myfifo2", S_IFIFO | 0744, 0);
    if (result_2 == 0)
    {
        printf("fifo special file has been created using mknod");
    }
}

/*
Output: ./19
fifo special file has been created using mkfifo
fifo special file has been created using mknod
*/