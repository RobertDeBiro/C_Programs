// Thread can also return some value, not only do some actions, as seen
// in previous examples

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h> // pthread
#include <time.h> // time

// thread function must return object void*
void* roll_dice() {
    // We need to return the diceValue by address from this function,
    // but we cannot do that by executing "return &diceValue" since diceValue is 
    // local variable and will be destroyed i.e. memory will be deallocated
    int diceValue = (rand() % 6) + 1;
    int* result = malloc(sizeof(diceValue));
    *result = diceValue;
    printf("Thread result address %p\n", result);
    return (void*) result;
}

int main(int argc, char* argv[]) {
    int* res;
    srand(time(NULL));
    pthread_t th;
    if (pthread_create(&th, NULL, &roll_dice, NULL) != 0) {
        return 1;
    }
    // pointer_join as second argument sends a double pointer and puts inside of it
    // whatever is set as return value from thread function
    //  - (void**) &res is actually cast of &res, which is int**, to void**
    if (pthread_join(th, (void**) &res) != 0) {
        return 2;
    }

    // variable "res" must have same address as dynamically created variable "result"
    printf("Main result address %p\n", res);
    printf("Result: %d\n", *res);
    free(res);

    return 0;
}