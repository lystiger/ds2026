#include <stdio.h>
#include <sys/syscall.h>
#include <sys/socket.h>

int mon_bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
    int binding = syscall(__NR_bind, sockfd, addr, addrlen);
    if(binding < 0){
        perror("mon_bind failed");
    }
    return binding;
}
//nothing to explain it is the same as connect, socket, if u r curious go back there