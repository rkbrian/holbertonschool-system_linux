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
	long ptval = -1;
	int status = 0, sysflag = 0;
	char *addr;
	struct user_regs_struct regs;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s command [args...]\n", argv[0]);
		return (1);
	}
	printf("execve = 0\n"), pid = fork();
	if (pid == 0)
	{
		ptrace(PTRACE_TRACEME, pid, 0, 0);
		execve(argv[1], argv + 1, envp);
	}
	else
	{
		status = 1;
		while (!WIFEXITED(status)) /*  returns true if child terminated normally */
		{
			sysflag++;
			ptval = ptrace(PTRACE_SYSCALL, pid, 0, 0);
			wait(&status);
			ptrace(PTRACE_GETREGS, pid, 0, &regs);
			if ((ptval == 0) && (sysflag % 2 == 0))
				printf("%s", syscalls_64_g[regs.orig_rax].name);
			else if ((ptval == 0) && (sysflag % 2 > 0) && !WIFEXITED(status))
				printf(" = %s%lx\n", addr = (regs.rax == 0 ? "" : "0x"), (size_t)regs.rax);
			fflush(stdout), ptval++;
		}
	}
	printf(" = ?\n");
	return (0);
}
