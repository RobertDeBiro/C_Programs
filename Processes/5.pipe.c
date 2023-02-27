// Communication between 2 processes
//  - send data from child process to parent process

#include <stdio.h>
#include <unistd.h> // fork, pipe, write

int main(int argc, char* argv[]) {
    int fd[2]; // This is normal integer array
    // After fd is send to pipe() its elements become file descriptors
    //  - fd[0] is always for reading from pipe
    //  - fd[1] is always for writting to pipe
    if (pipe(fd) == -1) {
        printf("An error ocurred with opening the pipe");
        return 1;
    }

    int id = fork();
    if (id == -1) {
        printf("An error occured with fork()\n");
        return 2;
    }

    if (id == 0) {
        close (fd[0]); // We won't read from pipe in this process, so we are closing that file descriptor
        int x;
        printf("Input a number: ");
        scanf("%d", &x);
        // Read something from a variable and write that to the pipe
        if (write(fd[1], &x, sizeof(x)) == -1) {
            printf("An error occured with writing to the pipe\n");
            return 3;
        }
        close (fd[1]);
    } else {
        close (fd[1]); // We won't write to the pipe in this process, so we are closing that file descriptor
        int y;
        // Read something from the pipe and write that to a variable
        if (read(fd[0], &y, sizeof(y)) == -1) {
            printf("An error occured with reading from the pipe\n");
            return 4;
        }
        y = y * 3;
        close (fd[0]);
        printf("Got from child process %d\n", y);
    }
    return 0;
}