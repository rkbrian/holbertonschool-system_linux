#include "elfhead.h"

/**
 * indie_game - function to print endianness
 * @elf_head: struct database of the elf file
 */
void indie_game(elf_hdr *elf_head)
{
	int i, j = 0, psum = 0, ssum = 0, end_i, k, pro_h, sec_h;
	/* unsigned int p_helper; */

	if (elf_head->e_data == 1) /* little endian, digit position reverse */
		i = (4 * elf_head->j) - 1, end_i = -1, k = -1;
	else if (elf_head->e_data == 2) /* big endian, digit position in order */
		i = 0, end_i = 4 * elf_head->j, k = 1;
	while (i != end_i)
	{
		if (elf_head->j == 1)
		{
			/* p_helper = elf_head->entry_addrl[i]; */
			if (j > 0)
				printf("%02x", elf_head->entry_addrl[i]), j++;
			else if (elf_head->entry_addrl[i] != 0)
				printf("%x", elf_head->entry_addrl[i]), j++;
			pro_h = elf_head->start_pro_hl[i], sec_h = elf_head->start_sec_hl[i];
		}
		else
		{
			/* p_helper = elf_head->entry_addrh[i]; */
			if (j > 0)
				printf("%02x", elf_head->entry_addrh[i]), j++;
			else if (elf_head->entry_addrh[i] != 0)
				printf("%x", elf_head->entry_addrh[i]), j++;
			pro_h = elf_head->start_pro_hh[i], sec_h = elf_head->start_sec_hh[i];
		}
		if (pro_h < 0)
			pro_h = pro_h + 256;
		if (sec_h < 0)
			sec_h = sec_h + 256; /* if (p_helper > 256)p_helper = p_helper + 256; */
		/* if (j > 0)printf("%02x", p_helper), j++; else if (p_helper != 0)printf("%x", p_helper), j++; */
		psum = (256 * psum) + pro_h, ssum = (256 * ssum) + sec_h, i = i + k;
	}
	if (j == 0)
		printf("0");
	printf("\n  Start of program headers:          %d (bytes into file)\n", psum);
	printf("  Start of section headers:          %d (bytes into file)\n", ssum);
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
	if (elf_head->j == 1)
	{
		free(elf_head->entry_addrl);
		free(elf_head->start_pro_hl);
		free(elf_head->start_sec_hl);
	}
	else if (elf_head->j == 2)
	{
		free(elf_head->entry_addrh);
		free(elf_head->start_pro_hh);
		free(elf_head->start_sec_hh);
	}
	free(elf_head);
}
