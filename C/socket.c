#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "socket.h"

int socket(int domain, int type, int protocol){
    int fd = syscall(__NR_socket, domain, type, protocol); //fd = file descriptors
    //__NR_socket: Since i have a petit brain, i will explain within my understanding.
    //             In linux every syscall has an unique number and __NR_socket is the
    //             number that assigned to the socket() syscall
    // So when i do int fd = ... => im telling the kernel to run the syscall for creating
    // a __NR_socket with arguments like domain, type and protocol, that's is. 
    if (fd < 0){
        perror("socket syscall failed");
        // If error it will print socket syscall failed: Connection refused
        return -1;
    } else {
    return fd;
    }
}