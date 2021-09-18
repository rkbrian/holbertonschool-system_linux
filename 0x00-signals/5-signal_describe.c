#include "signals.h"

/**
 * main - prints a description of a given signal, assume always a number
 * @argc: argument count
 * @argv: argument strings
 * Return: 0 or exit failure
 */
int main(int argc, char *argv[])
{
	sidi di[] = {{1, "Hangup"}, {2, "Interrupt"}, {7, "Bus error"},
		     {3, "Quit"}, {19, "Paused"}, {20, "Stopped"}, {6, "Aborted"},
		     {5, "Trace/breakpoint trap"}, {4, "Illegal instruction"}, {9, "Killed"},
		     {8, "Floating point exception"}, {10, "User defined signal 1"}};
	int i;

	if (argc != 2)
		printf("Usage: %s <signum>\n", argv[0]), exit(EXIT_FAILURE);
	for (i = 0; di[i].sig_name != NULL; i++)
		if (atoi(argv[1]) == di[i].n)
			return (printf("%d: %s\n", atoi(argv[1]), di[i].sig_name));
	return (printf("%d: Unknown signal %d\n", atoi(argv[1]), atoi(argv[1])));
}
