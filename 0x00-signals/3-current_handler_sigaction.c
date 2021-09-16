#include "signals.h"

/**
 * current_handler_sigaction - retrieve the current handler of the signal SIGINT
 * 
 */
void (*current_handler_sigaction(void))(int)
{
	void (*handler)(int);
	struct sigaction cigar;

	handler = cigar.sa_handler;
	if (handler == SIG_ERR)
		return (NULL);
	return (handler);
}