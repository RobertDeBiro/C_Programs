# Signals

---

## `kill`

```c
#include <signal.h>

int kill(pid_t pid, int sig)
```

- the `kill()` system call can be used to send any signal to any process or process group
- if `pid` is positive, then signal `sig` is sent to the process with the ID specified by `pid`
- if `sig` is *0*, then no signal is sent, but existence and permission checks are still performed

### Return value

- on success (at least one signal was sent), *0* is returned
- on error, *-1* is returned, and `errno` is set to indicate the error

### Terminal commands

```bash
kill -l
```

- list all signal names and numbers in our system

---

## `sigaction`

```c
#include <signal.h>

int sigaction(int signum, const struct sigaction *restrict act, struct sigaction *restrict oldact);

struct sigaction {
    void        (*sa_handler)(int);
    void        (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t    sa_mask;
    int         sa_flags;
    void        (*sa_restorer)(void);
};
```

- the `sigaction()` system call is used to change the action taken by a process on receipt of a specific signal
- `signum`
  - signal that will be handled, e.g:
    - `SIGTSTP` - stop signal, i.e. putting process to background
- `act`
  - `sigaction` struct address
- `oldact`
  - function that restores handling signal behavior
- `struct sigaction`:
  - `sa_handler`
    - saves pointer to a function that will be called whenever a certain signal is received
  - `sa_flags`
    - specifies a set od flags which modify the behavior of the signal

---

## References

- <https://man7.org/linux/man-pages/man2/kill.2.html>
- <https://linuxhint.com/kill-signal-numbers-linux/>
- <https://www.gnu.org/software/libc/manual/html_node/Standard-Signals.html>
- <https://www.youtube.com/watch?v=5We_HtLlAbs&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=16>
- <https://www.youtube.com/watch?v=3MZjaZxZYrE&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=17>
- <https://www.youtube.com/watch?v=7ud2iqu9szk&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=18>
- <https://man7.org/linux/man-pages/man7/signal.7.html>
- <https://man7.org/linux/man-pages/man2/sigaction.2.html>
- <https://www.youtube.com/watch?v=jF-1eFhyz1U&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=19>
- <https://www.youtube.com/watch?v=PErrlOx3LYE&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=20>
