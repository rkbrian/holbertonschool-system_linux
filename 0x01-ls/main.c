#include "headerfile.h"

/**
 * main - function to list the content of the current directory and more
 * @argc: argument count
 * @argv: argument array
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i, j, l = 0;
	char newlineflag = 'n', aflag = 'n';

	for (i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			for (j = 1; argv[i][j] != '\0'; j++)
			{
				if (argv[i][j] == '1' || argv[i][j] == 'l')
					newlineflag = argv[i][j];
				if (argv[i][j] == 'a' || argv[i][j] == 'A')
					aflag = argv[i][j];
			}
		}
		else
			l++;
	}
	if (l == 0)
		printme(".", newlineflag, aflag, argv[0]);
	else
	{
		for (i = 1; i < argc; i++)
		{
			if (argv[i][0] != '-')
			{
				if (file_stat(argv[i - 1]) == 'd'
				    || file_stat(argv[i]) == 'd')
					printf("\n");
				if (l > 1 && file_stat(argv[i]) == 'd')
					printf("%s:\n", argv[i]);
				printme(argv[i], newlineflag, aflag, argv[0]);
			}
		}
	}
	return (0);
}

/**
 * printme - function to list the content of the current directory and more
 * @av: argument string
 * @newlineflag: flag to print new line
 * @af: flag to list all or almost all
 * @avzero: argv[0] "./hls" pass down
 */

void printme(char *av, char newlineflag, char af, char *avzero)
{
	int i = 0;
	struct dirent *ds;
	DIR *dir;
	char *s = "  ";
	char *p = "%s: cannot open directory %s: Permission denied\n";
	char *en = "%s: cannot access %s: No such file or directory\n", *newpa;

	if (newlineflag != 'n')
		s = "\n";
	if (file_stat(av) == 'd')
	{
		ds = readdir(dir = opendir(newpa = dir_selector(av)));
		if (_strcmp(av, ".") != 0)
			free(newpa);
		while (ds != NULL)
		{
			if ((af == 'a') || (af == 'n' && ds->d_name[0] != '.'
			     && (ds->d_type == 4 || ds->d_type == 8))
			    || (af == 'A' && _strcmp(ds->d_name, ".") != 0
				&& _strcmp(ds->d_name, "..") != 0))
			{
				if (i == 0)
				{
					printf("%s", ds->d_name);
					i++;
				}
				else
					printf("%s%s", s, ds->d_name);
			}
			ds = readdir(dir);
		}
		closedir(dir);
		if (i != 0)
			printf("\n");
	}
	else if (file_stat(av) == 'E')
		fprintf(stderr, en, avzero, av);
	else if (file_stat(av) == 'e')
		fprintf(stderr, p, avzero, av);
	xtraprint(av);
}

/**
 * dir_selector - select directory path for opendir
 * @dirstr: dirctory string
 * Return: path string
 */

char *dir_selector(char *dirstr)
{
	char *newpath = NULL;

	if (_strcmp(dirstr, ".") == 0)
		return (dirstr);
	newpath = mall_strcat(".", dirstr, "/");
	return (newpath);
}

/**
 * xtraprint - print file name
 * @av: file name
 */

void xtraprint(char *av)
{
	if (file_stat(av) == 'f')
		printf("%s\n", av);
}
