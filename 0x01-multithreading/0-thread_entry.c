#include "multithreading.h"

/**
 * thread_entry - serve as the entry point to a new thread
 * @arg: address of a string that must be printed and followed by a new line
 * Return: exit the thread
 */
void *thread_entry(void *arg)
{
	if (arg)
		printf("%s\n", (char *)arg);
	pthread_exit(0);
}
