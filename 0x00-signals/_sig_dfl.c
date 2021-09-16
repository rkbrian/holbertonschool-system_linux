#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

/**
 * main - in case things go wrong, this should set SIGINT back to normal
 * Return: 0
 */
int main(void)
{
	struct sigaction cigar;

	cigar.sa_flags = SA_RESETHAND;
	sigaction(SIGINT, &cigar, NULL);
	return (0);
}
