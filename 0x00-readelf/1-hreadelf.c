#include "elfhead.h"

/**
 * main - main function to print elf section header
 * @argc: argument count
 * @argv: argument strings
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *filename;
	elf32_sh *she_sells = NULL;
	elf64_sh *sea_shells = NULL;
	elf_hdr *on_the_sea_shore = NULL;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: 1-hreadelf elf_filename\n"), exit(98);
	filename = argv[1];
	create_fileinfo(on_the_sea_shore, filename);
	if (on_the_sea_shore->e_data == 1) /* 32-bit functions */
	{
		create_saxon(she_sells, on_the_sea_shore, filename);
		print_saxon(she_sells, on_the_sea_shore);
	}
	else if (on_the_sea_shore->e_data == 2) /* 64-bit functions */
	{
		create_sanction(sea_shells, on_the_sea_shore, filename);
		print_sanction(sea_shells, on_the_sea_shore);
	}
	return (0);
}

/**
 * create_saxon - function to create file info
 * @saxon: struct database of the elf section file
 * @filename: file name
 */
void create_saxon(elf32_sh *saxon, char *filename)
{
	;


	;
}
