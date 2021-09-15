#include "signals.h"

/**
 * handle_signal - function that set a handler for the signal SIGINT
 * Return: 0 on success, -1 on error
 */
int handle_signal(void)
{
	int sig_num = SIGINT;

	if (sig_num == 2)
	{
		signal(sig_num, singer);
		return (0);
	}
	else
		return (-1);
}

/**
 * singer - print for handling ctrl-c signal
 * @sig_num: to be void
 */
void singer(int sig_num)
{
	(void)sig_num;
	printf("Gotcha! [2]\n");
}
