#include "elfhead.h"

/**
 * print_head - function to print elf file header
 * @elf_head: struct database of the elf file
 */
void print_head(elf_hdr elf_head)
{
        int i;

        printf("  Magic:   ");
        for (i = 0; i < 16; i++)
                printf("%02x ", elf_head->e_magic[i]);
        printf("\n");
        print_h_class(elf_head);
        
}

/**
 * print_head - function to print elf file header
 * @elf_head: struct database of the elf file
 */
void print_h_class(elf_hdr elf_head)
{
        printf("  Class:                             ");
        if (elf_head->e_magic[4] == 1)
                printf("ELF32\n");
        else if (elf_head->e_magic[4] == 2)
                printf("ELF64\n");
        else if (elf_head->e_magic[4] == 0)
                printf("ELFNONE\n");
}