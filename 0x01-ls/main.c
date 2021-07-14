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

  (void)argc;
  (void)argv;
  if (dir == NULL)
  {
    return (1);
  }

  mydir_stream = readdir(dir);
  while (mydir_stream != NULL)
  {
    printf("%s-", mydir_stream->d_name);
    mydir_stream = readdir(dir);
  }

  closedir(dir);
  return (0);
}
