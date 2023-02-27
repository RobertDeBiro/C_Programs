// Signals
// - used to control the processes
// - kill() function, SIGKILL signal

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
            printf("Some text goes here\n");
            usleep(50000); // sleep for 50 ms (50000 us)
        }
    } else {
        sleep(1); // sleep for 1 s
        // kill()
        // - sends the signal
        // - SIGKILL - kills the process
        kill(pid, SIGKILL); // kill child process
        wait(NULL);
    }

    return 0;
}