/*
 * 5 => 5 * 4 = 20 => 20
 * When one process writes and reads from the same pipe, it can happen that it will do it
 * before other process could write to that pipe, so behavior will be unproper
 *  - therefore, when two process inter-communicate, we need two pipes
 */ 

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <wait.h>

int main(int argc, char* argv[]) {
    printf("***************************************\n");
    
    int p1[2]; // C => P
    int p2[2]; // P => C
    if (pipe(p1) == -1) { return 1; }
    if (pipe(p2) == -1) { return 1; }

    int pid = fork();
    if (pid == -1) { return 2; }

    if (pid == 0) {
        // Child process
        close(p1[0]);
        close(p2[1]);
        int x;
        if (read(p2[0], &x, sizeof(x)) == -1) { return 3; }
        printf("Received %d\n", x);
        x *= 4;
        if (write(p1[1], &x, sizeof(x)) == -1) { return 4; }
        printf("Wrote %d\n", x); 
        close(p1[1]);
        close(p2[0]);
    } else {
        // Parent process
        close(p1[1]);
        close(p2[0]);
        srand(time(NULL));
        int y = rand() % 10;
        if (write(p2[1], &y, sizeof(y)) == -1) { return 5; }
        printf("Wrote %d\n", y);
        if (read(p1[0], &y, sizeof(y)) == -1) { return 6; }
        printf("Result is %d\n", y);
        wait(NULL);
        close(p1[0]);
        close(p2[1]);
    }

    printf("---------------------------------------\n");
    return 0;
}