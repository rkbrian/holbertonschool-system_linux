#ifndef _GETLINE_H
#define _GETLINE_H

#define READ_SIZE 1024

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * struct textmem - struct with texts of a file, string contents
 * @textline: text of a line
 * @next: linked list pointer to the next node
 */
typedef struct text_mem
{
	char *textline;
	struct text_mem *next;
} filetext;

char *_getline(const int fd);
filetext *continue_read(char *buffer, int linemem, int laststop, char *readtext);

#endif
