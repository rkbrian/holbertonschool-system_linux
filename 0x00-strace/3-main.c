#include "syscalls.h"

/**
 * sysprint - print syscall parameters
 * @sysrax: syscall struct, in term of regs
 * @regs: user registers
 */
void sysprint(const syscall_t *sysrax, struct user_regs_struct *regs)
{
	size_t params[MAX_PARAMS]; /* int/ptr parameters of the regi in order */
	size_t i;
	char *sepa, *addrh;

	params[0] = regs->rdi;
	params[1] = regs->rsi;
	params[2] = regs->rdx;
	params[3] = regs->r10; /* why not rcx??? */
	params[4] = regs->r8;
	params[5] = regs->r9;
	printf("(");
	/* for save guarding syscalls_64_g in main, I use sysrax, not regs */
	if (sysrax->params[0] != VOID)
	{
		for (i = 0; i < sysrax->nb_params; i++)
		{
			printf("%s", sepa = (i ? ", " : ""));
			if (sysrax->params[i] == VARARGS)
				printf("...");
			else
				printf("%s%lx", addrh = (params[i] ? "0x" : ""), params[i]);
		}
		fflush(stdout);
	}
}

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
	printf("execve(0, 0, 0) = 0\n"), pid = fork();
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
			{
				printf("%s", syscalls_64_g[regs.orig_rax].name);
				sysprint(&syscalls_64_g[regs.orig_rax], &regs);
			}
			else if ((ptval == 0) && (sysflag % 2 > 0) && !WIFEXITED(status))
				printf(") = %s%lx\n", addr = (regs.rax ? "0x" : ""), (size_t)regs.rax);
			fflush(stdout), ptval++;
		}
	}
	printf(") = ?\n");
	return (0);
}
