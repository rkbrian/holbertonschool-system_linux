#ifndef LAPS_H
#define LAPS_H

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

void race_state(int *id, size_t size);

#endif