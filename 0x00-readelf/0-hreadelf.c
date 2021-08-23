#include "elfhead.h"

/**
 * main - main function to print elf header
 * @argc: argument count
 * @argv: argument strings
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *filename;
	elf_hdr Legolas;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: 0-hreadelf elf_filename\n"), exit(98);
	filename = argv[1], Legolas = create_fileinfo(filename);
	if (Legolas == NULL)
		dprintf(STDERR_FILENO, "Error: Cannot read from file\n"), exit(98);

}

/**
 * create_fileinfo - function to create file info
 * @filename: file name
 * Return: struct database if succeed, null if failed
 */
elf_hdr create_fileinfo(char *filename)
{
	int i;
	ssize_t fd, fr;
	char *buffer[BUFFALO];

	fd = open(filename, O_RDWR);
	if (fd < 0)
		return(NULL);
	fr = read(filename, buffer, BUFFALO);
	if (fr < 0)
		return (NULL);
	for (i = 0; )

}

/**
 * magic_check - check if the ELF magic number is correct
 * @elf_head: struct database of the elf file
 */
void magic_check(elf_hdr elf_head)
{
	int i;

	if (elf_head->e_magic[EI_MAG0] != EI_MAG0)
	{
		dprintf(STDERR_FILENO, "Error: ELF Header EI_MAG0 incorrect.\n");
		return;
	}
	if (elf_head->e_magic[EI_MAG1] != EI_MAG1)
	{
		dprintf(STDERR_FILENO, "Error: ELF Header EI_MAG1 incorrect.\n");
		return;
	}
	if (elf_head->e_magic[EI_MAG2] != EI_MAG2)
	{
		dprintf(STDERR_FILENO, "Error: ELF Header EI_MAG2 incorrect.\n");
		return;
	}
	if (elf_head->e_magic[EI_MAG3] != EI_MAG3)
	{
		dprintf(STDERR_FILENO, "Error: ELF Header EI_MAG3 incorrect.\n");
		return;
	}
	for (i = 0; )
}
