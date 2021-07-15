#include "headerfile.h"

/**
 * block_list - return array of setup condition to control the readdir output 
 * 
 * Return: array
 */

char *block_list(char *flag_string)
{
    int i;
    char blockarr[20] = {".", "..", ".hidden"};

    {
        if (flag_string[i] == "a")
        {
            return (NULL);
        }
        if (flag_string[i] == "A")
        {
            return (block_list);
        }
    }
}