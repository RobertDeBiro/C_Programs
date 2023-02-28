// Use fifo to communicate between processes - process 2

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> // open

int main(int argc, char* argv[]) {
    int arr[5];
    printf("Opening the sum fifo for reading...\n");
    // Path to sum when source code is executed from VS Code: FIFOs/sum
    // Path to sum when source code is executed from terminal (from /bin directory): ../FIFOs/sum
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

    return 0;
}