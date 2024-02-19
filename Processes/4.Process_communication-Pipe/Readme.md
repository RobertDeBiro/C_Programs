# Process communication - `pipe`

---

## `pipe()`

```c
#include <unistd.h>

int pipe(int pipefd[2])
```

- creates a **pipe**, an unidirectional data channel that can be used for ***interprocess communication***
- `pipefd[2]`
  - **file descriptor**
  - `pipefd[0]` - for reading from pipe
  - `pipefd[0]` - for writting to pipe

### Return value

- on success:
  - *0* is returned
- on error
  - *-1* is returned, `errno` is set to indicate the error, and `pipefd` is left unchanged

---

## References

- <https://man7.org/linux/man-pages/man2/pipe.2.html>
- <https://www.youtube.com/watch?v=Mqb2dVRe0uo&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=6>
- <https://www.youtube.com/watch?v=8Q9CPWuRC6o&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=10>
