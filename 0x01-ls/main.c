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
  int i, j, k, l;
  char flaglist[] = "aA1l"

  for (i = 1; i < argc - 1; i++)
  {
    if (argv[i][0] == "-")
    {
      for (j = 1; argv[i][j] != "\0"; j++)
      {
        if (argv[i][j] = "l")
      }
    }
  }

for (i = 1; i < argc - 1; i++)
  {
    if (argv[i][0] != "-")
    {
      for (j = 1; argv[i][j] != "\0"; j++)
      {
        if (argv[i][j] = "l")
      }
    }
  }



  if (argc == 1)
  {
    ;
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
  char dest[] = {""};
  char separator[] = "  ";
  char linkname[] = ".";
  char *newpath;
  char block_list[] = {".", ".."};

  dir = opendir(linkname);
  if (dir == NULL)
  {
    return (1);
  }

  mydir_stream = readdir(dir);
  while (mydir_stream != NULL)
  {
    /* printf("%s  ", mydir_stream->d_name); */
    arr_of_str(dest, mydir_stream->d_name);
    mydir_stream = readdir(dir);
  }

  printf("%s/n", dest);
  free(dest);
  free_array()

  closedir(dir);
}