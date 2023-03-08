/*
 * Manipulate stoveFuel object by using 10 threads and pthread_mutex_trylock
 *  - chefs = threads
 *  - stove = shared data (+mutex)
 */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h> //srand, rand

pthread_mutex_t stoveMutex[4];
int stoveFuel[4] = { 100, 100, 100, 100 };

void* routine(void* arg) {
    // Cast arg to int* and dereference it
    int thread_n = *(int*)arg;
    int i;
    for (i = 0; i < 4; i++) {
        if (pthread_mutex_trylock(&stoveMutex[i]) == 0) {
            int fuelNeeded = (rand() % 30);
            if ((stoveFuel[i] - fuelNeeded) < 0) {
                printf("No more fuel... going home\n");
            } else {
                stoveFuel[i] -= fuelNeeded;
                // Sleep in order to act like the chef is currently cooking with the stove
                usleep(500000); // 500 ms
                printf("%d. thread - ", thread_n);
                printf("Fuel left in %d. stove: %d\n", i + 1, stoveFuel[i]);
            }
            pthread_mutex_unlock(&stoveMutex[i]);
            // After thread reduces stoveFuel, it breaks the loop and it fully finishes it execution
            break;
        } else {
            if (i == 3) {
                sleep(1);
                printf("%d. thread - ", thread_n);
                printf("No stove available yet, waiting...\n");
                i = -1;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    printf("************************************************\n");

    srand(time(NULL));
    
    // Create 10 thread objects
    pthread_t th[10];

    // Create 4 mutex objects
    for (int i = 0; i < 4; i++) {
        pthread_mutex_init(&stoveMutex[i], NULL);
    }

    // Start 10 threads
    for (int i = 0; i < 10; i++) {
        int* a = malloc(sizeof(i));
        *a = i;
        if (pthread_create(th + i, NULL, &routine, a) != 0) {
            perror("Failed to create thread!\n");
            return 1;
        }
    }

    // Join 10 threads
    for (int i = 0; i < 10; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread!\n");
            return 2;
        }
    }

    // Destroy 4 mutex objects
    for (int i = 0; i < 4; i++) {
        pthread_mutex_destroy(&stoveMutex[i]);
    }

    printf("--------------------------------------------\n");
    return 0;
}