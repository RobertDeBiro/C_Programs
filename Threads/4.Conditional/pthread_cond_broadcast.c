/*
 * Sending signal to every thread that is waiting for the signal by using condition broadcast
 */ 

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // sleep
#include <pthread.h> // pthread

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel; // Create conditional variable
int fuel = 0;

void* fuel_filling(void* arg) {
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutexFuel);
        fuel += 60;
        printf("Filled fuel... %d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
        // Checking behavior when 'cond' is signalled and not broadcasted:
        // - in that case only one 'car' receives the signal and takes the 'fuel'
        // pthread_cond_signal(&condFuel); 
        pthread_cond_broadcast(&condFuel);
        sleep(1);
    }
}

void* car(void* arg) {
    pthread_mutex_lock(&mutexFuel);
    while(fuel < 40) {
        printf("No fuel. Waiting...\n");
        pthread_cond_wait(&condFuel, &mutexFuel);
    }
    fuel -= 40;
    printf("Got fuel. Now left: %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
}

int main(int argc, char* argv[]) {
    printf("************************************************\n");

    pthread_t th[5];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);

    for (int i = 0; i < 5; i++) {
        if (i == 4) {
            if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0) {
                perror("Failed to create thread!\n");
            }
        } else {
            if (pthread_create(&th[i], NULL, &car, NULL) != 0) {
                perror("Failed to create thread!\n");
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread!\n");
        }
    }

    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);

    printf("--------------------------------------------\n");
    return 0;
}