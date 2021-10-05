#include "nm_objdump.h"

/**
 * main - function to reproduce the GNU nm command
 * @argc: argument count
 * @argv: argument strings
 * Return: 0
 */
int main(int argc, char **argv)
{
	int i, fd, fr, endian, eclass;
	unsigned char buffer[BUFFALO];

	if (argc == 1)
	{
		if ((fd = open("a.out", ORDONLY)) < 0)
			dprintf(STDERR_FILENO, "%s: 'a.out': No such file", argv[0]), exit(98);
		if ((fr = read(fd, buffer, BUFFALO)) < 0)
			dprintf(STDERR_FILENO, "Error: Cannot read from file\n"), exit(98);
		eclass = buffer[4], endian = buffer[5], close(fd);
		nm_printer("a.out", eclass, endian);
	}
	else if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
			if ((fd = open(argv[i], ORDONLY)) < 0)
				dprintf(STDERR_FILENO, "%s: '%s': No such file", argv[0], argv[i]), exit(98);
			if ((fr = read(fd, buffer, BUFFALO)) < 0)
				dprintf(STDERR_FILENO, "Error: Cannot read from file\n"), exit(98);
			eclass = buffer[4], endian = buffer[5], close(fd);
			nm_printer(argv[i], eclass, endian);
		}
	}
	else
		dprintf(STDERR_FILENO, "Usage: hnm [objfile ...]\n"), exit(98);
	return (0);
}

/**
 * nm_printer - function to print
 * @file_name: file name
 * @eclass: 32-bit or 64-bit
 * @endian: big endian or small endian
 */
void nm_printer(char *file_name, int eclass, int endian)
{
	FILE *obj_file = NULL;
	unsigned char buffer[BUFFALO];
	int i, end_i, k;

	obj_file = fopen(file_name, "rb+"), ;
	for ()
	{
		printf("\t");
	}

}
