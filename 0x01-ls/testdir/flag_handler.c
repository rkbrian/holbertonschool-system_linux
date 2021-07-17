#include "headerfile.h"

/**
 * block_list - print string for all and almost all conditions 
 * @listallflag: argument string from main function
 * @str: string to be printed
 */

char *block_list(char listallflag, char *str)
{
    int i;
    char blockarr[] = {".", ".."};

    /* block list change */
    if (av[1][i] == "a")
        printf("");

    else if (av[1][i] == "A" && str != "." && str != "..")
        return (block_list);

}

/**
 * longlist - return string for opendir 
 * @av: argument string from main function
 * Return: array
 */

char *longlist(char flagsep)
{
    char *separator;

    if (flagsep == "1")
        separator = "/n";

    else if (flagsep == "l")
        separator = "/n";

    return (separator);
}
