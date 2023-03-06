/*
 * Handle SIGCONT signal (signal that put process to foreground)
 *  - if we try to put programm in foreground via fg, our sigaction() function will fetch that
 *    signal and instead call handle_sigcont() function
 *  - SIGCONT
 *      - signal that is called when putting process to foreground
 *  - program must be executed from terminal
 */

#include <stdlib.h>
#include <stdio.h>
#include <signal.h> // sigaction

void handle_sigcont(int sig) {
    printf("Input number: ");
    
    // fflush() - clears (or flushes) the output buffer and moves the buffered data to console
    //  - with this command we are actually clearing everything we had in input buffer before we
    //    had put the process to background (everything that scanf saves into buffer)
    //    and we giving input stream to terminal
    fflush(stdout);
}

int main(int argc, char* argv[]) {
    printf("************************************************\n");

    // Create sigaction structure and define needed attributes
    struct sigaction sa;
    
    // Define which function will handle input signal
    sa.sa_handler = &handle_sigcont;
    
    // Define flag
    //  - SA_RESTART flag - needed when scanf() function is used
    sa.sa_flags = SA_RESTART;
    
    // Define sigaction() system call
    sigaction(SIGCONT, &sa, NULL);

    int x;
    printf("Input number: ");
    scanf("%d", &x);
    printf("Result %d * 5 = %d\n", x, x * 5);

    printf("-----------------------------------------\n");
    return 0;
}