#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include "read.h"
#include <errno.h>

ssize_t mon_read(int fd, void *buffer, size_t count){
    ssize_t n;
    // Loop to handle EINTR (interrupted system call)
    do {
        n = syscall(__NR_read, fd, buffer, count);
    } while (n < 0 && errno == EINTR);

    // If 'n' is still negative, an actual error occurred during the read syscall.
    // We print the error and return 'n' (which will be -1).
    // The caller is responsible for checking the return value of mon_read.
    if (n < 0) {
        perror("read syscall failed");
    }
    // If 'n' is 0, it indicates that the peer has closed its connection (EOF).
    // If 'n' is positive, it indicates the number of bytes successfully read.
    // The caller is responsible for processing the received data,
    // as mon_read now returns whatever data is available up to 'count',
    // rather than waiting for 'count' bytes to be fully filled.
    return n;
}
