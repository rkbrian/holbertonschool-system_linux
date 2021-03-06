#include "sockets.h"

#define PORT 12345

/**
 * main - open an IPv4/TCP socket, and listens to traffic on port 12345.
 *  Must hang indefinitely (to be killed by a signal during correction),
 *  don’t have to accept entering connections.
 * Return: 0 for successful exit, 1 if failed
 */
int main(void)
{
	int bind_status, socket_fd;
	struct sockaddr_in porty;

	/*create endpoint for comm; AF. = PF. in Windows, in Linux slightly diff*/
	socket_fd = socket(PF_INET, SOCK_STREAM, 0); /*normally 0, single protocol*/
	if (socket_fd == -1)
	{
		perror("Socket failed:");
		exit(1);
	}
	porty.sin_family = AF_INET; /*store info of network addr*/
	porty.sin_port = htons(PORT);
	porty.sin_addr.s_addr = htonl(INADDR_ANY);
	bind_status = bind(socket_fd, (struct sockaddr *)&porty, sizeof(porty));
	if (bind_status == -1)
	{
		perror("Bind failed:");
		close(socket_fd);
		exit(1);
	}
	listen(socket_fd, 2);
	printf("Server listening on port %d\n", PORT);
	pause();
	close(socket_fd);
	return (0);
}
