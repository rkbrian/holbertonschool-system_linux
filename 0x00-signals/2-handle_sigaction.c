#include "signals.h"

/**
 * handle_sigaction - set a handler for the signal SIGINT
 * Return: 0 on success, or -1 on error
 */
int handle_sigaction(void)
{
	struct sigaction cigar;

	cigar.sa_handler = &singer;
	cigar.sa_flags = SA_RESTART;
	return (sigaction(SIGINT, &cigar, NULL));
}
