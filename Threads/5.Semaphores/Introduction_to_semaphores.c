/*
 * Locking the code with semaphore
 *  - since in this example we are increasing the value of semaphore every iteration, we are actually not
 *    showing how exactly semaphore is used in practice
 */

#include <stdlib.h> // srand, rand
#include <stdio.h>
#include <unistd.h> // sleep
#include <pthread.h>
#include <semaphore.h>

#define THREAD_NUM 4

sem_t semaphore;

void* routine(void *args) {
    // sem_wait decrements semaphore value if value is greater then 0, and if it is not greater then
    // it waits
    sem_wait(&semaphore);
    sleep(1);
    printf("Hello from thread %d\n", *(int*)args);
    sem_post(&semaphore); // increments semaphore value
    free(args);
}

int main(int argc, char *argv[]) {
    printf("************************************************\n");

    pthread_t th[THREAD_NUM];

    // Initialize semaphore:
    sem_init(&semaphore, 0, 2);

    int i;
    for (i = 0; i < THREAD_NUM; i++) {
        int* a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) {
            perror("Failed to create thread!\n");
        }
    }
    for (int i = 0; i < 4; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread!\n");
        }
    }

    sem_destroy(&semaphore);

    printf("--------------------------------------------\n");
    return 0;
}