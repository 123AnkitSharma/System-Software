/*
============================================================================
Name : 07.c
Author : ANKIT SHARMA
Description : 
        Write a simple program to print the created thread ids.

Date: 21st Sept, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * thread_func(void * th_id)
{
    int id=*(long int *)th_id;
    printf("Thread %d created sucessfully!\n",id);
    pthread_exit(NULL);
}


int main()
{
    pthread_t thread_1,thread_2,thread_3;
    int num[3]={01,02,03};
    pthread_create(&thread_1,NULL,thread_func,&num[0]);
    pthread_create(&thread_2,NULL,thread_func,&num[1]);
    pthread_create(&thread_3,NULL,thread_func,&num[2]);
    pthread_join(thread_1,NULL);
    pthread_join(thread_2,NULL);
    pthread_join(thread_3,NULL);
    printf("All the three threads have finished their execution.\n");

}

/*
Output: ./07
Thread 1 created sucessfully!
Thread 2 created sucessfully!
Thread 3 created sucessfully!
All the three threads have finished their execution.

*/