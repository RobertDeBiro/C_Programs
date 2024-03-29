/*
 * Create FIFO file for one-way communication
   - one process will be in charge for writing to FIFO file and other for reading from it
     - in this example our "Open_WriteOnly.c" program will write to FIFO, and our terminal 'cat'
       command (program) will read from FIFO
   - when we use 'WRONLY' flag, our FIFO file is opened inside our code for writing, but not for reading
     - in other words, we opened only one side of our pipe, we created only one file descriptor
     - function 'open()' will return file descriptor value only when full pipe is opened i.e. when our
       other pipe end exists (when 'cat' command is executed in terminal)
   - this program is equivalent to "Process_communication-Pipe/Two_processes-One_way_comm.c" program
   - execution steps:
     1. VSCode: Run program
       - creates "myfifo1" fifo file with "777" permissions
     2. Terminal: Go to "FIFOs" directory and run 'cat' command
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> // mkfifo
#include <sys/stat.h> // mkfifo
#include <errno.h> // errno
#include <fcntl.h> // open

int main(int argc, char* argv[]) {
    printf("***************************************\n");

    if (mkfifo("FIFOs/myfifo1", 0777) == -1) {
        if (errno != EEXIST) {
            printf("Could not create fifo file\n");
            return 1;
        }
    }

    printf("Opening...\n");

    // Open file and write to it
    //  - 'O_WRONLY' - Open_WriteOnly
    int fd = open("FIFOs/myfifo1", O_WRONLY);
    if (fd == -1) {
        printf("Couldn't open the fifo file!\n");
        return 2;
    }

    printf("Opened\n");

    int x = 97; // 'x' will be written as ASCII code 'a'
    if (write(fd, &x, sizeof(x)) == -1) {
        printf("Could not write into fifo file\n");
        return 3;
    }

    char str[] = {"\nFifo opened\n"};
    int str_size = sizeof(str) / sizeof(str[0]);
    if (write(fd, str, str_size) == -1) {
        printf("Could not write into fifo file\n");
        return 3;
    }
    printf("Written\n");

    close(fd);
    printf("Closed\n");

    printf("---------------------------------------\n");
    return 0;
}