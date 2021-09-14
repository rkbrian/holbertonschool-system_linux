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
		signal(sig_num, printf("Gotcha! [%d]\n", sig_num));
		return (0);
	}
	else
		return (-1);
}