#include "elfhead.h"

/**
 * indie_game - function to print endianness
 * @indigo: array of numbers, big endian
 * @byte_size: array length, 4 or 8
 */
void indie_game(elf_hdr elf_head)
{
	int i, pro_sum = 0, sec_sum = 0;

	if (elf_head->j == 1)
	{
		for (i = 3; i >= 0; i--)
		{
			if (elf_head->entry_addrl[i] != 0)
				printf("%x", elf_head->entry_addrl[i]);
		}
		for (i = 3; i >= 0; i--)
		{
			pro_sum = (256 * pro_sum) + elf_head->start_pro_hl[i]);
			sec_sum = (256 * sec_sum) + elf_head->start_sec_hl[i]);
		}
	}
	else if (elf_head->j == 2)
	{
		for (i = 7; i >= 0; i--)
		{
			if (elf_head->entry_addrh[i] != 0)
				printf("%x", elf_head->entry_addrh[i]);
		}
		for (i = 8; i >= 0; i--)
		{
			pro_sum = (256 * pro_sum) + elf_head->start_pro_hh[i]);
			sec_sum = (256 * sec_sum) + elf_head->start_sec_hh[i]);
		}
	}
	printf("\n");
	printf("  Start of program headers:          %d (bytes into file)\n", pro_sum);
	printf("  Start of section headers:          %d (bytes into file)\n", sec_sum);
}

/**
 * print_to_shstrndx - function to print section and program header tables
 * @elf_head: struct database of the elf file
 */
void print_to_shstrndx(elf_hdr *elf_head)
{
	printf("  Flags:                             ");
	printf("0x%x\n", elf_head->flags);
	printf("  Size of this header:               ");
	printf("%d (bytes)\n", elf_head->size_eh);
	printf("  Size of program headers:           ");
	printf("%d (bytes)\n", elf_head->size_pro_h);
	printf("  Number of program headers:         ");
	printf("%d\n", elf_head->num_pro_h);
	printf("  Size of section headers:           ");
	printf("%d (bytes)\n", elf_head->size_sec_h);
	printf("  Number of section headers:         ");
	printf("%d\n", elf_head->num_sec_h);
	printf("  Section header string table index: ");
	printf("%d\n", elf_head->sec_h_str_index);
}
