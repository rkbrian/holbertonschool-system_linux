#ifndef _GETLINE_H
#define _GETLINE_H

#define READ_SIZE 1024

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/**
 * prototypes for static libraries
 */

char *_getline(const int fd);
char *continue_read(char *buffer, int linemem, int laststop);

#endif