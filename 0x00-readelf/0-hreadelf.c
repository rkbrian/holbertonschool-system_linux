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
	elf_hdr *Legolas = NULL;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: 0-hreadelf elf_filename\n"), exit(98);
	filename = argv[1], Legolas = create_fileinfo(filename);
	if (Legolas == NULL)
		dprintf(STDERR_FILENO, "Error: Cannot read from file\n"), exit(98);
	if (magic_check(Legolas) > 0)
	{
		dprintf(STDERR_FILENO,
		"Error: Not an ELF file - it has the wrong magic bytes at the start\n");
		exit(98);
	}
	print_head(Legolas);
	return (0);
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
	char buffer[BUFFALO];
	elf_hdr *Legolas;

	fd = open(filename, O_RDWR);
	if (fd < 0)
		return (NULL);
	fr = read(filename, buffer, BUFFALO);
	if (fr < 0)
		return (NULL);
	Legolas = malloc(sizeof(elf_hdr));
	if (Legolas == NULL)
		return (NULL);
	for (i = 0; i < 16; i++)
		Legolas->e_magic[i] = buffer[i];
	Legolas->e_class = buffer[4];
	Legolas->e_data = buffer[5];
	Legolas->e_version = buffer[6];
	Legolas->abi_name = buffer[7];
	Legolas->abi_v = buffer[8];
	Legolas->type = buffer[16];
	Legolas->machine = buffer[17]; /* to be confirmed */
	Legolas->version = Legolas->e_version;
	for (i = 0; i < 4; i++)
		Legolas->entry_addr[i] = buffer[24 + i];
	Legolas->start_pro_h = buffer[19]; /* to be confirmed */
	Legolas->start_sec_h = buffer[20]; /* to be confirmed */
	Legolas->flags = buffer[21]; /* to be confirmed */
	Legolas->size_h = buffer[22]; /* to be confirmed */
	Legolas->size_pro_h = buffer[23]; /* to be confirmed */
	Legolas->num_pro_h = buffer[24]; /* to be confirmed */
	Legolas->size_sec_h = buffer[25]; /* to be confirmed */
	Legolas->num_sec_h = buffer[26]; /* to be confirmed */
	Legolas->sec_h_str_index = buffer[27]; /* to be confirmed */
	close(filename);
	return (Legolas);
}

/**
 * magic_check - check if the ELF magic number is correct
 * @elf_head: struct database of the elf file
 * Return: 0 if no error, 1 if error
 */
int magic_check(elf_hdr *elf_head)
{
	if (elf_head->e_magic[EI_MAG0] != EI_MAG0)
	{
		dprintf(STDERR_FILENO, "Error: ELF Header EI_MAG0 incorrect.\n");
		return (1);
	}
	if (elf_head->e_magic[EI_MAG1] != EI_MAG1)
	{
		dprintf(STDERR_FILENO, "Error: ELF Header EI_MAG1 incorrect.\n");
		return (1);
	}
	if (elf_head->e_magic[EI_MAG2] != EI_MAG2)
	{
		dprintf(STDERR_FILENO, "Error: ELF Header EI_MAG2 incorrect.\n");
		return (1);
	}
	if (elf_head->e_magic[EI_MAG3] != EI_MAG3)
	{
		dprintf(STDERR_FILENO, "Error: ELF Header EI_MAG3 incorrect.\n");
		return (1);
	}
	return (0);
}
