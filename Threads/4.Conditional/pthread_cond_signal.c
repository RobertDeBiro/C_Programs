/*
 * Conditional variable
   - used when "first thread" locks mutex and decides to unlock it in order to
     be locked by "second thread" until that thread executes some condition
   - after that condition is executed "second thread" should signal "first thread"
     condition variable with 'pthread_cond_signal()' to inform it that
     condition is executed and that it can lock mutex again and continue doing
     actions that it previously stopped
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // sleep
#include <pthread.h> // pthread

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel; // Create conditional variable
int fuel = 0;

// Condition - fill fuel
void* fuel_filling(void* arg) {
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutexFuel);
        fuel += 15;
        printf("Filled fuel... %d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_signal(&condFuel);
        sleep(1);
    }
}

void* car(void* arg) {
    pthread_mutex_lock(&mutexFuel);
    while(fuel < 40) {
        printf("No fuel. Waiting...\n");
        //* Procedure when 'pthread_cond_wait()' is called:
        //  1. Unlock the mutex
        //  2. Wait for the signal
        //  3. Lock the mutex
        pthread_cond_wait(&condFuel, &mutexFuel);
    }
    fuel -= 40;
    printf("Got fuel. Now left: %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
}

int main(int argc, char* argv[]) {
    printf("************************************************\n");

    pthread_t th[2];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);

    for (int i = 0; i < 2; i++) {
        if (i == 1) {
            if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0) { // Executed second
                perror("Failed to create thread!\n");
            }
        } else {
            if (pthread_create(&th[i], NULL, &car, NULL) != 0) { // Executed first
                perror("Failed to create thread!\n");
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread!\n");
        }
    }

    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);

    printf("--------------------------------------------\n");
    return 0;
}