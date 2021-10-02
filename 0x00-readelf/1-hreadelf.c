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
	char *name, *flgs = "   "; /* name is array of numbers */
	elf32_sh *saxon = NULL; /* elf64_sh *sanction = NULL; */
	uint idx; /*int i, end_i, k, sec_h; */

	/* if (endian == 1) i = 3, end_i = -1, k = -1; */
	/* else if (endian == 2) i = 0, end_i = 4, k = 1; */
	saxon = malloc(sizeof(elf32_sh));
	if (saxon == NULL)
		return;
	fseek(elf_file, myself->start_sec_hl
	      + sizeof(elf32_sh) * myself->sec_h_str_index, SEEK_SET);
	fread(saxon, sizeof(elf32_sh), 1, elf_file);
	fseek(elf_file, saxon->sh_offset, SEEK_SET);
	name = malloc(sizeof(char) * saxon->sh_size);
	if (name == NULL)
		return;
	fread(name, saxon->sh_size, 1, elf_file);
	fseek(elf_file, myself->start_sec_hl, SEEK_SET);
	for (idx = 0; idx < myself->num_sec_h; idx++)
	{
		fread(saxon, sizeof(elf32_sh), 1, elf_file);
		printf("  [%2u] %-17s ", idx, name + saxon->sh_name);
		printf("%-16s%08x ", typewriter(saxon->sh_type), saxon->sh_addr);
		printf("%06x %06x ", saxon->sh_offset, saxon->sh_size);
		printf("%02x ", saxon->sh_entsize), sec_flag(saxon->sh_flags);
		printf("%3d %3d", saxon->sh_link, saxon->sh_info);
		printf("%3d\n", saxon->sh_addr_align);
	}
	printf("Key to Flags:\n");
	printf("  W (write), A (alloc), X (execute), M (merge), S (strings)\n");
	printf("  I (info), L (link order), G (group), T (TLS), E (exclude)");
	printf(", x (unknown)\n  O (extra OS processing required) o (OS specific),");
	printf(" p (processor specific)\n"), free(name), free(saxon);
}
