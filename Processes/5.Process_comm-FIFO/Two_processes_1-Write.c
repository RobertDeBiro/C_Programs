/*
 * Two-way communication using two VSCode programms for processes - Write data to FIFO
 *  - when having WRONLY flag, open() will return the descriptor after FIFO file is also opened in
 *    other end
 *  - hence, the program will be stopped on that line until other end is opened
 */

#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h>
#include <unistd.h>
#include <fcntl.h> // open

int main(int argc, char* argv[]) {
    printf("***************************************\n");

    // Generate array of five random numbers from 0 to 9
    int arr[5];
    srand(time(NULL));
    int i;
    for (i = 0; i < 5; i++) {
        arr[i] = rand() % 10;
    }

    printf("Opening the sum fifo for writing...\n");
    // Path is ../FIFOs/sum because this program is run from /bin directory
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

    printf("---------------------------------------\n");
    return 0;
}