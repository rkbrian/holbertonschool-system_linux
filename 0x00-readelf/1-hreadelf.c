#include "sechead.h"

/**
 * main - main function to print elf section header
 * @argc: argument count
 * @argv: argument strings
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *filename = NULL;
	elf32_hdr *myself = NULL;
	/* elf64_hdr *myshelf = NULL; */
	/* elf32_sh *saxon = NULL; */
	/* elf64_sh *sanction = NULL; */
	ssize_t fd, fr;
	unsigned char buffer[BUFFALO];
	int tmp_e_class, endian;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: 1-hreadelf elf_filename\n"), exit(98);
	filename = argv[1];
	fd = open(filename, O_RDWR);
	if (fd < 0)
		dprintf(STDERR_FILENO, "Error: Cannot read from file\n"), exit(98);
	fr = read(fd, buffer, BUFFALO);
	if (fr < 0)
		dprintf(STDERR_FILENO, "Error: Cannot read from file\n"), exit(98);
	tmp_e_class = buffer[4], endian = buffer[5], close(fd);
	if (tmp_e_class == 1)
		create_saxon(myself, endian, filename);
	/* else if (tmp_e_class == 2)create_sanction(myshelf, endian, filename); */
	return (0);
}

/**
 * create_saxon - function to create elf section header info for 32-bit
 * @myself: struct database of the elf header file
 * @endian: struct database of the elf section file
 * @filename: file name
 */
void create_saxon(elf32_hdr *myself, int endian, char *filename)
{
	char *sect_names = NULL;
	FILE *elf_file = NULL;
	elf32_sh *saxon = NULL; /* elf64_sh *sanction = NULL; */
	uint idx;
	int tmp_e_class;

	(void) endian;
	elf_file = fopen(filename, "r+");
	fread(&myself, 1, sizeof(elf32_hdr), elf_file);
	/* note: read section name string table, read the header first */
	fseek(elf_file, (myself->start_sec_hl + myself->sec_h_str_index * sizeof(elf32_hdr)), SEEK_SET);
	fread(&saxon, 1, sizeof(elf32_sh), elf_file);
	/* read the section, string data */
	sect_names = malloc(saxon->sh_size);
	if (sect_names == NULL)
		return;
	fseek(elf_file, saxon->sh_offset, SEEK_SET); /* seek_set: start of a file*/
	fread(sect_names, 1, saxon->sh_size, elf_file);

	/* print_saxon(myself); */
	/* read all section headers */
	for (idx = 0; idx < myself.e_shnum; idx++)
	{
		const char *name = "";

		fseek(elf_file, myself->start_sec_hl + idx * sizeof(elf32_hdr), SEEK_SET);
		fread(&saxon, 1, sizeof(elf32_hdr), elf_file);

		/* print section name */
		if (saxon.sh_name)
			name = sect_names + saxon->sh_name;
		printf("%2u %s\n", idx, name);
	}
}
