/*
 * Two process communication by using one pipe
   - by using one pipe we can define that communication between processes goes in only one direction
   - in this example child process write data to pipe, and parent process read that data from pipe
     i.e. we are sending data from child process to parent process
 */

#include <stdio.h>
#include <unistd.h> // fork, pipe, write, read, close

int main(int argc, char* argv[]) {
    printf("***************************************\n");

    // This is normal integer array
    // - after 'fd' is send to 'pipe()' its elements become file descriptors
    int fd[2];

    if (pipe(fd) == -1) {
        printf("An error ocurred with opening the pipe");
        return 1;
    }

    int id = fork();
    if (id == -1) {
        printf("An error occured with fork()\n");
        return 2;
    }

    if (id == 0)
    {
        // We won't read from pipe in this process, so we are closing that file descriptor
        close (fd[0]);
        
        int x;
        printf("Input a number: ");
        scanf("%d", &x);
        // Read something from a variable and after 3 seconds write that to the pipe
        sleep(3);
        // 'write' command doesn't have to wait that 'read' command is executed in another process
        if (write(fd[1], &x, sizeof(x)) == -1) {
            printf("An error occured with writing to the pipe\n");
            return 3;
        }
        close (fd[1]);
    }
    else
    {
        // We won't write to the pipe in this process, so we are closing that file descriptor
        close (fd[1]);

        int y;
        // Read something from the pipe and write that to a variable
        //  - 'read' command waits that actually something is written to the 'fd[0]'
        //  - hence, in this example it would wait for 3 seconds
        if (read(fd[0], &y, sizeof(y)) == -1) {
            printf("An error occured with reading from the pipe\n");
            return 4;
        }
        y = y * 3;
        close (fd[0]);
        printf("Got from child process %d\n", y);
    }

    printf("---------------------------------------\n");
    return 0;
}