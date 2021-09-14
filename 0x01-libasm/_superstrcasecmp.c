#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "mylibasm.h"

#define S1  "Holberton School"
#define S2  "HOLBERTON SCHOOL"
#define S3  "Holberton SBhool"
#define S4  "holberton"
#define S5  "holberton ="

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	printf("first the real strcasecm, then mine\n");
	printf("case different only: %d\n", strcasecmp(S1, S2));
	printf("case different only: %d\n", my_strcasecmp(S1, S2));
	printf("both case and char different: %d\n", strcasecmp(S1, S3));
	printf("both case and char different: %d\n", my_strcasecmp(S1, S3));
	printf("s and null: %d\n", strcasecmp(S1, ""));
	printf("s and null: %d\n", my_strcasecmp(S1, ""));
	printf("null and s: %d\n", strcasecmp("", S1));
	printf("null and s: %d\n", my_strcasecmp("", S1));
	printf("s and short s: %d\n", strcasecmp(S1, S4));
	printf("s and short s: %d\n", my_strcasecmp(S1, S4));
	printf("upper case and not letter char: %d\n", strcasecmp(S1, S5));
	printf("upper case and not letter char: %d\n", my_strcasecmp(S1, S5));
	return (0);
}

int my_strcasecmp(const char *s1, const char *s2)
{
	int low1 = 0, low2 = 0, flag = 0;

	if (*s1 == '\0')
	{
		if (*s2 > 64 && *s2 < 91)
			low2 = low2 + 32; /* tolower(s2) only */
		return (0 - *s2 -low2);
	}
	while (*s1)
	{
		if ((*s1 - *s2 == 32) && (*s1 > 96 && *s1 < 123))
			s1++, s2++;
		/* s2 lower, s1 upper */
		else if ((*s2 - *s1 == 32) && (*s2 > 96 && *s2 < 123))
			s1++, s2++;
		else if (*s1 != *s2)
		{
			flag = 1;
			break;
		}
		/* s1 = s2 no matter the case */
		else
			s1++, s2++;
	}
	if (flag == 0)
		return (0);
	if (*s1 > 64 && *s1 < 91)
		low1 = low1 + 32; /* tolower(s1) */
	if (*s2 > 64 && *s2 < 91)
		low2 = low2 + 32; /* tolower(s2) */
	return (*s1 + low1 - *s2 -low2);
}
