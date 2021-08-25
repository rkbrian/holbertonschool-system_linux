#include "elfhead.h"

/**
 * main - main function to print elf header
 * @argc: argument count
 * @argv: argument strings
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *filename;
	elf_hdr *Legolas = NULL;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: 0-hreadelf elf_filename\n"), exit(98);
	filename = argv[1];
	create_fileinfo(Legolas, filename);
	if (Legolas == NULL)
		dprintf(STDERR_FILENO, "Error: Cannot read from file\n"), exit(98);
	if (magic_check(Legolas) > 0)
	{
		dprintf(STDERR_FILENO,
		"Error: Not an ELF file - it has the wrong magic bytes at the start\n");
		exit(98);
	}
	print_head(Legolas);
	return (0);
}

/**
 * create_fileinfo - function to create file info
 * @Legolas: struct database of the elf file
 * @filename: file name
 */
void create_fileinfo(elf_hdr *Legolas, char *filename)
{
	int i;
	ssize_t fd, fr;
	char buffer[BUFFALO];

	fd = open(filename, O_RDWR);
	if (fd < 0)
		return;
	fr = read(fd, buffer, BUFFALO);
	if (fr < 0)
		return;
	Legolas = malloc(sizeof(elf_hdr));
	if (Legolas == NULL)
		return;
	for (i = 0; i < 16; i++)
		Legolas->e_magic[i] = buffer[i];
	Legolas->e_class = buffer[4];
	Legolas->e_data = buffer[5];
	Legolas->e_version = buffer[6];
	Legolas->abi_name = buffer[7];
	Legolas->abi_v = buffer[8];
	Legolas->type = buffer[16];
	Legolas->machine = buffer[17]; /* to be confirmed */
	Legolas->version = Legolas->e_version;
	for (i = 0; i < 4; i++)
		Legolas->entry_addr[i] = buffer[24 + i];
	Legolas->start_pro_h = buffer[19]; /* to be confirmed */
	Legolas->start_sec_h = buffer[20]; /* to be confirmed */
	Legolas->flags = buffer[21]; /* to be confirmed */
	Legolas->size_h = buffer[22]; /* to be confirmed */
	Legolas->size_pro_h = buffer[23]; /* to be confirmed */
	Legolas->num_pro_h = buffer[24]; /* to be confirmed */
	Legolas->size_sec_h = buffer[25]; /* to be confirmed */
	Legolas->num_sec_h = buffer[26]; /* to be confirmed */
	Legolas->sec_h_str_index = buffer[27]; /* to be confirmed */
	close(fd);
}

/**
 * magic_check - check if the ELF magic number is correct
 * @elf_head: struct database of the elf file
 * Return: 0 if no error, 1 if error
 */
int magic_check(elf_hdr *elf_head)
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

/**
 * war_machine - function to return machine name selected
 * @elf_head: struct database of the elf file
 * Return: machine name string
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

/**
 * entree_dressing - function to return machine name selected
 * @elf_head: struct database of the elf file
 */
void *entree_dressing(elf_hdr *elf_head)
{
	if (elf_head->entry_addr[3] != 0)
		printf("%x", elf_head->entry_addr[3]);
	if (elf_head->entry_addr[2] != 0)
		printf("%x", elf_head->entry_addr[2]);
	if (elf_head->entry_addr[1] != 0)
		printf("%x", elf_head->entry_addr[1]);
	if (elf_head->entry_addr[0] != 0)
		printf("%x", elf_head->entry_addr[0]);
	printf("\n");
}