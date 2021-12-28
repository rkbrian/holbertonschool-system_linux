#include "sockets.h"

/**
 * socket_server - open an IPv4/TCP socket and listen to traffic on port 8080,
 *  operations: socket, setsockopt, bind, listen
 * Return: socket's file descriptor, or -1 if failed
 */
int socket_server(void)
{
	int bind_status, socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in porty, addr_client;

	if (socket_fd == -1)
	{
		perror("Socket failed:");
		return (-1);
	}
	porty.sin_family = AF_INET, porty.sin_port = htons(PORT);
	porty.sin_addr.s_addr = htonl(INADDR_ANY);
	if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &porty, sizeof(int))
	    == -1)
	{
		perror("Setsockopt failed:"), close(socket_fd);
		return (-1);
	}
	bind_status = bind(socket_fd, (struct sockaddr *)&porty, sizeof(porty));
	if (bind_status == -1)
	{
		perror("Bind failed:"), close(socket_fd);
		return (-1);
	}
	listen(socket_fd, 2), printf("Server listening on port %d\n", PORT);
	return (socket_fd);
}
