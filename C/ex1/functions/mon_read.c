#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include "read.h"
#include <errno.h>

ssize_t mon_read(int fd, const void *buffer, size_t count){
    size_t total = 0; // total bytes successfully read 
    const char*ptr = buffer;

    while(total < count){
        ssize_t n = syscall(__NR_read, fd, ptr + total, count - total);
        // ptr + total = point to the first bytes not yet read
        // count - total = remaining bytes to read
        if( n < 0){
            if(errno == EINTR);//EINTR(interrupted by a signal)
            continue;
            perror("read syscall failed");
            return -1;
        } else if(n == 0){
            // connection closed by peer
            break;
        }
        total += n;
    }
    return total;
}
