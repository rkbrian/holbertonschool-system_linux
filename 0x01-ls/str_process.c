#include "headerfile.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcat - function to concatenate 2 strings
 * @dest: destination string
 * @src: source string
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0' ; i++)
	{
	}
	for (j = 0; src[j] != '\0' ; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';
	return (dest);
}

/**
 * _strlen - function to find string length
 * @s: string
 * Return: string length
 */

int _strlen(char *s)
{
	int n;

	for (n = 0; s[n] != '\0'; n++)
	{
	}
	return (n);
}

/**
 * _strcpy - pointer to copy a string
 * @dest: destination string
 * @src: source string
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	char *c = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (c);
}

/**
 * _strcmp - function to compare 2 strings
 * @s1: 1st string
 * @s2: 2nd string
 * Return: difference of 2 strings
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0 ; (s1[i] != '\0' && s2[i] != '\0') ; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}
