#include "headerfile.h"

/**
 * mall_strcat - function to cat strings for path, to be freed elsewhere
 * @oldstr: 1st major string
 * @newstr: 2nd major string
 * @separtor: string separator in form of minor string, can be null
 * Return: new string
 */

char *mall_strcat(char *oldstr, char *newstr, char *separator)
{
	int sublen = 0;
	char *dest;

	sublen = _strlen(oldstr) + _strlen(separator) + _strlen(newstr);
	dest = malloc(sizeof(char) * sublen + 1);
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

/**
 * sorted_array - function to bubble sort readdir strings for the print
 * @oldstr: destination string
 * @newstr: source string
 * Return: ptr to new string or null
 */

char *sorted_array(char *av[])
{
	int i, j, n, templen;
	char *tempstr;

	for (n = 0; av[n] != NULL; n++)
	{
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j <= n - i; j++)
		{
			if (_strcmp(av[j], av[j + 1]) > 0)
			{
				templen = _strlen(av[j]) + _strlen(av[j + 1]);
				tempstr = malloc(sizeof(char) * templen + 1);
				if (tempstr == NULL)
				{
					return (NULL);
					free(dest);
				}
				_strcpy(tempstr, av[j]);
				_strcpy(av[j], av[j + 1]);
				_strcpy(av[j + 1], tempstr);
				free(tempstr);
			}
		}
	}
	return (av);
}

/**
 * calc_arraylen - function to calculate total length of given array
 * @arr: array of strings
 * Return: int
 */

int calc_arraylen(char *arr[])
{
	int i, j, k = 0;

	for (i = 0; arr[i] != NULL; i++)
	{
		for (j = 0; arr[i][j] != "\0"; j++)
		{
			k++;
		}
		k++;
	}
	k++;
	return (k);
}

/**
 * arr_of_str - add a string into given array, to be free in main
 * @arr: array of string
 * @newstr: new string
 * Return: new array of string
 */

char **arr_of_str(char *arr[], char *newstr)
{
	int newstrlen, itemcount;
	char *str_copied;

	/* k = calc_arraylen(arr); */
	newstrlen = _strlen(newstr);
	str_copied
}

