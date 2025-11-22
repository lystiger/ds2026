#ifndef READ_H
#define READ_H

#include <stdio.h>

ssize_t read(int fd, void* buffer, size_t count);
// fd = file descriptor
// buffer = u know it
// count = maximum number of bytes readed

// some key ideas
// +) might receive fewer bytes
// +) blocks until at least 1 byte is available
// +) read() returns 0 at EOF for files while for sockets 0 means peer closed the connection
#endif