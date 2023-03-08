// pthread_exit exits the thread with added argument

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> // pthread
#include <time.h> // time

void* roll_dice() {
    int diceValue = (rand() % 6) + 1;
    int* result = malloc(sizeof(diceValue));
    *result = diceValue;
    sleep(2);
    printf("Thread result %d\n", *result);
    // pthread, is the same as using return
    pthread_exit((void*) result);
}

int main(int argc, char* argv[]) {
    int* res;
    srand(time(NULL));
    pthread_t th;
    if (pthread_create(&th, NULL, &roll_dice, NULL) != 0) {
        return 1;
    }

    // pthread_exit when run inside main() function exits the main thread, but not the main process,
    // hence it waits for other threads to be finished
    pthread_exit(0);

    // pointer_join as second argument sends a double pointer and puts inside of it
    // whatever is set as return value from thread function
    //  - (void**) &res is actually cast of &res, which is int**, to void**
    if (pthread_join(th, (void**) &res) != 0) {
        return 2;
    }

    printf("Result: %d\n", *res);
    free(res);

    return 0;
}