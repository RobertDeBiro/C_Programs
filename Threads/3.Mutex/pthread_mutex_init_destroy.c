// This example shows concurrency 

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h> // pthread

int mails = 0;

// Create mutex variable
pthread_mutex_t mutex;

void* routine() {
    for (int i = 0; i < 10000000; i++) {
        // Lock the mutex - Protect the code
        //  - when other thread encounters this line, it cannot lock the mutex
        //    since it is already locked, so it waits until mutex is unlocked
        pthread_mutex_lock(&mutex);
        
        mails++;

        // Unlock the mutex - Unprotect the code
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char* argv[]) {
    printf("************************************************\n");

    pthread_t t1, t2, t3, t4;

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    if (pthread_create(&t1, NULL, &routine, NULL) != 0) {
        printf("Error occured while creating a thread!\n");
        return 1;
    }
    if (pthread_create(&t2, NULL, &routine, NULL) != 0) {
        printf("Error occured while creating a thread!\n");
        return 2;
    }

    if (pthread_create(&t3, NULL, &routine, NULL) != 0) {
        printf("Error occured while creating a thread!\n");
        return 3;
    }
    if (pthread_create(&t4, NULL, &routine, NULL) != 0) {
        printf("Error occured while creating a thread!\n");
        return 4;
    }

    if (pthread_join(t1, NULL) != 0) {
        printf("Error occured while waiting for thread termination!\n");
        return 3;
    }
    if (pthread_join(t2, NULL) != 0) {
        printf("Error occured while waiting for thread termination!\n");
        return 4;
    }
    if (pthread_join(t3, NULL) != 0) {
        printf("Error occured while waiting for thread termination!\n");
        return 3;
    }
    if (pthread_join(t4, NULL) != 0) {
        printf("Error occured while waiting for thread termination!\n");
        return 4;
    }

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    printf("Number of mails: %d\n", mails);

    printf("-----------------------------------------\n");
    return 0;
}