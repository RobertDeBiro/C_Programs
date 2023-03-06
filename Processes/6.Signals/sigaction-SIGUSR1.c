/*
 * Sending SIGUSR1 signal from child to parent process
 *  - program must be executed from terminal
 */

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

    if (pid == 0)
    {
        // Wait 3 seconds for the user to write an answer
        //  - if he don't do that, send signal to parent process with HINT how to do it
        sleep(3);

        // Sending SIGUSR1 signal to the parent process
        //  - SIGUSR1 is set aside for user to use it any way he wants
        //  - in this example basically we are just sending that signal to parent process as an
        //    indication for parent process to do something
        kill(getppid(), SIGUSR1);
    }
    else
    {
        struct sigaction sa;
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = &handle_sigusr1;
        sigaction(SIGUSR1, &sa, NULL);

        // Parent process
        int x;
        printf("What is the result of 3 x 5: ");
        scanf("%d", &x);
        if (x == 15) {
            printf("Right!\n");
        } else {
            printf("Wrong!\n");
        }
        wait(NULL);
    }

    return 0;
}