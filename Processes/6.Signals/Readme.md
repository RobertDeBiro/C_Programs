## KILL
    #include <signal.h>
    
    int kill(pid_t pid, int sig)

 - the *kill()* system call can be used to send any signal to any process group or process
 - if pid is positive, then signal sig is sent to the process with the ID specified by pid
 - if sig is 0, then no signal is sent, but existence and permission checks are still performed

### Return value
 - on success (at least one signal was sent), zero is returned
 - on error, -1 is returned, and errno is set to indicate the error

### Terminal commands
    kill -l

 - list all signal names and numbers in our system  

### References
 - https://man7.org/linux/man-pages/man2/kill.2.html
 - https://linuxhint.com/kill-signal-numbers-linux/
 - https://www.gnu.org/software/libc/manual/html_node/Standard-Signals.html

--------------------------------------------------------------------------------------------------
## SIGACTION
    #include <signal.h>

    int sigaction(int signum, const struct sigaction *restrict act,  
                  struct sigaction *restrict oldact);

    struct sigaction {
        void     (*sa_handler)(int);
        void     (*sa_sigaction)(int, siginfo_t *, void *);
        sigset_t   sa_mask;
        int        sa_flags;
        void     (*sa_restorer)(void);
    };

 - the *sigaction()* system call is used to change the action taken by a process on receipt of a specific signal
 - *signum*
    - signal that will be handled, e.g:
        - SIGTSTP - stop signal, i.e. putting process to background
 - *act*
    - sigaction struct address
 - *oldact*
    - function that restores handling signal behavior
 - struct sigaction:
    - *sa_handler*
        - saves pointer to a function that will be called whenever a certain signal is received
    - *sa_flags*
        - specifies a set od flags which modify the behavior of the signal

### References
 - https://man7.org/linux/man-pages/man2/sigaction.2.html
