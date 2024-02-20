# Semaphores

---

## `sem_init`

```c
#include <semaphore.h>

int sem_init(sem_t *sem, int pshared, unsigned int value);
```

- initialize an unnamed semaphore
- semaphore functionality is to lock the code for *arbitrary amount of threads*
  (depending on semaphore initial value i.e. the `value` parameter)

### Return value

- returns *0* on success
- on error, *-1* is returned, and `errno` is set to indicate the error

---

## `sem_wait`

```c
#include <semaphore.h>

int sem_wait(sem_t *sem);
```

- decrements (locks) the semaphore pointed to by `sem`
- if the semaphore's value is greater than *0*, then the decrement proceeds and the function returns, immediately
- if the semaphore currently has the value *0*, then the call blocks until either it becomes possible to perform
  the decrement (i.e. the semaphore value rises above *0*), or a signal handler interrupts the call

### Return value

- return *0* on success
- on error, the value of the semaphore is left unchanged, *-1* is returned, and `errno` is set to indicate the error

---

## `sem_post`

```c
#include <semaphore.h>

int sem_post(sem_t *sem);
```

- increments (unlocks) the semaphore pointed to by `sem`

### Return value

- return *0* on success
- on error, the value of the semaphore is left unchanged, *-1* is returned, and `errno` is set to indicate the error

---

## References

- <https://man7.org/linux/man-pages/man3/sem_init.3.html>
- <https://www.youtube.com/watch?v=YSn8_XdGH7c&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=21>

- <https://man7.org/linux/man-pages/man3/sem_wait.3.html>

- <https://man7.org/linux/man-pages/man3/sem_post.3.html>
