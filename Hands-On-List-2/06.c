/*
============================================================================
Name : 06.c
Author : ANKIT SHARMA
Description : 
        Write a simple program to create three threads.

Date: 21st Sept, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * thread_func()
{
    printf("Thread Created Sucessfully!\n");
}


int main()
{
    pthread_t thread_1,thread_2,thread_3;
    pthread_create(&thread_1,NULL,thread_func,NULL);
    pthread_create(&thread_2,NULL,thread_func,NULL);
    pthread_create(&thread_3,NULL,thread_func,NULL);
    pthread_join(thread_1,NULL);
    pthread_join(thread_2,NULL);
    pthread_join(thread_3,NULL);
    printf("All the three threads have finished their execution.\n");

}

/*
Output: ./06
Thread Created Sucessfully!
Thread Created Sucessfully!
Thread Created Sucessfully!
All the three threads have finished their execution.

*/