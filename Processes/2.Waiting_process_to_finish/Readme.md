## SYNTAX
    pid_t wait(int *wstatus)

 - wait for process to change state

### Return value
 - on success, returns the process ID of the terminated child
 - on failure, -1 is returned

### Library
 - included in <sys/wait.h>

### References
 - https://man7.org/linux/man-pages/man2/wait.2.html
