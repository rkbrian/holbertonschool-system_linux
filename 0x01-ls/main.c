#include "headerfile.h"

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
  char *dest = "";

  (void)argc;
  if (dir == NULL)
  {
    return (1);
  }

  mydir_stream = readdir(dir);
  while (mydir_stream != NULL)
  {
    /*printf("%s  ", mydir_stream->d_name);*/
    _strcat();

    /*malloc and free!!!!!!!!!!!!!*/

    mydir_stream = readdir(dir);
  }
  printf("\n");

  closedir(dir);
  return (0);
}
