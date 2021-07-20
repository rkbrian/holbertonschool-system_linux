#include "headerfile.h"

/**
 * main - function to list the content of the current directory and more
 * @argc: argument count
 * @argv: argument array
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i, j, k = 0, l = 0;
	char newlineflag = 'n', listallflag = 'n';

	for (i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			for (j = 1; argv[i][j] != '\0'; j++)
			{
				if (argv[i][j] == '1' || argv[i][j] == 'l')
					newlineflag = argv[i][j];
				if (argv[i][j] == 'a' || argv[i][j] == 'A')
					listallflag = argv[i][j];
			}
		}
		else
		{
			k++;
			l++;
		}
	}
	if (argc == 1 || (argc == 2 && argv[1][0] == '-'))
		printme(NULL, newlineflag, listallflag);
	else
	{
		for (i = 1; i < argc; i++)
		{
			if (argv[i][0] != '-')
			{
				if (l > 1)
					printf("%s:\n", argv[i]);

				printme(argv[i], newlineflag, listallflag);
				if (k > 1)
					printf("\n");
			}
			k--;
		}
	}
	return (0);
}

/**
 * printme - function to list the content of the current directory and more
 * @av: argument string
 * @newlineflag: flag to print new line
 * @aflag: flag to list all or almost all
 */

void printme(char *av, char newlineflag, char aflag)
{
	int i = 0;
	struct dirent *dstr;
	DIR *dir;
	char *sepa = "  ", *newpath;

	if (newlineflag != 'n')
		sepa = "\n";
	if (file_stat(av) == 'd')
	{
		dir = opendir(newpath = dir_selector(av));
		free(newpath);
		dstr = readdir(dir);
		while (dstr != NULL)
		{
			if ((aflag == 'n' && (dstr->d_type == 4
					      || dstr->d_type == 8)
			     && _strcmp(dstr->d_name, ".") != 0
			     && _strcmp(dstr->d_name, "..") != 0)
			    || (aflag == 'A' && _strcmp(dstr->d_name, ".") != 0
				&& _strcmp(dstr->d_name, "..") != 0)
			    || (aflag == 'a'))
			{
				if (i == 0)
				{
					printf("%s", dstr->d_name);
					i++;
				}
				else
					printf("%s%s", sepa, dstr->d_name);
			}
			dstr = readdir(dir);
		}
		closedir(dir);
		printf("\n");
	}
	else if (file_stat(av) == 'd')
		printf("%s\n", av);
}

/**
 * dir_selector - select directory path for opendir
 * @dirstr: dirctory string
 * Return: path string
 */

char *dir_selector(char *dirstr)
{
	char *newpath = NULL;

	if (dirstr != NULL)
		newpath = mall_strcat(".", dirstr, "/");
	else
		newpath = mall_strcat(".", dirstr, "");
	return (newpath);
}
