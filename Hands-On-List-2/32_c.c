/*
============================================================================
Name : 32_c.c
Author : ANKIT SHARMA
Description : 
        Write a program to implement semaphore to protect any critical section.
            a. rewrite the ticket number creation program using semaphore
            b. protect shared memory from concurrent write access
            c. protect multiple pseudo resources ( may be two) using counting semaphore
            d. remove the created semaphore

Date: 21st Sept, 2024.
============================================================================
*/
#include <sys/ipc.h>   
#include <sys/sem.h>   
#include <sys/types.h> 
#include <unistd.h>   
#include <fcntl.h> 
#include <stdio.h> 

void main(){
    char *filename = "sample.txt";
    char data[16]; // Sample data
      
    union semun{
        int val;           
    } semvar;

    int fd = open(filename,O_RDONLY);
    if(fd==-1){
      perror("Error while creating ticket file");
      return;
    }

    key_t key = ftok(".", 324);
    if(key==-1){
      perror("ftok returns");
      return;
    }

    int semid= semget(key,1,0);
    if(semid==-1){
      semid = semget(key,1,IPC_CREAT|0700);  
      if(semid==-1){
        perror("semget returns");
        return;
      }

      semvar.val = 2; // Set a counting semaphore
      int semctlflag = semctl(semid,0,SETVAL,semvar);
      if(semctlflag==-1){
        perror("semctl returns");
        return;
      }
    }

    struct sembuf semOp;
    semOp.sem_num = 0;
    semOp.sem_flg = IPC_NOWAIT;

    printf("Press enter to obtain lock for the critical section!\n");
    getchar();

    // Use semaphore to lock the critical section
    semOp.sem_op = -1;
    int semopflag = semop(semid,&semOp,1);
    if(semopflag==-1){
      perror("semop returns");
      return;
    }

    printf("Obtained lock on critical section!\n");
    printf("Now entering critical section!\n");

    int read_bytes = read(fd,&data,16);
    if(read_bytes==-1){
      perror("read returns");
      return;
    }
    else if(read_bytes==0)
       printf("No data exists!\n");
    else
       printf("Sample data:%s\n",data);
    
    printf("\nPress enter key to exit critical section!");
    getchar();

    // Use semaphore to unlock the critical section
    semOp.sem_op = 1;
    semopflag = semop(semid,&semOp,1);
    if(semopflag==-1){
      perror("Error while operating on semaphore!");
      return;
    }

    close(fd);
}


/*
Output:
Process1
ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./32_c
Press enter to obtain lock for the critical section!

Obtained lock on critical section!
Now entering critical section!
Sample data:Hello

Press enter key to exit critical section!

Process2
ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./32_c
Press enter to obtain lock for the critical section!

Obtained lock on critical section!
Now entering critical section!
Sample data:Hello

Press enter key to exit critical section!

Process3
ankit-sharma@ankit-sharma:~/cs-513-system-software/Hands-On-List-2$ ./32_c
Press enter to obtain lock for the critical section!

semop returns: Resource temporarily unavailable

i.e Process3 cannot enter critical section when already 2 processes are already accessing sample.txt file


*/