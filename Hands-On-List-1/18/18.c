/*
============================================================================
Name : 18.c
Author : ANKIT SHARMA
Description : 
        18. Write a program to perform Record locking.
            Create three records in a file. Whenever you access a particular record, first lock it then modify/access
            to avoid race condition.
          
Date: 31st Aug, 2024.
============================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

struct Train {
  int train_no;
  int ticket_no;
};

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Missing arguments: Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  struct Train db[3];  // Array to store train data

  for (int i = 0; i < 3; i++) {
    db[i].train_no = i + 1;
    db[i].ticket_no = 0;
  }

  int fd = open(argv[1], O_RDWR | O_CREAT, 0666);
  if (fd == -1) {
    perror("Error opening the file");
    return 1;
  }

  ssize_t fd_write = write(fd, db, sizeof(db));
  if (fd_write == -1) {
    perror("Error writing into the file");
    close(fd);
    return 1;
  }

  int fd_close = close(fd);
  if (fd_close == -1) {
    perror("Error closing the file");
    return 1;
  }

  printf("File '%s' initialized with train data.\n", argv[1]);
  return 0;
}

/*
Output:
ankit-sharma@ankit-sharma:~/Practicals/18$ ./18 18.txt
File '18.txt' initialized with train data.


*/