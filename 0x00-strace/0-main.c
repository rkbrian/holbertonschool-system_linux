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
	int status = 0; /*, sysflag = 0;*/
	struct user_regs_struct regs;

	if (argc < 2)
	{
		fprintf(stderr, "Useage: %s command [args...]\n", argv[0]);
		return (1);
	}
	setbuf(stdout, NULL);
	pid = fork();
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
			/* sysflag++;*/
			ptrace(PTRACE_SYSCALL, pid, 0, 0);
			wait(&status);
			ptval = ptrace(PTRACE_GETREGS, pid, 0, &regs);
			if (ptval != -1)
				printf("%lu\n", (size_t)regs.orig_rax); /*printf("sysflag: %d\n", sysflag);*/
			/*sleep(1);*/
		}
	}
	return (0);
}
