#include "syscalls.h"
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
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
	char **buffalo;
	char *envp[]={"PATH=/bin", NULL};

	buffalo = malloc(sizeof(char *) * argc);

	for (i = 1; i < argc; i++)
	{
		buffalo[i - 1] = malloc(sizeof(char) * strlen(argv[i]));
		for (j = 0; j < (strlen(argv[i]) && 64); j++)
			buffalo[i - 1][j] = argv[i][j];
		buffalo[i - 1][j] = '\0';
	}
	buffalo[i - 1] = NULL;

	pid = fork();
	if (pid == 0)
	{
		ptrace(PTRACE_TRACEME, 0, NULL, NULL);
		execve(argv[1], (char * const *)buffalo, envp);
	}
	else
	{
		wait(NULL);
		orig_eax = ptrace(PTRACE_PEEKUSER, pid, ORIG_EAX * 4, NULL);
		printf("%ld\n", orig_eax);
		ptrace(PTRACE_CONT, pid, NULL, NULL);
	}
	for (i = 0; buffalo[i] != NULL; i++)
		free(buffalo[i]);
	free(buffalo);
	return (0);
}
