## pthread_mutex_init, pthread_mutex_destroy
    #include <pthread.h>

    int pthread_mutex_destroy(pthread_mutex_t *mutex);
    int pthread_mutex_init(pthread_mutex_t *restrict mutex,
        const pthread_mutexattr_t *restrict attr);
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

 - initializes and destroys the mutex object
 - mutex variable is used when several threads can change some global variable
 - parameters:
    - *mutex*
        - pointer to mutex object
    - *attr*
        - custom_attributes
        - if we pass NULL as custom attributes, everything is set to default

### Return value
 - if successful, the *pthread_mutex_destroy()* and *pthread_mutex_init()* functions shall return zero
 - otherwise, an error number shall be returned to indicate the error

### References
 - https://man7.org/linux/man-pages/man3/pthread_mutex_init.3p.html
 - https://man7.org/linux/man-pages/man3/pthread_mutex_destroy.3p.html
 - https://www.youtube.com/watch?v=FY9livorrJI&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=3
 - https://www.youtube.com/watch?v=oq29KUy29iQ&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=4