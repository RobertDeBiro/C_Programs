// Signals
// - SIGSTOP and SIGCONT

#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <unistd.h>
#include <time.h>
#include <sys/wait.h> // wait
#include <signal.h> // kill

int main(int argc, char* argv[]) {
    int pid = fork();
    if (pid == -1) {
        return 1;
    }

    if (pid == 0) {
        while(1) {
            printf("Some output\n");
            usleep(50000);
        }
    } else {
        kill(pid, SIGSTOP); // stop the child process

        int t;
        do {
            printf("Time in seconds for execution: ");
            scanf("%d", &t);

            if (t > 0) {
                kill(pid, SIGCONT); // continue the child process
                sleep(t);
                kill(pid, SIGSTOP); // stop the child process
            }
        } while(t > 0);

        kill(pid, SIGKILL); // kild child process
        wait(NULL);
    }

    return 0;
}