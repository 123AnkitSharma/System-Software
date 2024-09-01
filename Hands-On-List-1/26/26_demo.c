/*
============================================================================
Name : 26_demo.c
Author : ANKIT SHARMA
Description : 
        26. Write a program to execute an executable program.
            a. use some executable program
            b. pass some input to an executable program. (for example execute an executable of $./a.out name)
          
Date: 31st Aug, 2024.
============================================================================
*/
#include<stdio.h>

int main()
{
    int a,b;
    printf("Pass two numbers to add\n");
    scanf("%d%d",&a,&b);
    printf("Sum of two numbers: %d",a+b);
    return 0;
}