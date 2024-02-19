#include <stdio.h>
#include <unistd.h> // fork
#include <sys/wait.h> // wait

int main(int argc, char* argv[]) {
    printf("***************************************\n");
    
    int id = fork();

    if (id == 0) {
        printf("\nChild process: Current ID: %d, parent ID: %d\n", getpid(), getppid());
    } else {
        printf("Parent process: Current ID: %d, parent ID: %d\n", getpid(), getppid());
    }

    // Both processes try to wait for child to be finished
    int res = wait(NULL);
    if (res == -1) {
        // If wait returns '-1' means that we are currently in the child process and that there is no
        // other process to wait for
        printf("No children to wait for\n");
    } else {
        // If wait doesn't return '-1', we are in parent process, and we will actually wait for child
        // process to be finished and then printout following text
        printf("My child process with ID = %d finished execution\n", res);
    }

    printf("---------------------------------------\n");
    return 0;
}