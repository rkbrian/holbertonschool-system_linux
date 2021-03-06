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
void path_query_printer(char *buffalo);
void headers_printer(char *buffalo);
void path_bodypara_printer(char *buffalo);

#endif /* SOCKETS_H */
