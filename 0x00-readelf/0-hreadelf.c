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
	if (Legolas->start_pro_hh)
		free(Legolas->start_pro_hh);
	if (Legolas->start_pro_hl)
		free(Legolas->start_pro_hl);
	if (Legolas->start_sec_hh)
		free(Legolas->start_sec_hh);
	if (Legolas->start_sec_hl)
		;
	return (0);
}

/**
 * create_fileinfo - function to create file info
 * @Legolas: struct database of the elf file
 * @filename: file name
 */
void create_fileinfo(elf_hdr *Legolas, char *filename)
{
	int i, j = 1;
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
		dprintf(STDERR_FILENO, "Error: Cannot read from file\n"), exit(98);
	for (i = 0; i < 16; i++)
		Legolas->e_magic[i] = buffer[i];
	Legolas->e_class = buffer[4], Legolas->e_data = buffer[5];
	Legolas->e_version = buffer[6], Legolas->abi_name = buffer[7];
	Legolas->abi_v = buffer[8], Legolas->type = buffer[16];
	Legolas->machine = buffer[18], Legolas->version = buffer[20];
	walternate(Legolas, buffer), j = Legolas->j;
	Legolas->flags = buffer[24 + (j * 12)]; /* to be confirmed */
	Legolas->size_eh = buffer[28 + (j * 12)]; /* to be confirmed */
	Legolas->size_pro_h = buffer[30 + (j * 12)]; /* to be confirmed */
	Legolas->num_pro_h = buffer[32 + (j * 12)]; /* to be confirmed */
	Legolas->size_sec_h = buffer[34 + (j * 12)]; /* to be confirmed */
	Legolas->num_sec_h = buffer[36 + (j * 12)]; /* to be confirmed */
	Legolas->sec_h_str_index = buffer[38 + (j * 12)]; /* to be confirmed */
	close(fd);
	if (Legolas == NULL)
		dprintf(STDERR_FILENO, "Error: Cannot read from file\n"), exit(98);
	print_head(Legolas);
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
	abyss iron_man[] = {
		{0, "No machine"}, {1, "AT&T WE 32100"}, {2, "Sparc"}, {3, "Intel 80386"},
		{4, "Motorola 68000"}, {5, "Motorola 88000"}, {7, "Intel 80860"},
		{8, "MIPS I Architecture"}, {9, "IBM System/370 Processor"},
		{10, "MIPS RS3000 Little-endian"}, {15, "Hewlett-Packard PA-RISC"},
		{17, "Fujitsu VPP500"}, {18, "Enhanced instruction set Sparc"},
		{19, "Intel 80960"}, {20, "PowerPC"}, {21, "64-bit PowerPC"},
		{22, "IBM System/390 Processor"}, {36, "NEC V800"}, {37, "Fujitsu FR20"},
		{38, "TRW RH-32"}, {39, "Motorola RCE"}, {40, "Advanced RISC Machines ARM"},
		{41, "Digital Alpha"}, {42, "Hitachi SH"}, {43, "Sparc Version 9"},
		{44, "Siemens TriCore embedded processor"},
		{45, "Argonaut RISC Core, Argonaut Technologies Inc."},
		{46, "Hitachi H8/300"}, {47, "Hitachi H8/300H"}, {48, "Hitachi H8S"},
		{49, "Hitachi H8/500"}, {50, "Intel IA-64 processor architecture"},
		{51, "Stanford MIPS-X"}, {52, "Motorola ColdFire"}, {53, "Motorola M68HC12"},
		{54, "Fujitsu MMA Multimedia Accelerator"}, {55, "Siemens PCP"},
		{56, "Sony nCPU embedded RISC processor"}, {57, "Denso NDR1 microprocessor"},
		{58, "Motorola Star*Core processor"}, {59, "Toyota ME16 processor"},
		{60, "STMicroelectronics ST100 processor"},
		{61, "Advanced Logic Corp. TinyJ embedded processor family"},
		{62, "Advanced Micro Devices X86-64"}, {63, "Sony DSP Processor"},
		{64, "Digital Equipment Corp. PDP-10"},
		{65, "Digital Equipment Corp. PDP-11"}, {66, "Siemens FX66 microcontroller"},
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
	return (NULL);
}

/**
 * walternate - choose whether store 32-bit or 64-bit variables
 * @Legolas: struct database of the elf file
 * @buffer: buffer
 */
void walternate(elf_hdr *Legolas, char *buffer)
{
	int i;

	if (Legolas->e_class == 1)
	{
		Legolas->j = 1, Legolas->entry_addrl = malloc(sizeof(uint32_t) * 4);
		if (Legolas->entry_addrl == NULL)
			return;
		for (i = 0; i < 4; i++)
			Legolas->entry_addrl[i] = buffer[24 + i]; /* to be confirmed */
		Legolas->start_pro_hl = malloc(sizeof(uint32_t) * 4);
		if (Legolas->start_pro_hl == NULL)
			return;
		for (i = 0; i < 4; i++)
			Legolas->start_pro_hl[i] = buffer[24 + (Legolas->j * 4) + i];
		Legolas->start_sec_hl = malloc(sizeof(uint32_t) * 4);
		if (Legolas->start_sec_hl == NULL)
			return;
		for (i = 0; i < 4; i++)
			Legolas->start_sec_hl[i] = buffer[24 + (Legolas->j * 8) + i];
	}
	else if (Legolas->e_class == 2)
	{
		Legolas->j = 2, Legolas->entry_addrh = malloc(sizeof(uint64_t) * 8);
		if (Legolas->entry_addrh == NULL)
			return;
		for (i = 0; i < 8; i++)
			Legolas->entry_addrh[i] = buffer[24 + i]; /* to be confirmed */
		Legolas->start_pro_hh = malloc(sizeof(uint64_t) * 8);
		if (Legolas->start_pro_hh == NULL)
			return;
		for (i = 0; i < 4; i++)
			Legolas->start_pro_hh[i] = buffer[24 + (Legolas->j * 4) + i];
		Legolas->start_sec_hh = malloc(sizeof(uint64_t) * 8);
		if (Legolas->start_sec_hh == NULL)
			return;
		for (i = 0; i < 4; i++)
			Legolas->start_sec_hh[i] = buffer[24 + (Legolas->j * 8) + i];
	}
}
