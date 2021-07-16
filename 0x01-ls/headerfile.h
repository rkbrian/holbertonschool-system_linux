#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

/**
 * prototypes for static libraries
 */

/* str_process */
int _putchar(char c);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
/* readdir_to_str */
char *mall_strcat(char *oldstr, char *newstr, char *separator);
char *sorted_array(char *av[]);
char **arr_of_str(char *arr[], char *newstr);
void free_array(char *arr[]);
/*  */


#endif