#include "signals.h"

/**
 * print_hello - fuction to print hello
 */
void print_hello(int sig_num)
{
	(void)sig_num;
	printf("Hello :)\n");
}

/**
 * set_print_hello - fuction to set print_hello as the handler for SIGINT
 */
void set_print_hello(void)
{
	signal(SIGINT, print_hello);
}
