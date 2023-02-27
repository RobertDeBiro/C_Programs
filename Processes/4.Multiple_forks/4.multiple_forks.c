// Create multiple processes

#include <stdio.h>
#include <unistd.h> // fork()
#include <sys/wait.h> // wait()

int main(int argc, char* argv[]) {
    int id1 = fork();
    int id2 = fork();
    if (id1 == 0) {
        if (id2 == 0) {
            printf("We are process y with ID = %d\n", getpid());
        } else {
            printf("We are process x with ID = %d\n", getpid());
        }
    } else {
        if(id2 == 0) {
            printf("We are process z with ID = %d\n", getpid());
        } else {
            printf("We are the parrent process with ID = %d\n", getpid());
        }
    }

    int res;
    do {
        res = wait(NULL);
        if(res != -1) {
            printf("Waited for a child with ID = %d to finish\n", res);
        }
    } while (res != -1);
    
    return 0;
}