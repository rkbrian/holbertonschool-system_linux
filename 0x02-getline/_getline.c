#include "_getline.h"

/**
 * _getline - reads an entire line from a file descriptor.
 * @fd: file descriptor
 * Return: fd lines.
 */
char *_getline(const int fd)
{
	static char *buffer;
	char *readtext;
	static int linemem;
	int laststop;

	if (buffer == NULL) /* making buffer, this action is once for all */
	{
		buffer = malloc(sizeof(char) * READ_SIZE);
		if (buffer == NULL)
			return (NULL);
		memset(buffer, 0, sizeof(char) * READ_SIZE); /* initializing buffer */
		if (read(fd, buffer, READ_SIZE) == -1)
			return (NULL);
	}

	laststop = linemem;
	for (; buffer[linemem] != '\n' && buffer[linemem] != '\0'; linemem++)
	{
	}
	if (buffer[linemem] == '\n') /* if stopped at new line, normal case */
	{
		continue_read(buffer, linemem, laststop, readtext);
		laststop = linemem;
		linemem++; /* memory count skip a space for null byte */
	}
	else if (buffer[linemem] == '\0') /* if stopped at the middle of the line */
	{
		if (linemem > laststop)
		{
			continue_read(buffer, linemem, laststop, readtext);
			laststop = linemem;
		}
		free(buffer);
		buffer = NULL;
	}
	return (readtext);
}

/**
 * continue_read - read through everything in a line and return
 * @buffer: buffer pass down
 * @linemem: the current end of text to be read
 * @laststop: the current start of text been read, also the total size read
 * @readtext: return string pointer
 * Return: the text been read
 */
char *continue_read(char *buffer, int linemem, int laststop, char *readtext)
{
	int i_diff = 0;

	readtext = malloc(sizeof(char) * (linemem - laststop + 1));
	if (readtext == NULL)
		return (NULL);
	for (; laststop < linemem; laststop++)
		readtext[i_diff] = buffer[laststop];
	readtext[i_diff] = '\0';
	return (readtext);
}
