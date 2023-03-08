#include <stdlib.h>
#include <stdio.h>
#include <pthread.h> // pthread

int prime[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* routine(void* arg) {
    // Cast arg to int* and dereference it
    int index = *(int*)arg;
    printf("%d ", prime[index]);
    free(arg);
}

int main(int argc, char* argv[]) {
    printf("************************************************\n");

    pthread_t th[10];
    for(int i = 0; i < 10; i++) {
        int* a = malloc(sizeof(i));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) {
            perror("Failed to create thread!\n");
        }
    }
    for (int i = 0; i < 10; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread!\n");
        }
    }
    printf("\n");

    printf("-----------------------------------------\n");
    return 0;
}