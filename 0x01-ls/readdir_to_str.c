#include "headerfile.h"

/**
 * dirtostr - function to cat readdir strings
 * @ac: argument string count
 * @av: double string pointer for argument
 * Return: ptr to new string or null
 */

char *dirtostr(char *oldstr, char *newstr, char *separator)
{
	int sublen = 0;
	char *dest;

	if (newstr == NULL)
	{
		return (NULL);
	}
	sublen = _strlen(oldstr) + _strlen(separator) + _strlen(newstr);
	s = malloc(sizeof(char) * sublen + 1);
	if (dest == NULL)
	{
		return (NULL);
		free(dest);
	}
	_strcat(dest, oldstr);
	_strcat(dest, separator);
	_strcat(dest, newstr);
	return (dest);
}

char *pathfinder(char *path)
{
	if (something != "." and something != "..")
	{
		dirtostr();
	}
}

