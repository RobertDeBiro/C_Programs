#include <stdio.h> // flush
#include <unistd.h> // fork
#include <sys/wait.h> // wait

int main(int argc, char* argv[])
{
    printf("***************************************\n");
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
    // 1. step, Child process: print 1, 2, 3, 4, 5
    // 2. step, Parent process: print 6, 7, 8, 9, 10
    for (i = n; i < n + 5; i++) {
        printf("%d ", i);
        // With 'fflush()', printf immediatelly prints text to the output, it doesn't buffers it into
        // internal buffer that it has
        // - however, I don't see any difference with and without 'fflush()' in my compiler!
        fflush(stdout);
    }
    printf("\n");

    printf("---------------------------------------\n");
    return 0;
}