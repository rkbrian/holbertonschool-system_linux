#include "headerfile.h"

/**
 * mall_strcat - function to cat strings for path, to be freed elsewhere
 * @oldstr: 1st major string
 * @newstr: 2nd major string
 * @separator: string separator in form of minor string, can be null
 * Return: new string
 */

char *mall_strcat(char *oldstr, char *newstr, char *separator)
{
	int sublen = 0;
	char *dest;

	if (oldstr == NULL)
		oldstr = "";

	sublen = _strlen(oldstr) + _strlen(separator) + _strlen(newstr);
	dest = malloc(sizeof(char) * sublen + 1);
	if (dest == NULL)
		return (NULL);

	dest[0] = '\0';
	_strcat(dest, oldstr);
	_strcat(dest, separator);
	_strcat(dest, newstr);
	return (dest);
}
