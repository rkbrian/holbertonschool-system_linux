#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * struct signal_dictionary - struct of temprary signal dictionary
 * @n: signum
 * @sig_name: signal description
 */
typedef struct signal_dictionary
{
	int n;
	char *sig_name;
} sidi;

void singer(int sig_num);
int handle_signal(void);
void print_hello(int);
void set_print_hello(void);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);
void sigma(int);
void cigarette(int sigourney);
void zygons(void);
int pid_exist(pid_t pid);

#endif /* SIGNALS_H */
