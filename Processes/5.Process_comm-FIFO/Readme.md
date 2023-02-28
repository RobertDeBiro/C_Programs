## SYNTAX
    #include <sys/types.h>
    #include <sys/stat.h>

    int mkfifo(const char *pathname, mode_t mode)

 - makes a FIFO special file with name *pathname*
 - *mode* specifies the FIFO's permissions, such as *prwxrwxr-x*
 - a FIFO special file is similar to a pipe, except that it is created in a different way

### Return value
 - on success mkfifo() and mkfifoat() return 0
 - on error, -1 is returned and errno is set to indicate the error

---------------------------------------------------------------------------
## SYNTAX
    #include <fcntl.h>
    
    int open(const char *pathname, int flags);
    int open(const char *pathname, int flags, mode_t mode);

 - opens fifo file specified by the *pathname*
    - however, it can be oppened only if other process started reading from it
    - that is because fifo actually replaces a pipe - it is a file that acts like a pipe
    - since pipe is opened on both ends, the fifo must be also
 - flags:
    - O_RDONLY
    - O_WRONLY
    - O_RDWR

### Return value
 - the return value of open() is a file descriptor, a small, nonnegative integer that is an index to an
   entry in the process's table of open file descriptors

---------------------------------------------------------------------------
### References
 - https://man7.org/linux/man-pages/man3/mkfifo.3.html
 - https://man7.org/linux/man-pages/man2/open.2.html