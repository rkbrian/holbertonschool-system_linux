#include "multithreading.h"

/**
 * thread_entry - serve as the entry point to a new thread 
 * @arg: address of a string that must be printed and followed by a new line
 */
void *thread_entry(void *arg)
{
	if (arg)
		printf("%p\n", arg);
	pthread_exit();
}