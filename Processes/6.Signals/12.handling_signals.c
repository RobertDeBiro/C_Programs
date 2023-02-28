// Handling signals
// - SIGTSTP
//   - for bringing process to backround
//   - differs from SIGSTOP
// - this example must be run from terminal

#include <stdlib.h>
#include <stdio.h>
#include <signal.h> // sigaction

void handle_sigtstp(int sig) {
    printf("Stop not allowed!\n");
}

void handle_sigcont(int sig) {
    printf("Input number: ");
    fflush(stdout);
}

int main(int argc, char* argv[]) {
    // sigaction structure contains parameters used for signal handling
    // - sa_handler
    //    - saves pointer to a function that will be called whenever a certain signal is received
    // - sa_flags
    //    - specifies a set od flags which modify the behavior of the signal
    //    - SA_RESTART - needed because scanf() function is used
    //
    // sigaction() is system call used to change the action taken by a process
    // on receipt of a specific signal
    // - first parameter is signal that will be handled
    //   - SIGTSTP - stop signal, i.e. putting process to background
    // - second parameter is sigaction struct address
    // - as a third parameter we can send function that restores handling signal behavior
    struct sigaction sa;
    sa.sa_handler = &handle_sigtstp;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGTSTP, &sa, NULL);

    // Handling SIGCONT signal
    // - must be executed if handle_sigtstp part is commented
    // sa.sa_handler = &handle_sigcont;
    // sigaction(SIGCONT, &sa, NULL);

    int x;
    printf("Input number: ");
    scanf("%d", &x);
    printf("Result %d * 5 = %d\n", x, x * 5);
    return 0;
}