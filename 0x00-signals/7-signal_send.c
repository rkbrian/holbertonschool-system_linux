#include "signals.h"

/**
 * main - sends the signal SIGINT to a process, given its PID
 * @argc: argument count
 * @argv: argument strings
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	int kill_ret;

	if (argc != 2 || atoi(argv[1]) == 0)
		printf("Usage: %s <pid>\n", argv[0]), exit(EXIT_FAILURE);
	kill_ret = kill(atoi(argv[1]), SIGINT);
	if (kill_ret == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
