#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // sleep
#include <pthread.h> // pthread

// Create a function that will be a new thread
void* routine() {
    printf("Test from threads\n");
    sleep(3);
    printf("Ending thread\n");
}

int main(int argc, char* argv[]) {
    printf("************************************************\n");

    // Create 'pthread_t' variables in which API will store info about the threads
    pthread_t t1, t2;

    // Create threads
    if (pthread_create(&t1, NULL, &routine, NULL) != 0) {
        printf("Error occured while creating a thread!\n");
        return 1;
    }
    if (pthread_create(&t2, NULL, &routine, NULL) != 0) {
        printf("Error occured while creating a thread!\n");
        return 2;
    }

    // Join threads
    if (pthread_join(t1, NULL) != 0) {
        printf("Error occured while waiting for thread termination!\n");
        return 3;
    }
    if (pthread_join(t2, NULL) != 0) {
        printf("Error occured while waiting for thread termination!\n");
        return 4;
    }

    printf("-----------------------------------------\n");
    return 0;
}