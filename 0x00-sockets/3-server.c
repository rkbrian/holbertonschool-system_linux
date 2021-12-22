#include "sockets.h"

#define PORT 12345

/**
 * main - open an IPv4/TCP socket, and listen to traffic on port 12345.
 *  Must accept an entering connection, print IP addr of the cnnctd client,
 *  wait for an incoming msg from the cnnctd client, print this msg,
 *  close the connection with the client, and exit.
 * Return: 0 for successful exit, 1 if failed
 */
int main(void)
{
	int bind_status, socket_fd = socket(AF_INET, SOCK_STREAM, 0), acc_fd;
	socklen_t addrlen_client = sizeof(struct sockaddr);
	struct sockaddr_in porty, addr_client;
	char buffalo[1024];

	if (socket_fd == -1)
	{
		perror("Socket failed:");
		exit(1);
	}
	porty.sin_family = AF_INET, porty.sin_port = htons(PORT);
	porty.sin_addr.s_addr = htonl(INADDR_ANY);
	if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &porty, sizeof(int))
	    == -1)
	{
		perror("Setsockopt failed:"), close(socket_fd);
		exit(1);
	}
	bind_status = bind(socket_fd, (struct sockaddr *)&porty, sizeof(porty));
	if (bind_status == -1)
	{
		perror("Bind failed:"), close(socket_fd);
		exit(1);
	}
	listen(socket_fd, 2), printf("Server listening on port %d\n", PORT);
	acc_fd = accept(socket_fd, (struct sockaddr *)&addr_client, &addrlen_client);
	if (acc_fd == -1)
	{
		perror("Accept error:"), close(socket_fd);
		exit(1);
	}
	printf("Client connected: %s\n", inet_ntoa(addr_client.sin_addr));
	if (recv(acc_fd, buffalo, sizeof(buffalo), 0) == -1)
	{
		perror("Receive message error:"), close(acc_fd), close(socket_fd);
		exit(1);
	}
	printf("Message received: \"%s\"\n", buffalo);
	close(acc_fd), close(socket_fd);
	return (0);
}
