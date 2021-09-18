#include "signals.h"

/**
 *
 */
int main(void)
{
	int pid;

	pid = fork();
	if (pid == 0)
	{
		printf("\n");
	}
	else
	{
		kill(pid, SIGSTOP);
	}
	return (0);
}
