#include "syscalls.h"

/**
 * main - executes and traces a given command to print the syscall numbers
 * @argc: argument count
 * @argv: argument array
 * @envp: environmental parameteres
 * Return: 0 if success, 1 if failed
 */
int main(int argc, char *argv[], char *envp[])
{
	pid_t pid;
	long ptval;
	int i, j, status = 0;
	struct user_regs_struct regs;

	pid = fork();
	if (pid == 0)
	{
		ptrace(PTRACE_TRACEME, 0, 0, 0);
		execve(argv[1], argv + 1, envp);
	}
	else
	{
		wait(&status);
		while (1)
		{
			ptval = ptrace(PTRACE_SYSCALL, pid, 0, 0);
			if (ptval)
				printf("%ld\n", ptval);
			sleep(1);
		}
		/*ptrace(PTRACE_CONT, pid, NULL, NULL);*/
	}
	return (0);
}
