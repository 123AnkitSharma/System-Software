/*
============================================================================
Name : 24.c
Author : ANKIT SHARMA
Description : 
        24. Write a program to create an orphan process.
          
Date: 31st Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main()
{

    printf("parentid: %d\n",getpid());
    int child_pid=fork();

    if(child_pid==-1)
    {
        perror("fork() error!");
        return 1;
    }

    if(child_pid==0)
    {     int cpid;
        printf("I am child process, my parent %d has left me.\n",getppid());
        cpid=getppid();
        sleep(3);
        printf("Child process finished sleeping\n");
        printf("Child process is assigned to some other Parent: %d\n",getppid());
        if(getppid()!=cpid){
            printf("Child process has become orphan\n");
        }     
    }

    else
    {
        printf("I am the parent process and my pid: %d\n",getpid());
        printf("Exiting Parent!\n");
    }

    return 0;
}

/*
Output:
ankit-sharma@ankit-sharma:~/Practicals/24$ ./24
parentid: 14654
I am the parent process and my pid: 14654
Exiting Parent!
I am child process, my parent 14654 has left me.
ankit-sharma@ankit-sharma:~/Practicals/24$ Child process finished sleeping
Child process is assigned to some other Parent: 1916
Child process has become orphan


*/