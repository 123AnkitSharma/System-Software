/*
============================================================================
Name : 8.c
Author : ANKIT SHARMA
Description : 
        8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
           Close the file when end of file is reached.
          
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE* fd;
    char b[100];
    fd = fopen("source.txt","r");

    if(fd<0){
    perror("Error ");
    }
    while(fgets(b,sizeof(b),fd)){
        printf("%s",b);
    }
    fclose(fd);
}


/*
Output:
ankit-sharma@ankit-sharma:~/Practicals/8$ ./8
The Beach House,
The sun painted the sky in hues of orange and pink, casting long shadows across the deserted beach. I stood at the water's edge, the cool sand beneath my feet. 
It had been a tumultuous year. I'd lost my job, broken up with my partner, and felt like I was drowning in a sea of uncertainty.
I remembered the old beach house my grandmother used to take me to as a child. 
With a newfound determination, I decided to pack my bags and head to the beach house.

*/
