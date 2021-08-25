#include "elfhead.h"

/**
 * print_head - function to print elf file header
 * @elf_head: struct database of the elf file
 */
void print_head(elf_hdr *elf_head)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < 16; i++)
		printf("%02x ", elf_head->e_magic[i]);
	printf("\n");
	print_h_magic16(elf_head);
}

/**
 * print_h_magic16 - function to print E_IDENT info (1st 16 numbers)
 * @elf_head: struct database of the elf file
 */
void print_h_magic16(elf_hdr *elf_head)
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
	printf("  Entry point address:               ");
	printf("%s\n", war_machine(elf_head));
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
		{0, "System V"},
		{1, "HP-UX"},
		{2, "NetBSD"},
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

/**
 * war_machine - function to return machine name selected
 * @elf_head: struct database of the elf file
 */
char *war_machine(elf_hdr *elf_head)
{
	int i, j = elf_head->machine;
	abyss iron_man[] = {{0, "No machine"}, {1, "AT&T WE 32100"}, {2, "Sparc"},
			    {3, "Intel 80386"}, {4, "Motorola 68000"}, {5, "Motorola 88000"},
			    {7, "Intel 80860"}, {8, "MIPS I Architecture"},
			    {9, "IBM System/370 Processor"}, {10, "MIPS RS3000 Little-endian"},
			    {15, "Hewlett-Packard PA-RISC"}, {17, "Fujitsu VPP500"},
			    {18, "Enhanced instruction set Sparc"}, {19, "Intel 80960"},
			    {20, "PowerPC"}, {21, "64-bit PowerPC"},
			    {22, "IBM System/390 Processor"}, {36, "NEC V800"},
			    {37, "Fujitsu FR20"}, {38, "TRW RH-32"}, {39, "Motorola RCE"},
			    {40, "Advanced RISC Machines ARM"}, {41, "Digital Alpha"},
			    {42, "Hitachi SH"}, {43, "Sparc Version 9"},
			    {44, "Siemens TriCore embedded processor"},
			    {45, "Argonaut RISC Core, Argonaut Technologies Inc."}, 
			    {46, "Hitachi H8/300"}, {47, "Hitachi H8/300H"}, {48, "Hitachi H8S"},
			    {49, "Hitachi H8/500"}, {50, "Intel IA-64 processor architecture"},
			    {51, "Stanford MIPS-X"}, {52, "Motorola ColdFire"},
			    {53, "Motorola M68HC12"}, {54, "Fujitsu MMA Multimedia Accelerator"},
			    {55, "Siemens PCP"}, {56, "Sony nCPU embedded RISC processor"},
			    {57, "Denso NDR1 microprocessor"},
			    {58, "Motorola Star*Core processor"}, {59, "Toyota ME16 processor"},
			    {60, "STMicroelectronics ST100 processor"},
			    {61, "Advanced Logic Corp. TinyJ embedded processor family"},
			    {62, "Advanced Micro Devices X86-64"}, {63, "Sony DSP Processor"},
			    {64, "Digital Equipment Corp. PDP-10"},
			    {65, "Digital Equipment Corp. PDP-11"},
			    {66, "Siemens FX66 microcontroller"},
			    {67, "STMicroelectronics ST9+ 8/16 bit microcontroller"},
			    {68, "STMicroelectronics ST7 8-bit microcontroller"},
			    {69, "Motorola MC68HC16 Microcontroller"},
			    {70, "Motorola MC68HC11 Microcontroller"},
			    {71, "Motorola MC68HC08 Microcontroller"},
			    {72, "Motorola MC68HC05 Microcontroller"}, {73, "Silicon Graphics SVx"},
			    {74, "STMicroelectronics ST19 8-bit microcontroller"}
	}; /* Iron Man surely has lots of armors */

	for (i = 0; i < 75; i++)
	{
		if (j == iron_man[i].id)
			return (iron_man[i].abi_name);
	}
	return ("LOOS (Operating system-specific");
}
