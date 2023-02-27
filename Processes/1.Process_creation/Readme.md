## SYNTAX
    pid_t fork(void)

 - fork system call is used for creating a new process, which is called child process, which runs concurrently with the process that makes the fork() call (parent process)

### Return value
 - on success, the PID of the child process is returned in the parent, and 0 is returned in the child
 - on failure, -1 is returned in the parent, no child process is created, and errno is set to indicate the error

### Library
 - included in <unistd.h>

### References
 - https://man7.org/linux/man-pages/man2/fork.2.html
 - https://www.geeksforgeeks.org/fork-system-call/
