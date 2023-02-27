// Use fifo to communicate between processes - process 1

#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <unistd.h>
#include <fcntl.h> // open
#include <time.h> /// Use fifo to communicate between processes

int main(int argc, char* argv[]) {
    int arr[5];
    srand(time(NULL));
    int i;
    for (i = 0; i < 5; i++) {
        arr[i] = rand() % 10;
    }

    printf("Opening the sum fifo for writing...\n");
    // Path to sum when source code is executed from VS Code: FIFOs/sum
    // Path to sum when source code is executed from terminal (from /bin directory): ../FIFOs/sum
    int sum_fd_1 = open("../FIFOs/sum", O_WRONLY);
    if (sum_fd_1 == -1) {
        printf("sum FIFO couldn't be open!\n");
        return 1;
    }
    printf("Sum fifo opened for writing!\n");

    for (i = 0; i < 5; i++) {
        if ((write(sum_fd_1, &arr[i], sizeof(int))) == -1) {
            return 2;
        }
        printf("Wrote %d\n", arr[i]);
    }
    close(sum_fd_1);

    return 0;
}