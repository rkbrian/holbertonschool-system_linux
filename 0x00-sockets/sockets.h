#ifndef SOCKETS_H
#define SOCKETS_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

int socket_server(void);
int accept_console(int socket_fd);

#endif /* SOCKETS_H */
