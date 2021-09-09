#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	int i               ;
	char str[] = "Hoalberton" ;
	char accept[] = "abcdefghijklmnopqrstuvwxyz" ;

	i = strspn(str, accept) ;
	printf("how many chars belong to accept? %d\n", i);
	return (0);
}
