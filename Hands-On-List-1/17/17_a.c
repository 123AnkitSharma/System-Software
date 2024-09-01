/*
============================================================================
Name : 17_a.c
Author : ANKIT SHARMA
Description : 
        17. Write a program to simulate online ticket reservation. Implement write lock
            Write a program to open a file, store a ticket number and exit.
          
Date: 31st Aug, 2024.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h> 


int main() {
int fd;
struct {
int ticket_no;
} Ticket;
Ticket.ticket_no = 20;
//opening Ticket.txt file and creating it if not exist.
fd = open("Ticket.txt", O_CREAT|O_RDWR, 0744);
write(fd, &Ticket, sizeof(Ticket));
printf("Ticket no: %d\n", Ticket.ticket_no);
close(fd);
}


/*
Output:
ankit-sharma@ankit-sharma:~/Practicals/17$ ./17_a
Ticket no: 20

*/