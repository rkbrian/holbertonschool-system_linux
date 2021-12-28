#include "sockets.h"

/**
 * header_printer - function to print the headers key/value pairs
 *  of the received HTTP request.
 * @buffalo: buffer that stores the HTTP request
 */
void header_printer(char *buffalo)
{
	char *buffalo_chop, *header_name, *header_val;

	strtok_r(buffalo, "\r\n", &buffalo_chop);
	header_name = strtok_r(NULL, ":", &buffalo_chop);
	header_val = strtok_r(NULL, "\r", &buffalo_chop);
	while (header_name && header_val)
	{
		printf("Header: \"%s\" -> \"%s\"\n", ++header_name, ++header_val);
		header_name = strtok_r(NULL, ":", &buffalo_chop);
		header_val = strtok_r(NULL, "\r", &buffalo_chop);
	}
}

/**
 * accept_console - accept an entering connection and keep printing
 * @socket_fd: the socket file descriptor
 * Return: 0 for successful exit, 1 if failed 
 */
int accept_console(int socket_fd)
{
	int acc_fd, read_bytes;
	char buffalo[1024], *resp_msg = "HTTP/1.1 200 OK\r\n\r\n";
	struct sockaddr_in addr_client;
	socklen_t addrlen_client = sizeof(struct sockaddr);

	while (1)
	{
		acc_fd = accept(socket_fd, (struct sockaddr *)&addr_client, &addrlen_client);
		if (acc_fd == -1)
		{
			perror("Accept error:"), close(socket_fd);
			exit(1);
		}
		printf("Client connected: %s\n", inet_ntoa(addr_client.sin_addr));
		read_bytes = recv(acc_fd, buffalo, sizeof(buffalo), 0);
		if (read_bytes == -1)
		{
			perror("Receive message error:"), close(acc_fd), close(socket_fd);
			exit(1);
		}
		else if (read_bytes > 0)
			printf("Raw request: \"%s\"\n", buffalo);
		header_printer(buffalo);
		send(acc_fd, resp_msg, strlen(resp_msg), 0);
		close(acc_fd);
	}
	return (0);
}

/**
 * main - open an IPv4/TCP socket and listen to traffic on port 8080.
 *  Must do: Accept an entering connection,
 *  Print the IP address of the connected client,
 *  Wait for an incoming message from the connected client,
 *  Print the full received HTTP request,
 *  Print the headers key/value pairs of the received HTTP request,
 *  Send back a response to the connected client (HTTP 200 OK),
 *  Close the connection with the client, Wait for the next connection.
 * Return: 0 for successful exit, 1 if failed
 */
int main(void)
{
	int socket_fd;

	setbuf(stdout, NULL);
	socket_fd = socket_server();
	if (socket_fd == -1)
		exit(1);
	accept_console(socket_fd);
	close(socket_fd);
	return (0);
}
