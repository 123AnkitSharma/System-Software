/*
============================================================================
Name : 5.c
Author : ANKIT SHARMA
Description : 
        5. Write a program to create five new files with infinite loop. Execute the program in the background
           and check the file descriptor table at /proc/pid/fd.
          
Date: 31st Aug, 2024.
============================================================================
*/

#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd1,fd2,fd3,fd4,fd5;

    fd1=creat("new_file1.txt",0700);
    fd2=creat("new_file2.txt",0700);
    fd3=creat("new_file3.txt",0700);
    fd4=creat("new_file4.txt",0700);
    fd5=creat("new_file5.txt",0700);

    while(1);

    return 0;
}

/*

Output:-
ankit-sharma@ankit-sharma:~/Practicals/5$ ls -l /proc/9545/fd
total 0
lrwx------ 1 ankit-sharma ankit-sharma 64 Sep  1 19:46 0 -> /dev/pts/0
lrwx------ 1 ankit-sharma ankit-sharma 64 Sep  1 19:46 1 -> /dev/pts/0
lrwx------ 1 ankit-sharma ankit-sharma 64 Sep  1 19:46 2 -> /dev/pts/0
l-wx------ 1 ankit-sharma ankit-sharma 64 Sep  1 19:46 3 -> /home/ankit-sharma/Practicals/5/new_file1.txt
l-wx------ 1 ankit-sharma ankit-sharma 64 Sep  1 19:46 4 -> /home/ankit-sharma/Practicals/5/new_file2.txt
l-wx------ 1 ankit-sharma ankit-sharma 64 Sep  1 19:46 5 -> /home/ankit-sharma/Practicals/5/new_file3.txt
l-wx------ 1 ankit-sharma ankit-sharma 64 Sep  1 19:46 6 -> /home/ankit-sharma/Practicals/5/new_file4.txt
l-wx------ 1 ankit-sharma ankit-sharma 64 Sep  1 19:46 7 -> /home/ankit-sharma/Practicals/5/new_file5.txt


*/