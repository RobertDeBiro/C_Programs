/*
 * Sending data within one process by using pipe
 */

#include <stdio.h>
#include <unistd.h> // fork, pipe, write, read, close

int main(int argc, char* argv[]) {
    printf("***************************************\n");

    int fd[2]; 
    if (pipe(fd) == -1) {
        printf("An error ocurred with opening the pipe");
        return 1;
    }   
        
    int x;
    printf("Input a number: ");
    scanf("%d", &x);
    if (write(fd[1], &x, sizeof(x)) == -1) {
        printf("An error occured with writing to the pipe\n");
        return 3;
    }

    printf("Executing anything in order to show that 'read' will be valid...\n");

    int y;
    if (read(fd[0], &y, sizeof(y)) == -1) {
        printf("An error occured with reading from the pipe\n");
        return 4;
    }
    y = y * 3;
    printf("Got from child process %d\n", y);

    // If we don't close the descriptor, it will be everything fine in this program, but it is a good
    // practice to close it because in other programs it may be needed
    close (fd[0]);
    close (fd[1]);

    printf("---------------------------------------\n");
    return 0;
}