#include "sockets.h"

/**
 * main - connects to a listening server.
 * @argc: argument count
 * @argv: argument strings
 * Return: 0 for successful exit, 1 if failed
 */
int main(int argc, char *argv[])
{
	int socket_fd;
	struct addrinfo hints, *host_ai;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
		exit(1);
	}
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET, hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	if (getaddrinfo(argv[1], argv[2], &hints, &host_ai))
	{
		perror("Getaddrinfo failed:");
		exit(1);
	}
	socket_fd = socket(host_ai->ai_family, host_ai->ai_socktype,
			   host_ai->ai_protocol);
	if (socket_fd == -1)
	{
		perror("Socket failed:");
		exit(1);
	}
	if (connect(socket_fd, host_ai->ai_addr, host_ai->ai_addrlen) == -1)
	{
		perror("Connect failed:");
		exit(1);
	}
	printf("Connected to %s:%s\n", argv[1], argv[2]);
	freeaddrinfo(host_ai);
	close(socket_fd);
	return (0);
}
