#include <stdio.h>
#include <sys/syscall.h>
#include <sys/socket.h>
#include <unistd.h>

int mon_accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen){
    int acception = syscall(__NR_accept, sockfd, addr, addrlen);
    if(acception < 0){
        perror("mon_accept failed");
    }
    return acception;
}

// return a new scoket fd to talk with that client