/*
 * Create FIFO file for two-way communication
   - one process will be in charge both for reading and writing to FIFO file
     - in this example our "Open_ReadWrite.c" program will write and read FIFO file
   - when we open FIFO file as 'RDWR', open function returns file descriptor that is able to be used
     both for reading and writing i.e. in functions 'write()' and 'read()'
   - this program is equivalent to "Process_comm-Pipe/One_process.c" program
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

    // Open file and read and write to it
    //  - 'O_RDWR' - Open_ReadWrite
    int fd = open("FIFOs/myfifo1", O_RDWR);
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
    printf("Written: %d\n", x);

    int y;
    if (read(fd, &y, sizeof(y)) == -1) {
        printf("Could not write into fifo file\n");
        return 3;
    }

    printf("Read: %d\n", y);

    close(fd);
    printf("Closed\n");

    printf("---------------------------------------\n");
    return 0;
}