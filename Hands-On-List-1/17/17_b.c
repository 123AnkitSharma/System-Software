/*
============================================================================
Name : 17_b.c
Author : ANKIT SHARMA
Description : 
        17. Write a program to simulate online ticket reservation. Implement write lock
            Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print
            the new ticket number then close the file.
          
Date: 31st Aug, 2024.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h> 


int main() {
// creating Ticket structure
struct flock lock;
int fd;

struct {
int ticket_no;
} Ticket;
//opening Ticket.txt file
fd = open("Ticket.txt", O_RDWR);
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

//Implementing mandatory lock on Ticket.txt file 
printf("Before entering into critical section\n");
fcntl(fd, F_SETLKW, &lock);
printf("Inside the critical section\n");
// Reading Ticket.txt file data
read(fd, &Ticket, sizeof(Ticket));
printf("Current ticket number: %d\n", Ticket.ticket_no);
Ticket.ticket_no++; // to increment ticket number
// to reposition file pointer to the beginning of Ticket.txt file
lseek(fd, 0, SEEK_SET);
write(fd, &Ticket, sizeof(Ticket));
printf("new ticket number: %d\n",Ticket.ticket_no);
printf("Press enter to unlock\n");
getchar();
// Unlock the file
lock.l_type = F_UNLCK;
fcntl(fd, F_SETLK, &lock);
printf("Exited critical section\n");
}

/*
Output:
Process1:
ankit-sharma@ankit-sharma:~/Practicals/17$ ./17_b
Before entering into critical section
Inside the critical section
Current ticket number: 20
new ticket number: 21
Press enter to unlock

Process2:
ankit-sharma@ankit-sharma:~/Practicals/17$ ./17_b
Before entering into critical section

*/