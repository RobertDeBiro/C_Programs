/*
 * Due to race condition, at the end it won't be 2 000 000 mails, but rather some number
 * between 1 and 2 milion
 *  - it can happen that both threads read mails variable at the same time, hence the both will inrease
 *    by one the same value, and there we will have a loss of one value
 */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h> // pthread

int mails = 0;

void* routine() {
    for (int i = 0; i < 1000000; i++) {
        // Processor steps when increasing mails (can be confirmed in assembly code):
        //  1) Read mails
        //  2) Increment mails
        //  3) Write mails
        mails++;
    }
}

int main(int argc, char* argv[]) {
    printf("************************************************\n");

    pthread_t t1, t2;

    if (pthread_create(&t1, NULL, &routine, NULL) != 0) {
        printf("Error occured while creating a thread!\n");
        return 1;
    }
    if (pthread_create(&t2, NULL, &routine, NULL) != 0) {
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

    printf("Number of mails: %d\n", mails);

    printf("--------------------------------------------\n");
    return 0;
}