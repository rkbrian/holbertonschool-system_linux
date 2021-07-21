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
		{
			k++;
			l++;
		}
	}
	if (argc == 1 || (argc == 2 && argv[1][0] == '-'))
		printme(".", newlineflag, aflag, argv[0]);
	else
	{
		for (i = 1; i < argc; i++)
		{
			if (argv[i][0] != '-')
			{
				if (l > 1)
					printf("%s:\n", argv[i]);

				printme(argv[i], newlineflag, aflag, argv[0]);
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
 * @af: flag to list all or almost all
 * @avzero: argv[0] "./hls" pass down
 */

void printme(char *av, char newlineflag, char af, char *avzero)
{
	int i = 0;
	struct dirent *ds;
	DIR *dir;
	char *sepa = "  ", *newpath;
	char *errmsgp = "%s: cannot open directory %s: Permission denied\n";
	char *errmsgn = "%s: cannot access %s: No such file or directory\n";

	if (newlineflag != 'n')
		sepa = "\n";
	if (file_stat(av) == 'd')
	{
		ds = readdir(dir = opendir(newpath = dir_selector(av)));
		if (_strcmp(av, ".") != 0)
			free(newpath);
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
					printf("%s%s", sepa, ds->d_name);
			}
			ds = readdir(dir);
		}
		closedir(dir);
		printf("\n");
	}
	else if (file_stat(av) == 'f')
		printf("%s\n", av);
	else if (file_stat(av) == 'E')
		fprintf(stderr, errmsgn, avzero, av);
	else if (file_stat(av) == 'e')
		fprintf(stderr, errmsgp, avzero, av);
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
