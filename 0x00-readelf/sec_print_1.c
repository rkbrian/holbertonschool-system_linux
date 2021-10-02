#include "sechead.h"

/**
 * print_saxon - function to print elf file section header
 * @elf_head: struct database of the elf file
 * @endian: struct database of the elf section file
 * @elf_file: elf file
 */
void print_saxon(elf32_hdr *elf_head, int endian, FILE *elf_file)
{
	int nsh;

	if (endian == 2)
	{
		elf_head->start_sec_hl = bitwise_swap(elf_head->start_sec_hl, 4);
		elf_head->num_sec_h = bitwise_swap(elf_head->num_sec_h, 2);
	}
	nsh = elf_head->num_sec_h;
	printf("There are %d section headers, starting at offset ", nsh);
	printf("%#x", elf_head->start_sec_hl);
	/*print_shoff(elf_head)*/
	printf(":\n\nSection Headers:\n");
	printf("  [Nr] Name              Type            ");
	if (elf_head->e_class == 1)
		printf("Addr     Off    Size   ES Flg Lk Inf Al\n");
	else if (elf_head->e_class == 2)
		printf("Address          Off    Size   ES Flg Lk Inf Al\n");
	create_saxon(elf_head, endian, elf_file);
}

/**
 * sec_flag - print flag string
 * @data: data from section header to define all the flag chars
 */
void sec_flag(unsigned long int data)
{
	int idx = 2;
	char flg_str[3] = "   ";

	if (data & SHF_EXECINSTR)
		flg_str[idx] = 'X', idx--;
	if (data & SHF_INFO_LINK)
		flg_str[idx] = 'I', idx--;
	if (data & SHF_STRINGS)
		flg_str[idx] = 'S', idx--;
	if (data & SHF_MERGE)
		flg_str[idx] = 'M', idx--;
	if (data & SHF_ALLOC)
		flg_str[idx] = 'A', idx--;
	if (data & SHF_WRITE)
		flg_str[idx] = 'W', idx--;
	if (data & SHF_EXCLUDE)
		flg_str[idx] = 'E', idx--;
	printf("%c%c%c", flg_str[0], flg_str[1], flg_str[2]);
}

/**
 * typewriter - function to find the types in elf section file
 * @type: type representation in integer form
 * Return: string of type name to be printed
 */
char *typewriter(int type)
{
	int i;
	abyss tidy[] = {{SHT_NULL, "NULL"}, {SHT_PROGBITS, "PROGBITS"},
			{SHT_SYMTAB, "SYMTAB"}, {SHT_STRTAB, "STRTAB"}, {SHT_RELA, "RELA"},
			{SHT_HASH, "HASH"}, {SHT_DYNAMIC, "DYNAMIC"}, {SHT_NOTE, "NOTE"},
			{SHT_NOBITS, "NOBITS"}, {SHT_REL, "REL"}, {SHT_DYNSYM, "DYNSYM"},
			{SHT_GNU_HASH, "GNU_HASH"}, {SHT_GNU_versym, "VERSYM"},
			{SHT_GNU_verneed, "VERNEED"}, {SHT_INIT_ARRAY, "INIT_ARRAY"},
			{SHT_FINI_ARRAY, "FINI_ARRAY"}, {0x6ffffffc, "VERDEF"},
			{0x6ffffff1, "LOOS+ffffff1"}, {0x6ffffff3, "LOOS+ffffff3"}};

	for (i = 0; tidy[i].abi_name != NULL; i++)
	{
		if (type == tidy[i].id)
			return (tidy[i].abi_name);
	}
	return (NULL);
}

/**
 * magic_check - check if the ELF magic number is correct
 * @elf_head: struct database of the elf file
 * Return: 0 if no error, 1 if error
 */
int magic_check(elf32_hdr *elf_head)
{
	if (elf_head->e_magic[0] != EI_MAG0)
	{
		dprintf(STDERR_FILENO, "Error: ELF Header EI_MAG0 incorrect.\n");
		return (1);
	}
	if (elf_head->e_magic[1] != EI_MAG1)
	{
		dprintf(STDERR_FILENO, "Error: ELF Header EI_MAG1 incorrect.\n");
		return (1);
	}
	if (elf_head->e_magic[2] != EI_MAG2)
	{
		dprintf(STDERR_FILENO, "Error: ELF Header EI_MAG2 incorrect.\n");
		return (1);
	}
	if (elf_head->e_magic[3] != EI_MAG3)
	{
		dprintf(STDERR_FILENO, "Error: ELF Header EI_MAG3 incorrect.\n");
		return (1);
	}
	return (0);
}
