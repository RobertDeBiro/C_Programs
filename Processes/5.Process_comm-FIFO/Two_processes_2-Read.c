/*
 * Two-way communication using two VSCode programms for processes - Read data from FIFO
 *  - when having RDONLY flag, open() will return the descriptor after FIFO file is also opened in
 *    other end
 *  - hence, the program will be stopped on that line until other end is opened
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> // open

int main(int argc, char* argv[]) {
    printf("***************************************\n");

    int arr[5];
    printf("Opening the sum fifo for reading...\n");
    // Path is ../FIFOs/sum because this program is run from /bin directory
    int sum_fd_2 = open("../FIFOs/sum", O_RDONLY);
    if (sum_fd_2 == -1) {
        return 1;
    }
    printf("Sum fifo opened for reading!\n");

    int i;
    for (i = 0; i < 5; i++) {
        if ((read(sum_fd_2, &arr[i], sizeof(int))) == -1) {
            return 2;
        }
        printf("Received %d\n", arr[i]);
    }
    close(sum_fd_2);

    int sum = 0;
    for(i = 0; i < 5; i++) {
        sum += arr[i];
    }
    printf("Result is %d\n", sum);

    printf("---------------------------------------\n");
    return 0;
}