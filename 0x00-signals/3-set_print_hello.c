#include "signals.h"

/**
 * print_hello - fuction to print hello
 */
void print_hello(int sig_num)
{
	/* (void)sig_num; */
	write(STDOUT_FILENO, "Hello :)\n", 9);
}

/**
 * set_print_hello - fuction to set print_hello as the handler for SIGINT
 */
void set_print_hello(void)
{
	struct sigaction cigar;

	cigar.sa_handler = &print_hello;
	cigar.sa_flags = SA_RESTART;
	sigaction(SIGINT, &cigar, NULL);
}
