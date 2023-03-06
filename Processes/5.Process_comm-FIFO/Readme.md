## MKFIFO
    #include <sys/types.h>
    #include <sys/stat.h>

    int mkfifo(const char *pathname, mode_t mode)

 - makes a FIFO special file with name *pathname*
 - *mode* specifies the FIFO's permissions, such as *prwxrwxr-x*
 - a FIFO special file is similar to a pipe, except that it is created in a different way
   - pipe:
      - inside our program we must create an array with two elements (file descriptor) and pipe with that array
   - FIFO:
      - we only need to create FIFO file, and that can be done either inside our program or inside terminal, hence it is less complicated then pipe

### Return value
 - on success mkfifo() and mkfifoat() return 0
 - on error, -1 is returned and errno is set to indicate the error

### References
 - https://man7.org/linux/man-pages/man3/mkfifo.3.html

---------------------------------------------------------------------------
## OPEN
    #include <fcntl.h>
    
    int open(const char *pathname, int flags);
    int open(const char *pathname, int flags, mode_t mode);

 - opens fifo file specified by the *pathname*
 - flags:
    - O_RDONLY
    - O_WRONLY
    - O_RDWR

### Return value
 - the return value of open() is a file descriptor, a small, nonnegative integer that is an index to an
   entry in the process's table of open file descriptors

### References
 - https://man7.org/linux/man-pages/man2/open.2.html