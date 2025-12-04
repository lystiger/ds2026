#ifndef BIND_H
#define BIND_H
#include <sys/socket.h>

int mon_bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

#endif