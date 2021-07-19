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
  struct dirent *mydir_stream;
  DIR *dir;
  char *dest = "", *separator = "  ", *newpath;

  if (av != NULL)
  {
    newpath = mall_strcat(".", av, "/");
    dir = opendir(newpath);
    free(newpath);
  }
  else
    dir = opendir(".");

  if (newlineflag != 'n')
      separator = "\n";

  mydir_stream = readdir(dir);
  while (mydir_stream != NULL)
  {
    if (listallflag == 'n' && (mydir_stream->d_type == 4 || mydir_stream->d_type == 8) && _strcmp(mydir_stream->d_name, ".") != 0 && _strcmp(mydir_stream->d_name, "..") != 0)
    {
      /* arr_of_str(dest, mydir_stream->d_name); */
      dest = mall_strcat(dest, mydir_stream->d_name, separator);
    }
    else if (listallflag == 'A' && _strcmp(mydir_stream->d_name, ".") != 0 && _strcmp(mydir_stream->d_name, "..") != 0)
    {
      /* arr_of_str(dest, mydir_stream->d_name); */
      dest = mall_strcat(dest, mydir_stream->d_name, separator);
    }
    else if (listallflag == 'a')
    {
      /* arr_of_str(dest, mydir_stream->d_name); */
      dest = mall_strcat(dest, mydir_stream->d_name, separator);
    }
    mydir_stream = readdir(dir);
  }
  for (i = _strlen(separator); dest[i] != '\0'; i++)
    printf("%c", dest[i]);

  /* sorted_array(dest); */
  /** printf("%s", dest[0]);
  for (i = 1; dest[i] != NULL; i++)
  {
    if (newlineflag == "l"){printf("")}
    printf("%s%s", separator, dest[i]);
  } */
  printf("\n");
  free(dest);
  closedir(dir);
}
