#include "signals.h"

/**
 * print_hello - fuction to print hello
 * @sig_num: to be void
 */
void print_hello(int sig_num)
{
	(void)sig_num;
	write(STDOUT_FILENO, "Hello :)\n", 9);
}

/**
 * set_print_hello - fuction to set print_hello as the handler for SIGINT
 */
void set_print_hello(void)
{
	signal(SIGINT, print_hello);
}
