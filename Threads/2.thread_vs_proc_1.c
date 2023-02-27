// Threads are running under the same process and
// share the same memory, i.e. have the same variables

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // sleep
#include <pthread.h> // pthread

int x = 2;

void* routine1() {
    printf("Process id of the routine1 thread: %d\n", getpid());
    x += 5;
    sleep(2);
    printf("Value of x: %d\n", x);
}

void* routine2() {
    printf("Process id of the routine2 thread: %d\n", getpid());
    sleep(2);
    printf("Value of x: %d\n", x);
}

int main(int argc, char* argv[]) {
    pthread_t t1, t2;

    if (pthread_create(&t1, NULL, &routine1, NULL) != 0) {
        printf("Error occured while creating a thread!\n");
        return 1;
    }
    if (pthread_create(&t2, NULL, &routine2, NULL) != 0) {
        printf("Error occured while creating a thread!\n");
        return 2;
    }

    if (pthread_join(t1, NULL) != 0) {
        printf("Error occured while waiting for thread termination!\n");
        return 3;
    }
    if (pthread_join(t2, NULL) != 0) {
        printf("Error occured while waiting for thread termination!\n");
        return 4;
    }

    return 0;
}