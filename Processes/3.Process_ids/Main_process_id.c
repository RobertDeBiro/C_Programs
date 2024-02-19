//* Terminating parent process before child
//  - when parent process is terminated before child process, child process won't be left
//    without of parent process, but rather initial process in Linux (with 'id = 1') will be
//    assigned to that child as its new parent
//  - that is because the initial process is actually first process started in the Linux
//    and it is parent for every process

#include <stdio.h>
#include <unistd.h> // fork
#include <sys/wait.h> // wait

int main(int argc, char* argv[]) {
    printf("***************************************\n");

    int id = fork();

    //  If we are in child process, let our process sleep for one second
    //  - in the meantime, while sleeping, parent process will finish his execution
    if (id == 0) {
        sleep(1);
    }

    if (id == 0)
    {
        printf("\nChild process: Current ID: %d, parent ID: %d\n", getpid(), getppid());
    }
    else
    {
        printf("Parent process: Current ID: %d, parent ID: %d\n", getpid(), getppid());
    }

    printf("---------------------------------------\n");
    return 0;
}