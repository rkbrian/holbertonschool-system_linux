#include "headerfile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

/**
 * main - function to list the content of the current directory and more
 * @argc: argument count
 * @argv: argument array
 * Retrun: 0
 */
int main(int argc, char *argv[])
{
  struct dirent *mydir_stream;
  DIR *dir = opendir(".");
  char *dest, *separator = "  ";
  int i, j;

  /* (void)argc; */
  if (argv[1][0] == "-")
  {
    /*separator change*/
  }
  for (i = 1; i < argc - 1; i++)
  {
    if (argv[i] == "-1")
    {
      /*separator change*/
    }
  }

  if (dir == NULL)
  {
    return (1);
  }
  mydir_stream = readdir(dir);
  dest = "";
  while (mydir_stream != NULL)
  {
    /* printf("%s  ", mydir_stream->d_name); */
    dirtostr(dest, mydir_stream->d_name, separator);
    /* malloc and free! */
    free(dest);
    mydir_stream = readdir(dir);
  }
  dirtostr(dest, "\n", "");
  free(dest);

  closedir(dir);
  return (0);
}
