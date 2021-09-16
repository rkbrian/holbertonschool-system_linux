#include "signals.h"

/**
 * current_handler_signal - retrieve the current handler of the signal SIGINT
 * Return: pointer to the current handler of SIGINT, or NULL on failure
 */
void (*current_handler_signal(void))(int)
{
	void (*handler)(int);

	handler = signal(SIGINT, SIG_DFL); /* signal returns previous handler addr */
	/* change handler back to print_hello from sig_dfl */
	if (signal(SIGINT, handler) == SIG_ERR)
		return (NULL);
	return (handler);
}
