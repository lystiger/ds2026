#ifndef WRITE_H
#define WRITE_H
#include <stdio.h>

ssize_t mon_write(int fd, const void* buffer, size_t count);
// Problems:
// +) Might not write all bytes since it is a must to loop all bytes are sent 
// +) Return -1 or errno if bad things occur
// +) write() blocks until buffer has a room, also may return EAGAIN(resource temporarily unavailable) when not accepting the data
//                                                            EINTR(interrupted by a signal)
//                                                            EBADF(invalid fd)
//                                                            ECONNREFUSED(connection refused for sockets)
//                                                            EPIPE(waiting to a closed pipe/socket)
#endif