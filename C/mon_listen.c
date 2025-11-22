#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int mon_listen(int sockfd, int backlog){
    int listening = syscall(__NR_listen, sockfd, backlog);
    if(listening < 0){
        perror("mon_listen failed");
    }
    return listening;
}