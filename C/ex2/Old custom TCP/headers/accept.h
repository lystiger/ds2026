#ifndef ACCEPT_H
#define ACCEPT_H
#include <sys/socket.h>

int mon_accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

#endif