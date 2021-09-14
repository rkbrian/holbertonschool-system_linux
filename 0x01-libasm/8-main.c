#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton School"
#define S2  "HOLBERTON SCHOOL"
#define S3  "Holberton SchooL"
#define S4  "holberton ="

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(strcasecmp(S1, S1) == asm_strcasecmp(S1, S1));
	assert(strcasecmp(S1, S2) == asm_strcasecmp(S1, S2));
	assert(strcasecmp(S1, S3) == asm_strcasecmp(S1, S3));
	printf("S - null byte = %d\n", strcasecmp(S1, S4));
	printf("my S - null byte = %d\n", asm_strcasecmp(S1, S4));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
