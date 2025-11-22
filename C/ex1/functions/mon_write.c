#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include "headers/write.h"
#include <errno.h>

ssize_t mon_write(int fd, const void *buffer, size_t count){
    size_t total = 0; // total bytes successfully written 
    const char*ptr = buffer;

    while(total < count){
        ssize_t n = syscall(__NR_write, fd, ptr + total, count - total);
        // ptr + total = point to the first bytes not yet sent
        // count - total = remaining bytes to write
        if( n < 0){
            if(errno == EINTR);//EINTR(interrupted by a signal)
            continue;
        } else {
            perror("write syscall failed");
            return -1;
        }
        total += n;
    }
    return total;
}
