#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void singer(int sig_num);
int handle_signal(void);
void print_hello(int);
void set_print_hello(void);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);

#endif /* SIGNALS_H */
