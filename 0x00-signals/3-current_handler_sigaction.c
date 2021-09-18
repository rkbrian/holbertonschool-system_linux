#include "signals.h"

/**
 * current_handler_sigaction - retrieve the current handler of SIGINT
 * Return: pointer to the current handler of SIGINT, or NULL on failure
 */
void (*current_handler_sigaction(void))(int)
{
	/* void (*handler)(int); */
	struct sigaction cigar;

	if (cigar.sa_handler == SIG_ERR || cigar.sa_handler == SIG_DFL)
		return (NULL);
	return (cigar.sa_handler);
}
