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

------------------------------------------------------------------------------------------------
## pthread_mutex_lock, pthread_mutex_trylock, pthread_mutex_unlock

    #include <pthread.h>

    int pthread_mutex_lock(pthread_mutex_t *mutex);
    int pthread_mutex_trylock(pthread_mutex_t *mutex);
    int pthread_mutex_unlock(pthread_mutex_t *mutex);

 - lock and unlock a mutex
 - *pthread_mutex_trylock* locks execution of the code for every function except one
    - in normal mutex example function waits for mutex being unlocked and then starts executing the code, whereas here, if it is locked, it just skip that part of the code

### Return value
 - if successful, the *pthread_mutex_lock()*, *pthread_mutex_trylock()*, and *pthread_mutex_unlock()* functions shall return zero;
 - otherwise, an error number shall be returned to indicate the error

### References
 - https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html

 ------------------------------------------------------------------------------------------------
 ### References
 - https://www.youtube.com/watch?v=FY9livorrJI&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=3
 - https://www.youtube.com/watch?v=oq29KUy29iQ&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=4
 - https://www.youtube.com/watch?v=xoXzp4B8aQk&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=5
 - https://www.youtube.com/watch?v=OIKr2ll2Nd8&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=9