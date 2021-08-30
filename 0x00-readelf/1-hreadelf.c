#include "sechead.h"
#include <stdio.h>
/**
 * main - main function to print elf section header
 * @argc: argument count
 * @argv: argument strings
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *elf_file = NULL;
	char *filename = NULL;
	elf32_hdr *myself = malloc(sizeof(elf32_hdr));
	/* elf64_hdr *myshelf = NULL; */
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
	{
		elf_file = fopen(filename, "r+");
		fread(myself, sizeof(elf32_hdr), 1, elf_file);
		print_saxon(myself, endian, elf_file);
	}
	/* else if (tmp_e_class == 2)create_sanction(myshelf, endian, filename); */
	return (0);
}

/**
 * create_saxon - function to create elf section header info for 32-bit
 * @myself: struct database of the elf header file
 * @endian: struct database of the elf section file
 * @elf_file: elf file
 */
void create_saxon(elf32_hdr *myself, int endian, FILE *elf_file)
{
	char *sect_names = NULL;
	const char *name;
	elf32_sh *saxon = NULL; /* elf64_sh *sanction = NULL; */
	uint idx;
	long int tmp_offset = 0;
	int i, end_i, k, sec_h;

	printf("%lu\n", sizeof(elf32_sh));
	/* note: read section name string table, read the header first */
	tmp_offset = 0;
	if (endian == 1) /* little endian, digit position reverse */
		i = 3, end_i = -1, k = -1;
	else if (endian == 2)
		i = 0, end_i = 4, k = 1;
	for (; i != end_i; i = i + k)
	{
		sec_h = myself->start_sec_hl[i];
		if (sec_h < 0)
			sec_h = sec_h + 256;
		tmp_offset = (tmp_offset * 256) + sec_h;
	}
	printf("myself->sec_h_str_index, little endian: %ld\n", tmp_offset);
	tmp_offset = tmp_offset + sizeof(elf32_sh);
	for (idx = 1; idx < myself->num_sec_h; idx++)
	{
		saxon = malloc(sizeof(elf32_sh));
		if (saxon == NULL)
			return;
		/* printf("tmp_offset before fseek %ld, ", tmp_offset); */
		fseek(elf_file, tmp_offset, SEEK_SET);
		/* printf("after fseek %ld\n", tmp_offset); */

		fread(saxon, sizeof(elf32_sh), 1, elf_file);
		/* read the section, string data */
		sect_names = malloc(saxon->sh_size);
		if (sect_names == NULL)
			return;
		fseek(elf_file, saxon->sh_offset, SEEK_SET); /* seek_set: start of a file*/
		fread(sect_names, saxon->sh_size, 1, elf_file);
		name = "";
		/* read all section headers */
		/* print section name */
		if (saxon->sh_name)
			name = sect_names + saxon->sh_name;
		printf("[%2u] %s\n", idx, name);
		tmp_offset = tmp_offset + sizeof(elf32_sh);
	}
	printf("Key to Flags:\n");
	printf("  W (write), A (alloc), X (execute), M (merge), S (strings)\n");
	printf("  I (info), L (link order), G (group), T (TLS), E (exclude), x (unknown)\n");
	printf("  O (extra OS processing required) o (OS specific), p (processor specific)\n");
}
