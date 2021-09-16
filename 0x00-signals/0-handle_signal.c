#include "signals.h"

/**
 * handle_signal - function that set a handler for the signal SIGINT
 * Return: 0 on success, -1 on error
 */
int handle_signal(void)
{
	if (signal(SIGINT, singer) == SIG_ERR)
		return (-1);
	return (0);
}

/**
 * singer - print for handling ctrl-c signal
 * @sig_num: to be void
 */
void singer(int sig_num)
{
	/* (void)sig_num; */
	write(STDOUT_FILENO, "Gotcha! [2]\n", 12);
	/* Note: printf() is not safe as the handler function to signal() */
}
