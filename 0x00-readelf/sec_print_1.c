#include "elfhead.h"

/**
 * print_saxon - function to print elf file section header
 * @elf_head: struct database of the elf file
 */
void print_saxon(elf_hdr *elf_head)
{
	int i, j, nsh;
	char *name = "                   ", *type = "                ";
	char *addr = "0000000000000000 ", *offs = "000000 ";

	if (magic_check(elf_head) > 0)
	{
		dprintf(STDERR_FILENO,
			"Error: Not an ELF file - it has the wrong magic bytes at the start\n");
		exit(98);
	}
	nsh = elf_head->num_sec_h;
	printf("There are %d section headers, starting at offset 0x", nsh);
	print_start(elf_head), printf(":\n\nSection Headers:\n");
	printf("  [Nr] Name              Type            ");
	if (elf_head->j == 1)
		printf("Addr     Off    Size   ES Flg Lk Inf Al\n");
	else if (elf_head->j == 2)
		printf("Address          Off    Size   ES Flg Lk Inf Al\n");
	for (i = 0; i < nsh; i++)
	{
		if (i < 10)
			printf("  [ %d] ");
		else
			printf("  [%d] ");
		for (j = 0; j < 5; j++)
			name
			printf("%s");
	}
}

/**
 * print_start - print the address of the start of section headers
 * @elf_head: struct database of the elf file
 */
void print_start(elf_hdr *elf_head)
{
	int i, j = 0, p_helper, end_i, k;

	if (elf_head->e_data == 1) /* little endian, digit position reverse */
		i = (4 * elf_head->j) - 1, end_i = -1, k = -1;
	else if (elf_head->e_data == 2) /* big endian, digit position in order */
		i = 0, end_i = 4 * elf_head->j, k = 1;
	while (i != end_i)
	{
		if (elf_head->j == 1)
			p_helper = sec_h = elf_head->start_sec_hl[i];
		else if (elf_head->j == 2)
			p_helper = sec_h = elf_head->start_sec_hh[i];
		if (j > 0)
			printf("%02x", p_helper), j++;
		else if (p_helper != 0)
			printf("%x", p_helper), j++;
		i = i + k;
	}
}
