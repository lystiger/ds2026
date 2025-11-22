#include <stdio.h>
#include <unistd.h>
#include "headers/socket.h"
#include "headers/connect.h"
#include <sys/socket.h>
#include <string.h>

#include <arpa/inet.h> // for inet_addr()
#include <netinet/in.h> // for sockaddr_in

int main(){
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    // AF = Address Family, INET = IPv4, INET6 = IPv6, UNIX = local sockets
    // SOCK_STREAM = TCP (reliable)
    // SOCK_DGRAM = UPD (unreliable)
    // SOCK_RAW = raw IP
    if(fd >= 0){
        printf("Socket created !\n");
        printf("fd = %d\n", fd);
    } else {
        printf("Failed to create socket !!! U die.\n");
    }

    // This is the part where i setup the server
    // IPv4 or IPv6 can be changed here
    struct sockaddr_in server_addr; // change to sockaddr_in6 for IPv6

    // I used the sockaddr_in because i can access sin_fam,...
    server_addr.sin_family = AF_INET; // ou INET6
    server_addr.sin_port = htons(12345); //hardcoded for now but what is htons? 
                                         // since 12345 is just normal integer, htons(host to network short with 2 byte int)
                                         // so it converts integer to network format
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    memset(server_addr.sin_zero,0, 8);
    // Memset is for filling block of memory with a value, i think its parameters are ptr, value, num
    // with ptr is the pointer to start of memo, value for byte value from 0 - 255 and num is number of bytes

    // Defining the connection
    int connection = mon_connect(fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Connecting
    if (connection >= 0){
        printf("Connected");
    } else {
        perror("Connect failed u idiot");
    }    
        close(fd);
    return 0;
}

//Im a newbie so this is my place
// fd = 0 = stdin
// fd = 1 = stdout
// fd = 2 = stderr
// fd = 3 = next open file = normal