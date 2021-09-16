#include "signals.h"

/**
 * main - prints a description of a given signal, assume always a number
 * @argc: argument count
 * @argv: argument strings
 * Return: 0 or exit failure
 */
int main(int argc, char *argv[])
{
	sig_dic dict[] = {{1, "Hangup"}, {2, "Interrupt"}, {3, "Quit"}, {9, "Killed"},
			  {20, "Stopped"}, {19, "Paused"}, {4, "Illegal"}, {18, "Resume"},
			  {6, "Abort"}, {15, "Terminated"}};
	int i;

	if (argc != 2)
		printf("Usage: %s <signum>\n", argv[0]), exit(EXIT_FAILURE);
	for (i = 0; dict[i].sig_name != NULL; i++)
		if (atoi(argv[1]) == dict[i].n)
			return(printf("%d: %s\n", atoi(argv[1]), dict[i].sig_name));
	return(printf("%d: Unknown signal %d\n", atoi(argv[1]), atoi(argv[1])));
}
