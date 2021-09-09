#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	int i, j, k = 0, flag = 0;
	char s[] = "Hoalberton" ;
        char accept[] = "abcdefghijklmnopqrstuvwxyz" ;

	for (j = 0 ; s[j] != '\0'; j++)
	{
		for (i = 0 ; accept[i] != '\0' ; i++)
		{
			if (s[j] == accept[i])
			{
				k++;
				break;
			}
		}
		if (k == 0)
			break;
		else if (k > 0)
			flag++;
		if (flag > k)
			break;
	}

	printf("how many chars belong to accept? %d\n", k);
	return (0);
}
