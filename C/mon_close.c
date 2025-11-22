#include <stdio.h>
#include <sys/syscall.h>

int mon_close(int fd){
    int closing = syscall(__NR_close, fd);
    if(closing < 0){
        perror("mon_close failed");
    }
    return closing;
}
