#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 */
int main(void)
{
  char *arr[50] = {"hoho", "hey"};
  char newstr[] = "hello";
  int i, newstrlen, itemcount;
  char *str_copied, **ptr = arr;

  newstrlen = strlen(newstr);
  for (itemcount = 0; arr[itemcount] != NULL; itemcount++)
  {
  }
  printf("%d\n", itemcount);
  str_copied = malloc(sizeof(char) * newstrlen + 1);
  strcpy(str_copied, newstr);
  ptr[itemcount] = str_copied;
  for (i = 0; ptr[i] != NULL; i++)
  {
    printf("%s\n", ptr[i]);
  }
  free(str_copied);
  return (0);
}
