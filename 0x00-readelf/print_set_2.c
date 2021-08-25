#include "elfhead.h"

/**
 * indie_game - function to print endianness
 * @elf_head: struct database of the elf file
 */
void indie_game(elf_hdr *elf_head)
{
	int i, print_helper, p_sum = 0, s_sum = 0;

	if (elf_head->j == 1)
	{
		for (i = 3; i >= 0; i--)
		{
			if (elf_head->entry_addrl[i] != 00)
			{
				print_helper = elf_head->entry_addrl[i];
				printf("%x", print_helper);
			}
		}
		for (i = 3; i >= 0; i--)
		{
			p_sum = (256 * p_sum) + elf_head->start_pro_hl[i];
			s_sum = (256 * s_sum) + elf_head->start_sec_hl[i];
		}
	}
	else if (elf_head->j == 2)
	{
		for (i = 7; i >= 0; i--)
		{
			if (elf_head->entry_addrh[i] != 00)
			{
				print_helper = elf_head->entry_addrh[i];
				printf("%x", print_helper);
			}
		}
		for (i = 8; i >= 0; i--)
		{
			p_sum = (256 * p_sum) + elf_head->start_pro_hh[i];
			s_sum = (256 * s_sum) + elf_head->start_sec_hh[i];
		}
	}
	printf("\n");
	printf("  Start of program headers:          %d (bytes into file)\n", p_sum);
	printf("  Start of section headers:          %d (bytes into file)\n", s_sum);
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
