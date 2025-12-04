#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

//headers
#include "socket.h"
#include "read.h"
#include "write.h"
#include "connect.h" 
#include "listen.h"  
#include "accept.h"  
#include "close.h"
#include "bind.h"   

int main() {
    int host = mon_socket(AF_INET, SOCK_STREAM, 0);
    if(host < 0){
        perror("Socket creation failed");
        return 1;
    }

    // Allow reuse of local addresses
    int yes = 1;
    if (setsockopt(host, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt");
        mon_close(host);
        return 1;
    }

    // Hardcode for testing, do not blame me im sad
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET; //IPv4
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = INADDR_ANY; // accept connections from any IP
    memset(server_addr.sin_zero, 0, 8);

    if(mon_bind(host, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        mon_close(host);
        return 1;
    }

    // Listen for connections
    if(mon_listen(host, 1) < 0){
        mon_close(host);
        return 1;
    }
    printf("Server listening on port 1..2......3.......4.....5.\n");

    // Accept a client
    int client = mon_accept(host, NULL, NULL); // can store client addr if needed
    if(client < 0){
        mon_close(host);
        return 1;
    }
    printf("Client connected successfully let's gooo!\n");

    // Read message from the client
    char buffer[1024];
    ssize_t n = mon_read(client, buffer, sizeof(buffer)-1);
    if(n > 0){
        buffer[n] = '\0';
        printf("Client telling that: %s\n", buffer);
    }

    // Send response to that cocky client
    char *reply = "Hey what do u think u are!";
    mon_write(client, reply, strlen(reply));

    // Close the sockets
    mon_close(client);
    mon_close(host);

    return 0;
}
