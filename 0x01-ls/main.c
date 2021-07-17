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
  char newlineflag = "n", listallflag = "n";

  for (i = 1; i < argc - 1; i++)
  {
    if (argv[i][0] = "-")
    {
      for (j = 1; argv[i][j] != "\0"; j++)
      {
        if (argv[i][j] = "1" || argv[i][j] = "l")
          newlineflag = argv[i][j];

        if (argv[i][j] = "a" || argv[i][j] =  "A" )
          listallflag = argv[i][j];
      }
    }
    else
      k++;
  }
  for (i = 1; i < argc - 1; i++)
  {
    if (argc == 1)
      printme(NULL, newlineflag, listallflag);

    else if (argv[i][0] != "-")
    {
      if (k > 0)
      {
        printf("%s:\n", argv[i]);
        k--;
      }
      printme(argv[i], newlineflag, listallflag);
      if (k > 0)
        printf("\n");
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
  char dest[] = {""}, separator[] = "  ";

  if (av != NULL)
    dir = opendir(mall_strcat(".", av, "/"));

  else
    dir = opendir(".");

  if (dir == NULL)
    return (1);

  if (newlineflag != "n")
      separator = "\n";

  mydir_stream = readdir(dir);
  while (mydir_stream != NULL)
  {
    if (listallflag == "n" && (mydir_stream->d_type == 4 || mydir_stream->d_type == 8))
      arr_of_str(dest, mydir_stream->d_name);

    else if (listallflag == "A" && mydir_stream->d_name != "." && mydir_stream->d_name != ".." )
      arr_of_str(dest, mydir_stream->d_name);

    else if (listallflag == "a")
      arr_of_str(dest, mydir_stream->d_name);

    mydir_stream = readdir(dir);
  }
  sorted_array(dest);
  printf("%s", dest[0]);
  for (i = 1; dest[i] != NULL; i++)
  {
    /* if (newlineflag == "l"){printf("")} */
    printf("%s%s", separator, dest[i]);
  }
  printf("\n");
  free(newpath);
  free_array(dest);
  closedir(dir);
}