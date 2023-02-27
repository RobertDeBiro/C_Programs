// Get process ID

#include <stdio.h>
#include <unistd.h> // fork
#include <sys/wait.h> // wait

// Terminate parent before child
//  - when parent process is terminated before child process,
//    child process won't be left without of parent process,
//    but rather initial process in Linux (with id = 1) will be
//    assigned to that child as its new parent
//     - that is because that initial process is actually first process
//       started in the Linux and it is parent for every process
void terminateParent(int id)
{
    if (id == 0) {
        sleep(1);
    }
}

int main(int argc, char* argv[]) {
    int id = fork();

    //terminateParent(id);

    if (id == 0)
    {
        printf("\nChild process: Current ID: %d, parent ID: %d\n", getpid(), getppid());
    }
    else
    {
        printf("Parent process: Current ID: %d, parent ID: %d\n", getpid(), getppid());
    }

    // Comment following part if terminateParent() is uncommented
    int res = wait(NULL);
    if (res == -1) {
        printf("No children to wait for\n");
    } else {
        printf("My child process with ID = %d finished execution\n", res);
    }

    return 0;
}