/*
 * fork(void) -> pid_t
 *
 *  - fork system call is used for creating a new process, which is called child process,
 *    which runs concurrently with the process that makes the fork() call (parent process)
 *  - Return value:
 *      - on success, the PID of the child process is returned in the parent,
 *        and 0 is returned in the child
 *      - on failure, -1 is returned in the parent, no child process is created, and errno is
 *        set to indicate the error
 *  - included in <unistd.h>
 * 
 * References:
 *  - https://man7.org/linux/man-pages/man2/fork.2.html
 *  - https://www.geeksforgeeks.org/fork-system-call/
 */

#include <stdio.h>
#include <unistd.h>

// Basic fork() example
void basicFork()
{
    // If fork() returned 0, means that we are in child process
    //  - but, 0 is not a child process id, it is only an indicator that we are currently
    //    in the child process
    int id = fork();
    if(id == 0) {
        printf("id = %d; Hello from child process\n", id);
    } else {
        printf("id = %d; Hello from the main process\n", id);
    }
}

// Calling multiple fork() functions
//  - number of processes is equal to 2 ^ number_of_fork()_calls
void multipleForks()
{
    fork();
    fork();
    fork();
    printf("Hello world\n");
}

// Calling fork() from particular process
// - that is how we can have odd number of processes
void oddForks()
{
    int id = fork();
    if (id != 0) {
        fork();
    }
    printf("Hello world\n");
}

int main(int argc, char* argv[])
{
    printf("************************************************\n");

    basicFork();
    //multipleForks();
    //oddForks();

    printf("-----------------------------------------\n");
    return 0;
}