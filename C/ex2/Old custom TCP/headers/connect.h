#ifndef CONNECT_H
#define CONNECT_H
#include <sys/socket.h> //for struct sockaddr and socklen_t

int mon_connect(int sockfd, const struct sockaddr *addr, socklen_t alen);
// using struct sockaddr for a generic address structure
// par exemple: struct sockaddr {
//                       unsigned short sa_family; (address family like INET or UNIX)
//                       char sa_data[14]          (protocol-specific address data)

// im also using pointer to access and read the address the socket will be connect to

// socklen_t is the size of the socket address because the kernel needs to know how many
// bytes i passed from my struct
#endif 