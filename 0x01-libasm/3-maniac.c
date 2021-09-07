/* Description: `asm_strchr("Holberton School", 0)` */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1 "Holberton School"
#define C 0

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	printf("real: %s\n", strchr(S1, C));
	printf("my value: %s\n", asm_strchr(S1, C));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
