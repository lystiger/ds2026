#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "headers/connect.h"

int mon_connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
    
    int connection = syscall(__NR_connect, sockfd, addr, addrlen);
    // same as __NR_socket but this time the connection gets a number as passed with those upper parameters
    if (connection < 0){
        perror("Connect syscall failed duh !");
    }
        return connection;
}