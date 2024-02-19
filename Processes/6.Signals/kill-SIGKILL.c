/*
 * Killing the process by using 'kill()' function and 'SIGKILL' signal
 */

#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <unistd.h>
#include <time.h>
#include <sys/wait.h> // wait
#include <signal.h> // kill

int main(int argc, char* argv[]) {
    printf("***************************************\n");

    int pid = fork();
    if (pid == -1) {
        return 1;
    }

    if (pid == 0)
    {
        while(1) {
            printf("Some text goes here\n");
            usleep(50000); // sleep for 50 ms (50000 us)
        }
    }
    else
    {
        sleep(1); // sleep for 1 s
        kill(pid, SIGKILL); // kill child process
        wait(NULL); // waiting for child process to be killed
        printf("Child process killed!\n");
    }

    printf("---------------------------------------\n");
    return 0;
}