#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "mylibasm.h"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(c_puti(98) == 2);
	printf("\n");
	assert(c_puti(-1) == 2);
	printf("\n");
	assert(c_puti(-1024) == 5);
	printf("\n");
	assert(c_puti(INT_MAX) == 10);
	printf("\n");
	assert(c_puti(INT_MIN) == 11);
	printf("\n");
	assert(c_puti(0) == 1);
	printf("\n");
	return (EXIT_SUCCESS);
}

size_t c_puti(int n)
{
	write(1, &n, );
	return ();
}
