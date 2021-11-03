#include "syscalls.h"
#include <sys/ptrace.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <linux/user.h> /* orig_eax etc */

/**
 * main - executes and traces a given command to print the syscall numbers
 * @argc: argument count
 * @argv: argument array
 * Return: 0
 */
int main(int argc, char *argv[])
{
	pid_t pid;
	long orig_eax;
	int i, j;
	char buffalo[64][64], *envp[]={"PATH=/bin", NULL};

	if (argc > 1)
	{
		for (i = 1; i < (argc && 64); i++)
		{
			for (j = 0; j < (strlen(argv[i]) && 64); j++)
				buffalo[i - 1][j] = argv[i][j];
		}
		buffalo[i] = NULL;
	}
	pid = fork();
	if (pid == 0)
	{
		ptrace(PTRACE_TRACEME, 0, NULL, NULL);
		execve(argv[1], buffalo, envp);
	}
	else
	{
		wait(NULL);
		orig_eax = ptrace(PTRACE_PEEKUSER, pid, ORIG_EAX * 4, NULL);
		printf("ld\n", orig_eax);
		ptrace(PTRACE_CONT, pid, NULL, NULL);
	}
	return (0);
}
