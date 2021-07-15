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
  char *dest, *separator = "  ";
  char linkname[] = ".";
  char *newpath;
  int i, j;

  /* (void)argc; */
  block_list(argv);
  for (i = 0; i < argv[1])
  for (i = 1; i < argc - 1; i++)
  {
    if (argv[i] == "-1")
    {
      /*separator change*/
    }
  }
  
  if (argc == 1)
  {
    dir = opendir(linkname);
  }
  else if (argv[1])
  {
    dir = opendir(pathfinder(linkname, ));
  }
  else

  for ()
  {

  }
  

  return (0);
}

/**
 * printme - function to list the content of the current directory and more
 * @ac: argument count
 * @av: argument string
 */

void printme(int ac, char *av[])
{
  int i;
  struct dirent *mydir_stream;
  DIR *dir;

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
    mydir_stream = readdir(dir);
  }
  printf("%s/n", dest);
  free(dest);

  closedir(dir);
}