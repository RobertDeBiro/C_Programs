// Work with fifo file

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> // mkfifo
#include <sys/stat.h> // mkfifo
#include <errno.h> // errno
#include <fcntl.h> // open

int openWRONLY()
{
    // Open file and write to it
    //  - O_WRONLY - Open_WriteOnly
    //  - this will work if we read from the fifo in another process,
    //    for example if we run "cat myfifo1" in the terminal, while code is run inside VS Code
    int fd = open("FIFOs/myfifo1", O_WRONLY);
    if (fd == -1) {
        printf("Couldn't open the fifo file!\n");
        return 2;
    }
    return fd;
}

int openRDWR()
{
    // Open file and read and write to it
    //  - O_RDWR - Open_ReadWrite
    int fd = open("FIFOs/myfifo1", O_RDWR);
    if (fd == -1) {
        printf("Couldn't open the fifo file!\n");
        return 2;
    }
    return fd;
}

int main(int argc, char* argv[]) {
    printf("***************************************\n");

    if (mkfifo("FIFOs/myfifo1", 0777) == -1) {
        if (errno != EEXIST) {
            printf("Could not create fifo file\n");
            return 1;
        }
        // errno == EEXIST -> file exists
    }

    printf("Opening...\n");

    // open()
    //  - opens fifo file and returns back file descriptor, but
    //    it can be oppened only if other process started reading from it
    //     - that is because fifo actually replaces a pipe - it is a file that acts like a pipe
    //     - since pipe is opened on both ends, the fifo must be also

    //int fd = openWRONLY();
    int fd = openRDWR();

    printf("Opened\n");

    int x = 97; // x will be written as ASCII code "a"
    if (write(fd, &x, sizeof(x)) == -1) {
        printf("Could not write into fifo file\n");
        return 3;
    }
    printf("Written\n");

    close(fd);
    printf("Closed\n");

    printf("---------------------------------------\n");
    return 0;
}