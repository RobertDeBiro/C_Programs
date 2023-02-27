// Wait for process to finish

#include <stdio.h> // flush
#include <unistd.h> // fork
#include <sys/wait.h> // wait

int main(int argc, char* argv[])
{
    int id = fork();
    int n;
    if (id == 0) {
        n = 1;
    } else {
        n = 6;
    }

    if(id != 0) {
        // Stop the execution of the main process until the child process finishes executing
        wait(NULL);
    }

    int i;
    for (i = n; i < n + 5; i++) {
        printf("%d ", i);
        // With fflush, printf immediatelly prints text to the output, it doesn't beffuers it into
        // internal buffer that it has
        // - however, I don't see any difference with and wothout fflush in my compiler!
        fflush(stdout);
    }
    if (id != 0) {
        printf("\n");
    }

    return 0;
}