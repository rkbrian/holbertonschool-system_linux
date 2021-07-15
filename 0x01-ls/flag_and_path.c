#include "headerfile.h"

/**
 * block_list - return array of setup condition to control the readdir output 
 * @av: argument string from main function
 * Return: array
 */

char *block_list(char *av[])
{
    int i;
    char blockarr[20] = {".", ".."};

    /* block list change */
    if (av[1][0] == "-")
    {
        for (i = 1; av[1][i] != "\0"; i++)
        {
            if (av[1][i] == "a")
            {
                return (NULL);
            }
            if (av[1][i] == "A")
            {
                return (block_list);
            }
        }
    }
    /* separator change */
    if (av[])
}

/**
 * pathfinder - return string for opendir 
 * @av: argument string from main function
 * Return: array
 */

char *pathfinder(char *currentstr, char *subpath, char *slash)
{
	if (something != "." and something != "..")
	{
		dirtostr();
	}
}

