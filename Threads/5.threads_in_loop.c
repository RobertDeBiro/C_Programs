// Create and join threads by using for loop
// - example is the same as in 4.mutex.c, but with for loop when creating and joining threads

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h> // pthread

int mails = 0;
pthread_mutex_t mutex;

void* routine() {
    for (int i = 0; i < 10000000; i++) {
        pthread_mutex_lock(&mutex);  
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char* argv[]) {
    pthread_t th[4]; // pthread_t can also be an array
    int i;
    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < 4; i++) {
        if (pthread_create(th + i, NULL, &routine, NULL) != 0) {
            perror("Failed to create thread!\n");
            return 1;
        }
        printf("Thread %d has started\n", i);
    }

    for (i = 0; i < 4; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            return 2;
        }
        printf("Thread %d has finished execution\n", i);
    }

    pthread_mutex_destroy(&mutex);

    printf("Number of mails: %d\n", mails);

    return 0;
}