/*
 * This program will only work if we read from the fifo in another process,
 * for example if we run "cat myfifo1" in the terminal, while code is run inside VS Code
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
    //  - O_WRONLY - Open_WriteOnly
    int fd = open("FIFOs/myfifo1", O_WRONLY);
    if (fd == -1) {
        printf("Couldn't open the fifo file!\n");
        return 2;
    }

    printf("Opened\n");

    int x = 97; // x will be written as ASCII code "a"
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