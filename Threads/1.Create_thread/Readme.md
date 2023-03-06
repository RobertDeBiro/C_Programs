## PTHREAD_CREATE
    #include <pthread.h>

    int pthread_create(pthread_t *restrict thread,
                       const pthread_attr_t *restrict attr,
                       void *(*start_routine)(void *),
                       void *restrict arg);

 - starts a new thread in the calling process
 - parameters:
    - *thread*
        - pointer to pthread_t variable
    - *attr*
        - custom attributes for the thread
        - NULL sets everything as default
    - *start_routine*
        - thread function pointer
        - this function pointer must point to function that receives void* object (doesn't receive object at all) and returns void* object (doesn't return anything at all, but must be a pointer)
    - *arg*
        - thread function parameters

### Return value
 - on success, pthread_create() returns 0
 - on error, it returns an error number, and the contents of *thread are undefined

### References
 - https://man7.org/linux/man-pages/man3/pthread_create.3.html
 - https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2

-----------------------------------------------------------------------------------
## PTHREAD_JOIN

    #include <pthread.h>

    int pthread_join(pthread_t thread, void **retval);

 - waits for the thread specified by *thread* to terminate
 - parameters:
    - *thread*
        - pthread_t variable
    - *retval*
        - pointer that saves the result from the thread

### Return value
 - on success, pthread_join() returns 0
 - on error, it returns an error number

### References
 - https://man7.org/linux/man-pages/man3/pthread_join.3.html
