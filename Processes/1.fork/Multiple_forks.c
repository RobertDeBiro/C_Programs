#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    printf("************************************************\n");

    // Calling multiple fork() functions
    //  - number of processes is equal to 2 ^ number_of_fork()_calls
    fork();
    fork();
    fork();
    printf("Hello world\n");

    printf("-----------------------------------------\n");
    return 0;
}