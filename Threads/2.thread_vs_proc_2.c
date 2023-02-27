// Every process has its own memory, i.e. its own variables

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // sleep
#include <sys/wait.h> // wait
#include <sys/types.h>

int main(int argc, char* argv[]) {
    int x = 2;
    int pid = fork();
    if (pid == -1) {
        return 1;
    }
    printf("Process id from one of the process: %d\n", getpid());

    if (pid == 0) {
        x++;
    }
    sleep(2);
    printf("Value of x: %d\n", x);

    if (pid != 0) {
        wait(NULL);
    }

    return 0;
}