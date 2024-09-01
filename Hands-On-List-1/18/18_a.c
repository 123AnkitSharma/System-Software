/*
============================================================================
Name : 18_a.c
Author : ANKIT SHARMA
Description : 
        18. Write a program to perform Record locking.
            a. Implement write lock
            Create three records in a file. Whenever you access a particular record, first lock it then modify/access
            to avoid race condition.
          
Date: 31st Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct Train {
    int train_no;
    int ticket_no;
};

int main() {
    int fd, input;
    fd = open("18.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    printf("Select train number: 1, 2, 3\n");
    scanf("%d", &input);

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (input - 1) * sizeof(struct Train);
    lock.l_len = sizeof(struct Train);
    lock.l_pid = getpid();
    printf("Before entering critical section\n");
    // Apply write lock to the selected train's record
    fcntl(fd, F_SETLKW, &lock);

    // Read the current ticket count
    struct Train train;
    lseek(fd, (input - 1) * sizeof(struct Train), SEEK_SET);
    read(fd, &train, sizeof(struct Train));
    
    printf("Current ticket count is: %d\n", train.ticket_no);

    train.ticket_no++;

    // Write the updated ticket count back to the file
    lseek(fd, -1 * sizeof(struct Train), SEEK_CUR);
    write(fd, &train, sizeof(struct Train));
    printf("To book ticket, press enter\n");
    getchar();
    getchar();
    printf("Unlocked\n");

    // Release the lock
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Booked ticket number is: %d\n", train.ticket_no);

    close(fd);
    return 0;
}


/*
Output:
Process1:
ankit-sharma@ankit-sharma:~/Practicals/18$ ./18_a
Select train number: 1, 2, 3
2
Before entering critical section
Current ticket count is: 0
To book ticket, press enter

Process2:
ankit-sharma@ankit-sharma:~/Practicals/18$ ./18_a
Select train number: 1, 2, 3
2
Before entering critical section

*/