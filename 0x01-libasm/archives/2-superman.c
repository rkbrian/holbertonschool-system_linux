#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define S1  "Holberton School"
#define S2  ""
#define S3  "Holberton Socool"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	printf("real: %d\n", strncmp(S1, S3, 1));
	printf("real: %d\n",strncmp(S1, S3, 11));
	printf("real: %d\n", strncmp(S1, S3, 15));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
