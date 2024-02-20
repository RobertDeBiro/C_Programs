/*
 * Manipulate 'stoveFuel' object by using 10 threads and 'pthread_mutex_trylock'
   - chefs = threads
   - stove = shared data (+mutex)
 */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h> //srand, rand

pthread_mutex_t stoveMutex[4];
int stoveFuel[4] = { 100, 100, 100, 100 };


//* Execution flow:
/*
  - 0.thread
    - locks stoveMutex[0]
  - 1.thread
    - tries to lock stoveMutex[0] - locked by 0.thread
    - locks stoveMutex[1]
  - 2.thread
    - tries to lock stoveMutex[0] - locked by 0.thread
    - tries to lock stoveMutex[1] - locked by 1.thread
    - locks stoveMutex[2]
  - 3.thread
    - tries to lock stoveMutex[0] - locked by 0.thread
    - tries to lock stoveMutex[1] - locked by 1.thread
    - tries to lock stoveMutex[2] - locked by 2.thread
    - locks stoveMutex[3]
  - 4.thread
    - loop until some of the 'stoveMutex' elements is unlocked:
      - tries to lock stoveMutex[0] - locked by 0.thread
      - tries to lock stoveMutex[1] - locked by 1.thread
      - tries to lock stoveMutex[2] - locked by 2.thread
      - tries to lock stoveMutex[3] - locked by 3.thread
      - prints: "No stove available yet, waiting..."
      - since 'i' becomes equal to '-1' thread still stays in 'for' loop,
        'i++' is executed and 'i' becomes equal to '0'
    -> in this example 'stoveMutex[0]' will be unlocked in the meantime and this thread will lock it
  - 5. thread ...
 */

void* routine(void* arg) {
    int thread_n = *(int*)arg; // cast 'arg' to 'int*' and dereference it
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