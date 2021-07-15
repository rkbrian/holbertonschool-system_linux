#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

/**
 * prototypes for static libraries
 */

int _putchar(char c);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *dirtostr(char *dest, char *newstr, char *separator);


#endif