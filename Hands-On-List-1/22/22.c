/*
============================================================================
Name : 22.c
Author : ANKIT SHARMA
Description : 
        22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
            parent processes. Check output of the file.
          
Date: 31st Aug, 2024.
============================================================================
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    char *fname="./demo.txt";
    int Child_pid,fd;
    fd=open(fname, O_WRONLY|O_CREAT,0744);
    Child_pid=fork();
    if(Child_pid!=0)
    {
        write(fd,"I am Parent process\n",20);
    }
    else
        {
            write(fd,"I am Child process\n",19);
        }
        close(fd);
    return 0;
}

/*
Output:
demo.txt file content:
I am Parent process
I am Child process

*/