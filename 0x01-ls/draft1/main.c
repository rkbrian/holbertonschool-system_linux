#include "headerfile.h"

/**
 * main - function to list the content of the current directory and more
 * @argc: argument count
 * @argv: argument array
 * Return: 0
 */

int main(int argc, char *argv[])
{
<<<<<<< HEAD
	int i, j, k = 0, l = 0;
	char newlineflag = 'n', aflag = 'n', *temp0, *temp1;

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
			l++, k++;
	}
	if (l == 0)
		printme(".", newlineflag, aflag, argv[0]);
	else
	{
		for (i = 1; i < argc; i++)
		{
			if (argv[i][0] != '-')
			{
				temp0 = argv[i + 1];
				temp1 = argv[i];
				if (l > 1 && file_stat(temp1) == 'd')
					printf("%s:\n", temp1);
				printme(temp1, newlineflag, aflag, argv[0]);
				if (k > 1)
					mul_arg(temp1, temp0);
			}
			k--;
		}
	}
	return (0);
=======
    int i, j, k = 0, l = 0;
    char newlineflag = 'n', aflag = 'n', *temp0, *temp1;

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
            l++, k++;
    }
    if (l == 0)
        printme(".", newlineflag, aflag, argv[0]);
    else
    {
        for (i = 1; i < argc; i++)
        {
            if (argv[i][0] != '-')
            {
                temp0 = argv[i + 1];
                temp1 = argv[i];
                if (l > 1 && file_stat(temp1) == 'd')
                    printf("%s:\n", temp1);
                printme(temp1, newlineflag, aflag, argv[0]);
                if (k > 1)
                    mul_arg(temp1, temp0);
            }
            k--;
        }
    }
    return (0);
>>>>>>> 056eed321c16250475f861adae99fce385de1e8d
}

/**
 * printme - function to list the content of the current directory and more
 * @av: argument string, can be null
 * @newlineflag: flag to print new line
 * @af: flag to list all or almost all
 * @avzero: argv[0] execution command pass down
 */

void printme(char *av, char newlineflag, char af, char *avzero)
{
<<<<<<< HEAD
	int i = 0;
	struct dirent *ds;
	DIR *dir;
	char *s = "  ", *dename;
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
			dename = ds->d_name;
			if ((af == 'a') || (af == 'n' && dename[0] != '.'
			     && (ds->d_type == 4 || ds->d_type == 8))
			    || (af == 'A' && _strcmp(dename, ".") != 0
				&& _strcmp(dename, "..") != 0))
			{
				if (i == 0)
				{
					if (newlineflag == 'l')
						long_listing(dename, av);
					printf("%s", dename);
					i++;
				}
				else
				{
					printf("%s", s);
					if (newlineflag == 'l')
						long_listing(dename, av);
					printf("%s", dename);
				}
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
=======
    int i = 0;
    struct dirent *ds;
    DIR *dir;
    char *s = "  ", *dename;
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
            dename = ds->d_name;
            if ((af == 'a') || (af == 'n' && dename[0] != '.' && (ds->d_type == 4 || ds->d_type == 8)) || (af == 'A' && _strcmp(dename, ".") != 0 && _strcmp(dename, "..") != 0))
            {
                if (i == 0)
                {
                    if (newlineflag == 'l')
                        long_listing(dename, av);
                    printf("%s", dename);
                    i++;
                }
                else
                {
                    printf("%s", s);
                    if (newlineflag == 'l')
                        long_listing(dename, av);
                    printf("%s", dename);
                }
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
>>>>>>> 056eed321c16250475f861adae99fce385de1e8d
}

/**
 * dir_selector - select directory path for opendir
 * @dirstr: dirctory string
 * Return: path string
 */

char *dir_selector(char *dirstr)
{
<<<<<<< HEAD
	char *newpath = NULL;

	if (_strcmp(dirstr, ".") == 0)
		return (dirstr);
	newpath = mall_strcat(".", dirstr, "/");
	return (newpath);
=======
    char *newpath = NULL;

    if (_strcmp(dirstr, ".") == 0)
        return (dirstr);
    newpath = mall_strcat(".", dirstr, "/");
    return (newpath);
>>>>>>> 056eed321c16250475f861adae99fce385de1e8d
}

/**
 * xtraprint - print file name
 * @av: file name
 */

void xtraprint(char *av)
{
<<<<<<< HEAD
	if (file_stat(av) == 'f')
		printf("%s\n", av);
=======
    if (file_stat(av) == 'f')
        printf("%s\n", av);
>>>>>>> 056eed321c16250475f861adae99fce385de1e8d
}

/**
 * mul_arg - print spacing between args
 * @a0: 1st arg
 * @a1: 2nd arg
 */

void mul_arg(char *a0, char *a1)
{
<<<<<<< HEAD
<<<<<<< HEAD
	if (file_stat(a0) == 'd' || file_stat(a1) == 'd')
		printf("\n");
=======
        if (file_stat(a0) == 'd' || file_stat(a1) == 'd')
                printf("\n");
>>>>>>> 056eed321c16250475f861adae99fce385de1e8d
=======
    if (file_stat(a0) == 'd' || file_stat(a1) == 'd')
        printf("\n");
>>>>>>> 6ba4178e5d491d279bc79eb0a01d6963420b5633
}
