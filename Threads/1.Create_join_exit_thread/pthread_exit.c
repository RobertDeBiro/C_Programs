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
    // 'pthread_exit()' when run inside a thread function is the same as using 'return'
    pthread_exit((void*) result);
}

int main(int argc, char* argv[]) {
    printf("************************************************\n");

    int* res;
    srand(time(NULL));
    pthread_t th;
    if (pthread_create(&th, NULL, &roll_dice, NULL) != 0) {
        return 1;
    }

    // 'pthread_exit()', when run inside a 'main()' function, exits the main thread,
    // but not the main process, hence it waits for other threads to be finished
    //  - 'main' process starts the 'main' thread, which is 'main()' function
    //  - then, from the 'main' thread we start 'roll_dice' thread
    //  - 'pthread_exit(0)' terminates the 'main' thread and in addition waits for 'roll_dice'
    //    'pthread_join()' to be executed
    printf("Exit the 'main' thread.\n");
    pthread_exit(0);

    if (pthread_join(th, (void**) &res) != 0) {
        return 2;
    }

    // Following part of the code won't be executed since it is the part of the 'main' thread
    printf("Result: %d\n", *res);
    free(res);

    printf("-----------------------------------------\n");
    return 0;
}