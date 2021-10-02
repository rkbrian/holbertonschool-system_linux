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
	char *name; /* name is array of numbers */
	elf32_sh *saxon = NULL; /* elf64_sh *sanction = NULL; */
	uint idx; /*int i, end_i, k, sec_h; */

	saxon = malloc(sizeof(elf32_sh));
	if (saxon == NULL)
		return;
	if (endian == 2)
		myself->sec_h_str_index = bitwise_swap(myself->sec_h_str_index, 2);
	fseek(elf_file, myself->start_sec_hl
	      + sizeof(elf32_sh) * myself->sec_h_str_index, SEEK_SET);
	fread(saxon, sizeof(elf32_sh), 1, elf_file);
	fseek(elf_file, saxon->sh_offset, SEEK_SET);
	if (endian == 2)
		saxon->sh_size = bitwise_swap(saxon->sh_size, 4);
	name = malloc(sizeof(char) * saxon->sh_size);
	if (name == NULL)
		return;
	fread(name, saxon->sh_size, 1, elf_file);
	fseek(elf_file, myself->start_sec_hl, SEEK_SET);
	for (idx = 0; idx < myself->num_sec_h; idx++)
	{
		fread(saxon, sizeof(elf32_sh), 1, elf_file);
		if (endian == 2)
			saxon = saxon_swap(saxon);
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
	printf(" p (processor specific)\n"), free(name), free(saxon), free(myself);
}

/**
 * saxon_swap - bitwise swap every element in the elf section struct
 * @saxon: elf section struct
 * Return: elf section struct after the swaps
 */
elf32_sh *saxon_swap(elf32_sh *saxon)
{
	saxon->sh_name = bitwise_swap(saxon->sh_name, 4);
	saxon->sh_type = bitwise_swap(saxon->sh_type, 4);
	saxon->sh_flags = bitwise_swap(saxon->sh_flags, 4);
	saxon->sh_addr = bitwise_swap(saxon->sh_addr, 4);
	saxon->sh_offset = bitwise_swap(saxon->sh_offset, 4);
	saxon->sh_size = bitwise_swap(saxon->sh_size, 4);
	saxon->sh_link = bitwise_swap(saxon->sh_link, 4);
	saxon->sh_info = bitwise_swap(saxon->sh_info, 4);
	saxon->sh_addr_align = bitwise_swap(saxon->sh_addr_align, 4);
	saxon->sh_entsize = bitwise_swap(saxon->sh_entsize, 4);
	return (saxon);
}

/**
 * bitwise_swap - swap endianness
 * @num: number to be swapped for endianness
 * @bitsize: 2 for 16-bit, 4 for 32-bit, 8 for 64-bit
 * Return: swapped value
 */
unsigned long int bitwise_swap(unsigned long int num, int bitsize)
{
	uint16_t s0, s1, small_boss;
	uint32_t b0, b1, b2, b3, boss;
	uint64_t bb0, bb1, bb2, bb3, bb4, bb5, bb6, bb7, bboss;

	if (bitsize == 4)
	{
		b0 = (num & 0x000000ff) << 24u;
		b1 = (num & 0x0000ff00) << 8u;
		b2 = (num & 0x00ff0000) >> 8u;
		b3 = (num & 0xff000000) >> 24u;
		boss = b0 | b1 | b2 | b3;
		return (boss);
	}
	else if (bitsize == 8)
	{
		bb0 = (num & 0x00000000000000ff) << 56u;
		bb1 = (num & 0x000000000000ff00) << 40u;
		bb2 = (num & 0x0000000000ff0000) << 24u;
		bb3 = (num & 0x00000000ff000000) << 8u;
		bb4 = (num & 0x000000ff00000000) >> 8u;
		bb5 = (num & 0x0000ff0000000000) >> 24u;
		bb6 = (num & 0x00ff000000000000) >> 40u;
		bb7 = (num & 0xff00000000000000) >> 56u;
		bboss = bb0 | bb1 | bb2 | bb3 | bb4 | bb5 | bb6 | bb7;
		return (bboss);
	}
	else if (bitsize == 2)
	{
		s0 = (num & 0x00ff) << 8u;
		s1 = (num & 0xff00) >> 8u;
		small_boss = s0 | s1;
		return (small_boss);
	}
	return (num);
}
