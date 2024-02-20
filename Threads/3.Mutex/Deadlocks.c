/*
 * Deadlock - programs execution stuckes due to locked mutexes
 */

#include <stdlib.h> // srand, rand
#include <stdio.h>
#include <unistd.h> // sleep
#include <pthread.h>

#define THREAD_NUM 8

pthread_mutex_t mutexFuel;
int fuel = 50;

pthread_mutex_t mutexWater;
int water = 10;

// One thread will lock 'fuel/water' and wait for 1 second, whereas in the meantime
// some other thread may lock 'water/fuel' and wait for 1 second
//  - ultimately, both threads will try to lock already locked mutexes
//  - since that will not be possible, they will infinitely wait for them to be unlocked
void* routine(void *args) {
    if(rand() % 2 == 0) {
        pthread_mutex_lock(&mutexFuel);
        printf("Fuel LOCKED!\n");
        sleep(1);
        pthread_mutex_lock(&mutexWater);
    } else {
        pthread_mutex_lock(&mutexWater);
        printf("Water LOCKED!\n");
        sleep(1);
        pthread_mutex_lock(&mutexFuel);
    }
    fuel += 50;
    water = fuel;
    printf("Incremented fuel to: %d; Water set to %d\n", fuel, water);
}

int main(int argc, char *argv[]) {
    pthread_t th[THREAD_NUM];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_mutex_init(&mutexWater, NULL);
    srand(time(NULL));

    int i;
    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0) {
            perror("Failed to create thread!\n");
        }
    }
    for (int i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread!\n");
        }
    }
    pthread_mutex_destroy(&mutexFuel);
    pthread_mutex_destroy(&mutexWater);

    return 0;
}