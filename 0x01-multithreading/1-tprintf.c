#include "multithreading.h"

/**
 * tprintf - uses the printf family to print out a given formatted string
 * @format: input string
 * Return: 0 for success
 */
int tprintf(char const *format, ...)
{
	pthread_t tidy = pthread_self();

	if (format)
		printf("[%lu] %s\n", tidy, format);
	return (0);
}