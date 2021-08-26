#include "elfhead.h"

/**
 * main - main function to print elf section header
 * @argc: argument count
 * @argv: argument strings
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *filename;
	elf32_sh *she_sells = NULL;
	elf64_sh *sea_shells = NULL;
	elf_hdr *on_the_sea_shore = NULL;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: 1-hreadelf elf_filename\n"), exit(98);
	filename = argv[1];
	create_simpleinfo(on_the_sea_shore, filename);
	printf("test print: %d\n", on_the_sea_shore->type);
	if (on_the_sea_shore->e_data == 1) /* 32-bit functions */
	{
		create_saxon(she_sells, on_the_sea_shore, filename);
		print_saxon(she_sells, on_the_sea_shore);
	}
	else if (on_the_sea_shore->e_data == 2) /* 64-bit functions */
	{
		create_sanction(sea_shells, on_the_sea_shore, filename);
		print_sanction(sea_shells, on_the_sea_shore);
	}
	return (0);
}

/**
 * create_saxon - function to create file info
 * @saxon: struct database of the elf section file
 * @filename: file name
 */
void create_saxon(elf32_sh *saxon, char *filename)
{
	;
}

/**
 * create_simpleinfo - function to create file info
 * @Legolas: struct database of the elf file
 * @filename: file name
 */
void create_simpleinfo(elf_hdr *Legolas, char *filename)
{
	int i, j = 1, z = 0;
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
	Legolas->j = Legolas->e_class;
	Legolas->e_version = buffer[6], Legolas->abi_name = buffer[7];
	Legolas->abi_v = buffer[8], Legolas->type = buffer[16];
	if (Legolas->type == 0)
		z = 1;
	Legolas->machine = buffer[18], Legolas->version = buffer[20];
	walternate(Legolas, buffer), j = Legolas->j;
	Legolas->flags = buffer[24 + (j * 12)];
	Legolas->size_eh = buffer[28 + (j * 12) + z];
	Legolas->size_pro_h = buffer[30 + (j * 12) + z];
	Legolas->num_pro_h = buffer[32 + (j * 12) + z];
	Legolas->size_sec_h = buffer[34 + (j * 12) + z];
	Legolas->num_sec_h = buffer[36 + (j * 12) + z];
	Legolas->sec_h_str_index = buffer[38 + (j * 12) + z];
	close(fd);
	if (Legolas == NULL)
		dprintf(STDERR_FILENO, "Error: Cannot read from file\n"), exit(98);
}
