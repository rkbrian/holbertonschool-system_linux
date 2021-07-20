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

/**
 * file_stat - determine the file or directory stats and print
 * @av: directory or file name
 * Return: case selection code
 */

char file_stat(char *av)
{
	char casecode = 'u';
	struct stat my_stats;
	char *errmsgp = "./hls: cannot open directory %s: Permission denied\n";
	char *errmsgn = "./hls: cannot access %s: No such file or directory\n";

	if (lstat(av, &my_stats) == -1)
	{
		fprintf(stderr, errmsgn, av);
		casecode = 'e';
	}
	else if (S_ISDIR(my_stats.st_mode))
	{
		if (my_stats.st_mode & S_IROTH)
			casecode = 'd';
		else
		{
			fprintf(stderr, errmsgp, av);
			casecode = 'e';
		}
	}
	else if (S_ISREG(my_stats.st_mode))
		casecode = 'f';
	return (casecode);
}
