#include <strings.h>
#include <stdio.h>
int main(void)
{
	char a[] = "Me, myself and I will never be alone";
	char b[] = "nah";

	printf("Doctor, you are not alone: %d\n", strcasecmp(a, b));
	printf("I am the Master: %d\n", strcasecmp(b, a));
	printf("The Master reborn: I'm the primeminister! %d\n", *a - *b);
	return (0);
}
