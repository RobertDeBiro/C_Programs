// - this example must be run from terminal

#include <stdio.h>
#include <unistd.h> // fork()
#include <signal.h> // kill
#include <sys/wait.h> // wait

void handle_sigusr1()
{
    printf("\n(HINT) Remember that multiplication is repetetive addition!\n");
}

int main(int argc, char* argv[]) {
    int pid = fork();
    if (pid == -1) {
        return 1;
    }

    if (pid == 0) {
        sleep(5);
        kill(getppid(), SIGUSR1);
    } else {
        struct sigaction sa;
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = &handle_sigusr1;
        sigaction(SIGUSR1, &sa, NULL);

        // Parent process
        int x;
        printf("What is the result of 3 x 5: ");
        scanf("%d", &x);
        if (x == 15) {
            printf("Right!");
        } else {
            printf("Wrong!");
        }
        wait(NULL);
    }

    return 0;
}