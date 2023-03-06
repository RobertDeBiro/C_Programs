## WAIT
    #include <sys/wait.h>
    
    pid_t wait(int *wstatus)

 - wait for process to change state

### Return value
 - on success, returns the process ID of the terminated child
 - on failure, -1 is returned

### References
 - https://man7.org/linux/man-pages/man2/wait.2.html
 - https://www.youtube.com/watch?v=tcYo6hipaSA&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=2
