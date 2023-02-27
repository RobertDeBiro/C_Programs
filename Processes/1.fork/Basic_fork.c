#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    printf("************************************************\n");

    // If fork() returned 0, means that we are in child process
    //  - but, 0 is not a child process id, it is only an indicator that we are currently
    //    in the child process
    int id = fork();
    if(id == 0) {
        printf("id = %d; Hello from child process\n", id);
    } else {
        printf("id = %d; Hello from the main process\n", id);
    }

    printf("-----------------------------------------\n");
    return 0;
}