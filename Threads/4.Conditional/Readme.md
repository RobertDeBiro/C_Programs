## pthread_cond_init, pthread_cond_destroy
    #include <pthread.h>

    int pthread_cond_destroy(pthread_cond_t *cond);
    int pthread_cond_init(pthread_cond_t *restrict cond,
        const pthread_condattr_t *restrict attr);
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

 - initializes and destroys the condition variable

### Return value
 - if successful, the *pthread_cond_destroy()* and *pthread_cond_init()* functions shall return zero
 - otherwise, an error number shall be returned to indicate the error

### References
 - https://man7.org/linux/man-pages/man3/pthread_cond_init.3p.html
 - https://www.youtube.com/watch?v=0sVGnxg6Z3k&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=10
 - https://www.youtube.com/watch?v=RtTlIvnBw10&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=11

------------------------------------------------------------------------------------------------
## ptrhead_cond_signal, pthread_cond_broadcast
    #include <pthread.h>

    int pthread_cond_signal(pthread_cond_t *cond);
    int pthread_cond_broadcast(pthread_cond_t *cond);

 - signals and broadcasts a condition

### Return value
 - if successful, the *pthread_cond_broadcast()* and *pthread_cond_signal()* functions shall return zero - otherwise, an error number shall be returned to indicate the error

### References
 - https://man7.org/linux/man-pages/man3/pthread_cond_signal.3p.html
 - https://man7.org/linux/man-pages/man3/pthread_cond_broadcast.3p.html
 - https://www.youtube.com/watch?v=RtTlIvnBw10&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=11

------------------------------------------------------------------------------------------------
## pthread_cond_wait
    #include <pthread.h>

    int pthread_cond_wait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex);

 - wait on a condition

### Return value
 - upon successful completion, a value of zero shall be returned
 - otherwise, an error number shall be returned to indicate the error

### References
 - https://man7.org/linux/man-pages/man3/pthread_cond_wait.3p.html
