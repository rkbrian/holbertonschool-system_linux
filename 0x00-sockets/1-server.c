#include "sockets.h"

#define PORT 12345

/**
 * main - open an IPv4/TCP socket, and listens to traffic on port 12345.
 *  must accept an entering connection, print the IP address of the
 *  connected client, and close the connection right after.
 * Return: 0 for successful exit, 1 if failed
 */
int main(void)
{
	int bind_status, socket_fd;
        socklen_t addrlen_client = sizeof(struct sockaddr);
	struct sockaddr_in porty, addr_client;

	porty.sin_family = AF_INET; /*store info of network addr*/
	porty.sin_port = htons(PORT);
	porty.sin_addr.s_addr = htonl(INADDR_ANY);
	/*create endpoint for comm*/
	socket_fd = socket(PF_INET, SOCK_STREAM, 0); /*normally 0, single protocol*/
	if (socket_fd == -1)
	{
		perror("Socket failed:");
		return (1);
	}
	bind_status = bind(socket_fd, (struct sockaddr *)&porty, sizeof(porty));
	if (bind_status == -1)
	{
		perror("Bind failed:");
		return (1);
	}
	listen(socket_fd, 2);
	printf("Server listening on port %d\n", PORT);
	if (accept(socket_fd, (struct sockaddr *)&addr_client, &addrlen_client) == -1)
	{
		perror("Accept error:");
		return (1);
	}
	printf("Client connected: %s\n", inet_ntoa(addr_client.sin_addr));
	return (0);
}
