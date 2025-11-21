#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "socket.h"

int socket(int domain, int type, int protocol){
    int fd = syscall(__NR_socket, domain, type, protocol); //fd = file descriptors
    if (fd < 0){
        perror("socket syscall failed");
        return -1;
    } else {
    return fd;
    }
}