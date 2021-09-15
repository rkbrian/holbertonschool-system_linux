#include "signals.h"

/**
 * current_handler_signal - retrieve the current handler of the signal SIGINT
 * Return: pointer to the current handler of SIGINT, or NULL on failure
 */
void (*current_handler_signal(void))(int)
{
	if (current_handler_signal)
	{
		signal(SIGINT, current_handler_signal);
		return (current_handler_signal);
	}
	return (NULL);
}

/**
 * print_hello - fuction to print hello
 */
void print_hello(int)
{
	printf("Hello :)\n");
}

/**
 * set_print_hello - fuction to set print_hello as the handler for SIGINT
 */
void set_print_hello(void)
{
	current_handler_signal = print_hello;
}