#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    printf("************************************************\n");

    // Calling 'fork()' from particular process
    // - that is how we can have odd number of processes
    int id = fork();
    if (id != 0) {
        fork();
    }
    printf("Hello world\n");

    printf("-----------------------------------------\n");
    return 0;
}