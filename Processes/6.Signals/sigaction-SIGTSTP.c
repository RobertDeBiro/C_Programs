/*
 * Handle SIGTSTP signal
   - 'SIGTSTP'
     - signal that is called when putting process to background
     - differs from 'SIGSTOP'
   - disable possibility that process is put to background
   - if we try to put program in backround via 'Ctrl+z', our 'sigaction()' function will fetch that
     signal and instead call 'handle_sigtstp()' function
   - program must be executed from terminal
 */

#include <stdlib.h>
#include <stdio.h>
#include <signal.h> // sigaction

void handle_sigtstp(int sig) {
    printf("Stop not allowed!\n");
}

int main(int argc, char* argv[]) {
    printf("************************************************\n");

    // Create sigaction structure and define needed attributes
    struct sigaction sa;
    
    // Define which function will handle input signal
    sa.sa_handler = &handle_sigtstp;
    
    // Define flag
    //  - SA_RESTART flag - needed when scanf() function is used
    sa.sa_flags = SA_RESTART;
    
    // Define sigaction() system call
    sigaction(SIGTSTP, &sa, NULL);

    int x;
    printf("Input number: ");
    scanf("%d", &x);
    printf("Result %d * 5 = %d\n", x, x * 5);

    printf("-----------------------------------------\n");
    return 0;
}