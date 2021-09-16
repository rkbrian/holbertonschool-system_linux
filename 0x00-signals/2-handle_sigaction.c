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

/**
 * singer - print for handling ctrl-c signal
 * @sig_num: to be void
 */
void singer(int sig_num)
{
	(void)sig_num;
	write(STDOUT_FILENO, "Gotcha! [2]\n", 12);
	/* Note: printf() is not safe as the handler function to signal() */
}
