#include <stdio.h>
#include <unistd.h> // sleep
#include <pthread.h> // pthread

pthread_mutex_t mutex;

void* routine(void* arg) {
    if (pthread_mutex_trylock(&mutex) == 0) {
        sleep(1);
        printf("Got lock\n");
        pthread_mutex_unlock(&mutex);
    } else {
        printf("Didn't get lock\n");
    }
}

int main(int argc, char* argv[]) {
    printf("************************************************\n");

    pthread_t th[4];
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 4; i++) {
        if (pthread_create(th + i, NULL, &routine, NULL) != 0) {
            perror("Failed to create thread!\n");
            return 1;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread!\n");
            return 2;
        }
    }

    pthread_mutex_destroy(&mutex);

    printf("--------------------------------------------\n");
    return 0;
}