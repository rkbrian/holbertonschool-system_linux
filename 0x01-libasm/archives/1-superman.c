#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton School"
#define S2  ""
#define S3  "Holberton Schooz"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	printf("right: %d\n", strcmp(S1, S1));
	printf("me: %d\n", asm_strcmp(S1, S1));
	printf("right: %d\n", strcmp(S1, S2));
	printf("me: %d\n", asm_strcmp(S1, S2));
	printf("right: %d\n", strcmp(S1, S3));
	printf("me: %d\n", asm_strcmp(S1, S3));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
