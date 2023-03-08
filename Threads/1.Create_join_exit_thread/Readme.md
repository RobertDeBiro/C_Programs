## pthread_create
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
        - function pointer to thread function
        - this function pointer, according to its declaration, must point to function that receives void* object and returns void* object
            - hence thread function must satisfy all those conditions
    - *arg*
        - thread function parameters

### Return value
 - on success, pthread_create() returns 0
 - on error, it returns an error number, and the contents of *thread are undefined

### References
 - https://man7.org/linux/man-pages/man3/pthread_create.3.html
 - https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2
 - https://www.youtube.com/watch?v=HDohXvS6UIk&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=7

-----------------------------------------------------------------------------------
## pthread_join
    #include <pthread.h>

    int pthread_join(pthread_t thread, void **retval);

 - waits for the thread specified by *thread* to terminate
 - parameters:
    - *thread*
        - pthread_t variable
    - *retval*
        - double pointer that saves the result from the thread
        - in addition to doing some actions, threads can also returns some value by using *retval* parameter

### Return value
 - on success, pthread_join() returns 0
 - on error, it returns an error number

### References
 - https://man7.org/linux/man-pages/man3/pthread_join.3.html
 - https://www.youtube.com/watch?v=ln3el6PR__Q&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=6

-----------------------------------------------------------------------------------
## pthread_exit

    #include <pthread.h>

    noreturn void pthread_exit(void *retval);

 -  terminates the calling thread and returns a value via *retval* that (if the thread is joinable) is
    available to another thread in the same process that calls *pthread_join(3)*

### Return value
 - this function does not return to the caller

### References
 - https://man7.org/linux/man-pages/man3/pthread_exit.3.html
 - https://www.youtube.com/watch?v=w_8bFrHUK5Q&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=13