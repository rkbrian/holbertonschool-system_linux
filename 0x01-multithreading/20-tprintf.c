#include "multithreading.h"

/**
 * tprintf - uses the printf family to print out a given formatted string
 * use a mutex to avoid race conditions
 * @format: input string
 * Return: 0 for success
 */
int tprintf(char const *format, ...)
{
	va_list arg;
	pthread_t tidy = pthread_self();

	va_start(arg, format);
	pthread_mutex_lock(&mymutex);
	printf("[%lu] ", (unsigned long)tidy);
	if (format)
		vprintf(format, arg);
	pthread_mutex_unlock(&mymutex);
	va_end(arg);
	return (0);
}

/**
 * init_mymutex - use pthread_mutex_init method as mutex constructor 
 */
void init_mymutex(void)
{
	pthread_mutex_init(&mymutex, NULL);
}

/**
 * end_mymutex - use pthread_mutex_destroy method as mutex destructor
 */
void end_mymutex(void)
{
	pthread_mutex_destroy(&mymutex);
}
