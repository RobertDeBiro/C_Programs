#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // sleep
#include <sys/wait.h> // wait
#include <sys/types.h>

int x = 2;

int main(int argc, char* argv[]) {
    printf("************************************************\n");

    int pid = fork();
    if (pid == -1) {
        return 1;
    }
    printf("Process id from one of the processes: %d\n", getpid());

    if (pid == 0) {
        x++;
    }
    sleep(2);
    printf("Value of x: %d\n", x);

    if (pid != 0) {
        wait(NULL);
    }

    printf("--------------------------------------------\n");
    return 0;
}