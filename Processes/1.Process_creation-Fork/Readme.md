## FORK
    #include <unistd.h>
    
    pid_t fork(void)

 - fork system call is used for creating a new process, which is called child process, which runs concurrently with the process that makes the fork() call (parent process)

### Return value
 - on success, the PID of the child process is returned in the parent, and 0 is returned in the child
 - on failure, -1 is returned in the parent, no child process is created, and errno is set to indicate the error

### References
 - https://man7.org/linux/man-pages/man2/fork.2.html
 - https://www.geeksforgeeks.org/fork-system-call/
 - https://www.youtube.com/watch?v=cex9XrZCU14&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY
 - https://www.youtube.com/watch?v=QD9YKSg3wCc&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=3
 - https://www.youtube.com/watch?v=94URLRsjqMQ&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=5

 - System call:
    - https://www.geeksforgeeks.org/introduction-of-system-call/
    - https://www.youtube.com/watch?v=lhToWeuWWfw
