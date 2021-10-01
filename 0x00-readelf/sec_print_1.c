#include "sechead.h"

/**
 * print_saxon - function to print elf file section header
 * @elf_head: struct database of the elf file
 * @endian: struct database of the elf section file
 * @elf_file: elf file
 */
void print_saxon(elf32_hdr *elf_head, int endian, FILE *elf_file)
{
        int nsh; /*i, j*/

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
 * print_shoff - print the address of the start of section headers
 * @elf_head: struct database of the elf file
 */
void print_shoff(elf32_hdr *elf_head)
{
	/*int i, j = 0, end_i, k;

        if (elf_head->e_data == 1) /* little endian, digit position reverse */
                /*i = (4 * elf_head->e_class) - 1, end_i = -1, k = -1;
        else if (elf_head->e_data == 2) /* big endian, digit position in order */
                /*i = 0, end_i = 4 * elf_head->e_class, k = 1;
        while (i != end_i)
        {
                if (j > 0)
                        printf("%02x", elf_head->start_sec_hl[i]), j++;
                else if (elf_head->start_sec_hl[i] != 0)
                        printf("%x", elf_head->start_sec_hl[i]), j++;
                i = i + k;
		}*/
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
