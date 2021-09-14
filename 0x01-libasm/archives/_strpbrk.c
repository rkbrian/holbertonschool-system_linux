#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	char *i;
	char str[] = "hahaha";
	char accept[] = "";

	i = strpbrk(str, accept);
	printf("who did I found first? %s\n", i);
	return (0);
}
