// pthread_mutex_trylock locks execution of the code for every function except one
// - in normal mutex example function waits for mutex being unlocked and then starts executing the code,
//   whereas here, if it is locked, it just skip that part of the code

#include <stdio.h>
#include <unistd.h> // sleep
#include <pthread.h> // pthread

pthread_mutex_t mutex;

void* routine(void* arg) {
    if (pthread_mutex_trylock(&mutex) == 0) {
        printf("Got lock\n");
        sleep(1);
        pthread_mutex_unlock(&mutex);
    } else {
        printf("Didn't get lock\n");
    }
}

int main(int argc, char* argv[]) {
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

    return 0;
}