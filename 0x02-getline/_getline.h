#ifndef _GETLINE_H
#define _GETLINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * prototypes for static libraries
 */

char *_getline(const int fd);

#endif