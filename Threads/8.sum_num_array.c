// Showing how threads can cooperate in parallel in order to make execution faster
// - this example shows parallelism

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h> // pthread

int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* routine(void* arg) {
    int index = *(int*)arg;
    int sum = 0;
    for(int j = 0; j < 5; j++) {
        sum += primes[index + j];
    }
    printf("Local sum: %d\n", sum);
    *(int*)arg = sum;
    return arg;
}

int main(int argc, char* argv[]) {
    pthread_t th[2];
    int i;
    for(i = 0; i < 2; i++) {
        int* a = malloc(sizeof(i));
        *a = i * 5;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) {
            perror("Failed to create thread!\n");
        }
    }
    int globalSum = 0;
    for (i = 0; i < 2; i++) {
        int* r;
        if (pthread_join(th[i], (void**) &r) != 0) {
            perror("Failed to join thread!\n");
        }
        globalSum += *r;
        free(r);
    }
    printf("Global sum: %d\n", globalSum);

    return 0;
}