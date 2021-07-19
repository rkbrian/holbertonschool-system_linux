#include "headerfile.h"

/**
 * main - function to list the content of the current directory and more
 * @argc: argument count
 * @argv: argument array
 * Retrun: 0
 */

int main(int argc, char *argv[])
{
  int i, j, k = 0;
  char newlineflag = 'n', listallflag = 'n';

  for (i = 1; i < argc; i++)
  {
    if (argv[i][0] == '-')
    {
      for (j = 1; argv[i][j] != '\0'; j++)
      {
        if (argv[i][j] == '1' || argv[i][j] == 'l')
          newlineflag = argv[i][j];

        if (argv[i][j] == 'a' || argv[i][j] == 'A' )
          listallflag = argv[i][j];
      }
    }
    else
      k++;
  }
  if (argc == 1 || (argc == 2 && argv[1][0] == '-'))
    printme(NULL, newlineflag, listallflag);

  else
  {
    for (i = 1; i < argc; i++)
    {
      if (argv[i][0] != '-')
      {
	if (k > 1)
	  printf("%s:\n", argv[i]);

	printme(argv[i], newlineflag, listallflag);
	if (k > 1)
	  printf("\n");

	k--;
      }
    }
  }
  return (0);
}

/**
 * printme - function to list the content of the current directory and more
 * @av: argument string
 * @newlineflag: flag to print new line
 * @listallflag: flag to list all or almost all
 */

void printme(char *av, char newlineflag, char listallflag)
{
  int i;
  struct dirent *dstream;
  DIR *dir;
  char *dest = "", *separator, *newpath, noflag[] = "  ", yesflag[] = "\n";

  if (av != NULL)
  {
    newpath = mall_strcat(".", av, "/");
    dir = opendir(newpath);
    free(newpath);
  }
  else
    dir = opendir(".");

  if (newlineflag == 'n')
    separator = noflag;
  else
    separator = yesflag;

  dstream = readdir(dir);
  while (dstream != NULL)
  {
    if (listallflag == 'n' && (dstream->d_type == 4 || dstream->d_type == 8) && _strcmp(dstream->d_name, ".") != 0 && _strcmp(dstream->d_name, "..") != 0)
      dest = mall_strcat(dest, dstream->d_name, separator);
    else if (listallflag == 'A' && _strcmp(dstream->d_name, ".") != 0 && _strcmp(dstream->d_name, "..") != 0)
      dest = mall_strcat(dest, dstream->d_name, separator);
    else if (listallflag == 'a')
      dest = mall_strcat(dest, dstream->d_name, separator);

    dstream = readdir(dir);
  }
  for (i = _strlen(separator); dest[i] != '\0'; i++)
    printf("%c", dest[i]);
  printf("\n");
  free(dest);
  closedir(dir);
}
