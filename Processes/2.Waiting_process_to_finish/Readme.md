# Waiting process to finish

---

## `wait()`

```c
#include <sys/wait.h>

pid_t wait(int *wstatus)
```

- suspends the execution of the calling process until one of its child processes terminates
- typically used in conjunction with the `fork()` system call
- `wstatus`
  - pointer to an integer where the exit status of the terminated child process will be stored
  - if equal to `NULL` the exit status information is discarded

### Return value

- on success:
  - returns the process ID of the terminated child
- on failure:
  - *-1* is returned

---

## References

- <https://man7.org/linux/man-pages/man2/wait.2.html>
- <https://www.youtube.com/watch?v=tcYo6hipaSA&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=2>
