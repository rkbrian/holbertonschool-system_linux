#include "signals.h"

/* capture_flag - flag showing the sigint is retrieved */
int capture_flag = 0;

/**
 * main - set a handler for SIGINT, exit after signal is received and handled
 * Return: 0
 */
int main(void)
{
	/*int sig_num;*/
	struct sigaction cigar;

	cigar.sa_handler = &cigarette;
	cigar.sa_flags = SA_RESTART;
	sigaction(SIGINT, &cigar, NULL);
sigma:
	/*printf("\n");*/
	/*fflush(stdout);*/
	if (capture_flag == 1)
	{
		printf("Signal received\n");
		return (EXIT_SUCCESS);
	}
	/*scanf("%d", &sig_num);*/
	goto sigma;
	return (EXIT_SUCCESS);
}

/**
 * cigarette - fuction to capture SIGINT
 * @sigourney: input control-c
 */
void cigarette(int sigourney)
{
	if (sigourney == SIGINT)
	{
		write(STDOUT_FILENO, "Caught 2\n", 9);
		capture_flag = 1;
	}
}

/**
 * zygons - suspend the function
 */
void zygons(void)
{
}
