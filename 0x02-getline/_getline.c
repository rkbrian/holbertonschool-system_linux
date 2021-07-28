#include "_getline.h"

/**
 * _getline - reads an entire line from a file descriptor.
 * @fd: file descriptor
 * Return: fd lines.
 */
char *_getline(const int fd)
{
	static filetext *static_texts;
	filetext *current, *temp_node;

	if (fd == -1)
	{
		current = static_texts;
		if (current == NULL)
			return (NULL);
		while (current)
		{
			temp_node = current->next;
			if (current->buffer)
				free(current->buffer);
			free(current);
			current = temp_node;
		}
		return (NULL);
	}
	current = text_list(&static_texts, fd);
	if (current == NULL)
		return (NULL);
	return (continue_read(current));
}

/**
 * text_list - function to make a linked list of texts
 * @static_texts: static linked lists to store file lines of each fd
 * @fd: file descriptor
 * Return: linked list of texts
 */
filetext *text_list(filetext **static_texts, int fd)
{
	filetext *current, *newtext = NULL, *tmp = NULL;

	if (*static_texts == NULL)
	{
		newtext = new_node(fd), newtext->next = NULL;
		*static_texts = newtext;
		return (newtext);
	}
	current = *static_texts;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		else if (current->fd > fd)
		{
			newtext = new_node(fd), newtext->next = current;
			if (tmp)
				tmp->next = newtext;
			return (newtext);
		}
		tmp = current;
		current = current->next;
	}
	newtext = new_node(fd), newtext->next = NULL;
	tmp->next = newtext;
	return (newtext);
}

/**
 * new_node - make a new node with given parameter
 * @fd: file descriptor
 * Return: new node
 */
filetext *new_node(int fd)
{
	filetext *newtext;

	newtext = malloc(sizeof(filetext));
	if (newtext == NULL)
		return (NULL);
	newtext->buffer = NULL;
	newtext->fd = fd;
	newtext->linemem = 0;
	return (newtext);
}

/**
 * continue_read - read through everything in a line and return
 * @texts: current node pass down
 * Return: the text been read
 */
char *continue_read(filetext *texts)
{
	char *textline = NULL;
	int laststop = texts->linemem, i_diff = 0;

	if (texts->buffer == NULL) /* making buffer, once for all */
	{
		texts->linemem = 0, laststop = 0;
		texts->buffer = malloc(sizeof(char) * (READ_SIZE + 1));
		if (texts->buffer == NULL)
			return (NULL);
		memset(texts->buffer, 0, sizeof(char) * (READ_SIZE + 1)); /* initialize */
		if (read(texts->fd, texts->buffer, READ_SIZE) == -1)
			return (NULL);
	}
	for (; texts->buffer[texts->linemem] != '\n'
		     && texts->buffer[texts->linemem] != '\0' && texts->linemem < READ_SIZE;)
		texts->linemem++;
	if (texts->linemem == READ_SIZE)
		return (buffalo_string(texts, laststop));
	if (texts->buffer[texts->linemem] == '\n') /* if stopped at new line */
	{
		textline = malloc(sizeof(char) * (texts->linemem - laststop + 1));
		if (textline == NULL)
			return (NULL);
		for (; laststop < texts->linemem; laststop++, i_diff++)
			textline[i_diff] = texts->buffer[laststop];
		textline[i_diff] = '\0', texts->linemem++; /* mem count for null byte */
	}
	else if (texts->buffer[texts->linemem] == '\0') /* case stop in the middle */
	{
		if (texts->linemem > laststop)
		{
			textline = malloc(sizeof(char) * (texts->linemem - laststop + 1));
			if (textline == NULL)
				return (NULL);
			for (; laststop < texts->linemem; laststop++)
				textline[i_diff] = texts->buffer[laststop];
			textline[i_diff] = '\0';
		}
		free(texts->buffer), texts->buffer = NULL; /* end of file */
	}
	return (textline);
}

/**
 * buffalo_string - read texts and clear buffer when reaching buffer limit
 * @texts: current node pass down
 * @laststop: the starting point for the new text reading
 * Return: the text been read
 */
char *buffalo_string(filetext *texts, int laststop)
{
	char *buffalo = NULL, *tmp = NULL;
	int i, j;

	if (laststop == texts->linemem)
		buffalo = NULL;
	else
	{
		buffalo = malloc(sizeof(char) * (texts->linemem - laststop + 1));
		if (buffalo == NULL)
			return (NULL);
		for (i = 0; i < (texts->linemem - laststop); i++)
			buffalo[i] = texts->buffer[laststop + i];
		buffalo[i] = '\0';
	}
	free(texts->buffer), texts->buffer = NULL;
	tmp = continue_read(texts);
	if (tmp == NULL)
	{
		if (buffalo)
			free(buffalo);
		if (texts->buffer)
			free(texts->buffer);
		return (NULL);
	}
	for (j = 0; tmp[j] != '\0'; j++)
	{
	}
	if (buffalo)
	{
		buffalo = realloc(buffalo, i + j + 1);
		strcat(buffalo, tmp), free(tmp);
	}
	else
		buffalo = tmp;
	return (buffalo);
}
