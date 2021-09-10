#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	int i;
	char *src = strdup("Holberton");
	char *dest = strdup("......... School");

	for (i = 0; i <= 9; i++)
	{
		printf("%p before memcpy\n", dest);
		asm_memcpy(dest, src, i);
		printf("%p\n", dest);
	}
	assert(asm_memcpy(dest, src, 9) == dest);
	free(dest);
	free(src);
	printf("All good!\n");
	return (EXIT_SUCCESS);
}
