#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

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
char file_stat(char *av);
/* main */
void printme(char *av, char newlineflag, char listallflag, char *avzero);
char *dir_selector(char *dirstr);
void xtraprint(char *av);
void mul_arg(char *a0, char *a1);
/* long_listing */
/* void long_listing(char *av, char *path); */
/* void show_permission(int permnum); */

#endif
