#include <stdio.h>
#include <unistd.h>
#include "socket.h"
#include <sys/socket.h>

int main(){
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    // AF = Address Family, INET = IPv4, INET6 = IPv6, UNIX = local sockets
    // SOCK_STREAM = TCP (reliable)
    // SOCK_DGRAM = UPD (unreliable)
    // SOCK_RAW = raw IP
    
    if(fd >= 0){
        printf("Socket created !\n");
        printf("fd = %d\n", fd);
        close(fd);
    } else {
        printf("Failed to create socket !!! U die.\n");
    }

    return 0;
}