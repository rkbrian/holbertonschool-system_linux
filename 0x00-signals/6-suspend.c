#include "signals.h"

/* capture_flag - flag showing the sigint is retrieved */
/*int capture_flag = 0;*/

/**
 * main - set a handler for SIGINT, exit after signal is received and handled
 * Return: 0
 */
int main(void)
{
	int sig_num;

	/*cigar.sa_handler = &cigarette;*/
	/*cigar.sa_flags = SA_RESTART;*/
	/*printf("\n");*/
	if (signal(SIGINT, cigarette) == SIG_ERR)
		zygons();
	else
	{
		scanf("%d", &sig_num);
		signal(SIGINT, cigarette);
		fflush(stdout);
		signal(SIGINT, SIG_DFL);
		printf("Caught 2\nSignal received\n");
		return (EXIT_SUCCESS);
	}
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
		write(STDOUT_FILENO, "Caught ", 7);
		write(STDOUT_FILENO, &sigourney, sizeof(int));
		write(STDOUT_FILENO, "\n", 1);
		/*capture_flag = 1;*/
	}
}

/**
 * zygons - suspend the function
 */
void zygons(void)
{
	int sig_num;

	scanf("%d", &sig_num);
	/* printf("\n");*/
	fflush(stdout);
}
