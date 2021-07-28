#ifndef _GETLINE_H
#define _GETLINE_H

#define READ_SIZE 1024

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * struct text_mem - struct with texts of a file, string contents
 * @buffer: buffer
 * @fd: file description
 * @linemem: the current end of text to be read
 * @next: linked list pointer to the next node
 */
typedef struct text_mem
{
	char *buffer;
	int fd;
	int linemem;
	struct text_mem *next;
} filetext;

char *_getline(const int fd);
filetext *text_list(filetext **static_texts, int fd);
filetext *new_node(int fd);
char *continue_read(filetext *texts);
char *buffalo_string(filetext *texts, int laststop);

#endif
