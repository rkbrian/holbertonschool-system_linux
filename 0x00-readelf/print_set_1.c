#include "elfhead.h"

/**
 * print_head - function to print elf file header
 * @elf_head: struct database of the elf file
 */
void print_head(elf_hdr *elf_head)
{
	int i;

	if (magic_check(elf_head) > 0)
	{
		dprintf(STDERR_FILENO,
			"Error: Not an ELF file - it has the wrong magic bytes at the start\n");
		exit(98);
	}
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < 16; i++)
		printf("%02x ", elf_head->e_magic[i]);
	printf("\n");
	print_to_entry(elf_head);
        print_to_shstrndx(elf_head);
}

/**
 * print_to_entry - to print E_IDENT, type, machine, version and entry info
 * @elf_head: struct database of the elf file
 */
void print_to_entry(elf_hdr *elf_head)
{
	printf("  Class:                             ");
	if (elf_head->e_class == 1)
		printf("ELF32\n");
	else if (elf_head->e_class == 2)
		printf("ELF64\n");
	else if (elf_head->e_class == 0)
		printf("ELFNONE\n");
	printf("  Data:                              ");
	if (elf_head->e_data == 1)
		printf("2's complement, little endian\n");
	else if (elf_head->e_data == 2)
		printf("2's complement, big endian\n");
	else if (elf_head->e_data == 0)
		printf("NONE\n");
	printf("  Version:                           ");
	if (elf_head->e_version == 1)
		printf("1 (current)\n");
	printf("  OS/ABI:                            ");
	printf("%s\n", abi_list(elf_head));
	printf("  ABI Version:                       ");
	printf("%d\n", elf_head->abi_v);
	printf("  Type:                              ");
	printf("%s\n", type_list(elf_head));
	printf("  Machine:                           ");
	printf("%s\n", war_machine(elf_head));
	printf("  Version:                           ");
	if (elf_head->e_version == 1)
		printf("0x1\n");
	printf("  Entry point address:               0x");
	indie_game(elf_head);
        print_to_shstrndx(elf_head);
}

/**
 * abi_list - function to return abi name selected
 * @elf_head: struct database of the elf file
 * Return: abi name string
 */
char *abi_list(elf_hdr *elf_head)
{
	int i;
	abyss billy[] = {
		{0, "Unix - System V"},
		{1, "HP-UX"},
		{2, "Unix - NetBSD"},
		{3, "Linux"},
		{4, "GNU Hurd"},
		{6, "Solaris"},
		{7, "AIX"},
		{8, "IRIX"},
		{9, "FreeBSD"},
		{10, "Tru64 Unix"},
		{11, "Novell Modesto"},
		{12, "OpenBSD"},
		{13, "OpenVMS"},
		{14, "NonStop Kernel"},
		{15, "AROS"},
		{16, "Fenix OS"},
		{17, "CloudABI"},
		{18, "Stratus Technologies OpenVOS"}
	};

	for (i = 0; i < 19; i++)
	{
		if (elf_head->abi_name == billy[i].id)
			return (billy[i].abi_name);
	}
	return ("Architecture-specific value range");
}

/**
 * type_list - function to return type name selected
 * @elf_head: struct database of the elf file
 * Return: type name string
 */
char *type_list(elf_hdr *elf_head)
{
	int i, j = elf_head->type;
	abyss tea_party[] = {
		{0, "NONE (Unknown file)"},
		{1, "REL (Relocatable file)"},
		{2, "EXEC (Executable file)"},
		{3, "DYN (Shared object file)"},
		{4, "CORE (Core file)"}
	}; /* this format is borrowed from abi list for type list */

	for (i = 0; i < 5; i++)
	{
		if (j == tea_party[i].id)
			return (tea_party[i].abi_name);
	}
	return ("LOOS (Operating system-specific");
}
