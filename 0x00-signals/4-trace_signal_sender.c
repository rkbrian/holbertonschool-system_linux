#include "signals.h"

/**
 * trace_signal_sender - defines a handler for SIGQUIT (Control-\ in a shell)
 * Return: 0 on success, or -1 on error
 */
int trace_signal_sender(void)
{
	struct sigaction cigar;

	cigar.sa_handler = &sigma;
	cigar.sa_flags = SA_RESTART;
	return (sigaction(SIGQUIT, &cigar, NULL));
}

/**
 * sigma - print for handling ctrl-\ signal
 * @sig_num: to be void
 */
void sigma(int sig_num)
{
	long int num = getpid();

	(void)sig_num;
	write(STDOUT_FILENO, "SIGQUIT sent by ", 16);
	/* Note: printf() is not safe as the handler function to signal() */
	write(STDOUT_FILENO, num, sizeof(long int));
	write(STDOUT_FILENO, "\n", 1);
}