## SYNTAX
    #include <signal.h>
    
    int kill(pid_t pid, int sig)

 - used to send any signal to any process group or process i.e. signals are used to control the process
 - if pid is positive, then signal sig is sent to the process with the ID specified by pid
 - if sig is 0, then no signal is sent, but existence and permission checks are still performed

### Return value
 - on success (at least one signal was sent), zero is returned
 - on error, -1 is returned, and errno is set to indicate the error

### Other info
    kill -l

 - list all signal names and numbers in our system  

--------------------------------------------------------------
### References
 - https://man7.org/linux/man-pages/man2/kill.2.html
 - https://linuxhint.com/kill-signal-numbers-linux/
 - https://www.gnu.org/software/libc/manual/html_node/Standard-Signals.html
