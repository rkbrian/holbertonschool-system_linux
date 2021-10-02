#ifndef SECHEAD_H
#define SECHEAD_H

#define EI_MAG0 0x7f
#define EI_MAG1 'E'
#define EI_MAG2 'L'
#define EI_MAG3 'F'
#define BUFFALO 64

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <elf.h>

/**
 * struct elf32_header - database for the elf header for 32-bit
 * @e_magic: varable 1, the sequence constitutes the ELF magic number
 * @e_class: varable 2, elf file class
 * @e_data: varable 3, elf file data
 * @e_version: varable 4,elf file version
 * @abi_name: varable 5, operation system API
 * @abi_v: varable 6, API version
 * @type: varable 7, type
 * @machine: varable 8, machine
 * @version: varable 9, elf file version
 * @entry_addrl: varable 10, entry point address for 32-bit
 * @start_pro_hl: varable 11, start of program headers 32-bit
 * @start_sec_hl: varable 12, start of section headers 32-bit
 * @flags: varable 13, flags
 * @size_h: varable 14, size of this header
 * @size_pro_h: varable 15, size of program headers
 * @num_pro_h: varable 16, number of program headers
 * @size_sec_h: varable 17, size of section headers
 * @num_sec_h: varable 18, number of section headers
 * @sec_h_str_index: varable 19, section header string table index
 */
typedef struct elf32_header
{
	uint8_t e_magic[4];
	uint8_t e_class;
	uint8_t e_data;
	uint8_t e_version;
	uint8_t abi_name;
	uint8_t abi_v[8]; /* 0: version; 1-7: EI_PAD */
	uint16_t type;
	uint16_t machine;
	uint32_t version;
	uint32_t entry_addrl;
	uint32_t start_pro_hl;
	uint32_t start_sec_hl;
	uint32_t flags;
	uint16_t size_eh;
	uint16_t size_pro_h;
	uint16_t num_pro_h;
	uint16_t size_sec_h;
	uint16_t num_sec_h;
	uint16_t sec_h_str_index;
} elf32_hdr;

/**
 * struct elf32_header - database for the elf header for 32-bit
 * @e_magic: varable 1, the sequence constitutes the ELF magic number
 * @e_class: varable 2, elf file class
 * @e_data: varable 3, elf file data
 * @e_version: varable 4,elf file version
 * @abi_name: varable 5, operation system API
 * @abi_v: varable 6, API version
 * @type: varable 7, type
 * @machine: varable 8, machine
 * @version: varable 9, elf file version
 * @entry_addrh: varable 10, entry point address 64-bit
 * @start_pro_hh: varable 11, start of program headers 64-bit
 * @start_sec_hh: varable 12, start of section headers 64-bit
 * @flags: varable 13, flags
 * @size_h: varable 14, size of this header
 * @size_pro_h: varable 15, size of program headers
 * @num_pro_h: varable 16, number of program headers
 * @size_sec_h: varable 17, size of section headers
 * @num_sec_h: varable 18, number of section headers
 * @sec_h_str_index: varable 19, section header string table index
 */
typedef struct elf64_header
{
	uint8_t e_magic[4];
	uint8_t e_class;
	uint8_t e_data;
	uint8_t e_version;
	uint8_t abi_name;
	uint8_t abi_v[8]; /* 0: version; 1-7: EI_PAD */
	uint16_t type;
	uint16_t machine;
	uint32_t version;
	uint32_t entry_addrh;
	uint32_t start_pro_hh;
	uint32_t start_sec_hh;
	uint32_t flags;
	uint16_t size_eh;
	uint16_t size_pro_h;
	uint16_t num_pro_h;
	uint16_t size_sec_h;
	uint16_t num_sec_h;
	uint16_t sec_h_str_index;
} elf64_hdr;

/**
 * struct abi_list - struct of abi name list
 * @id: id number of abi name
 * @abi_name: abi name
 */
typedef struct abi_list
{
	int id;
	char *abi_name;
} abyss;

/**
 * struct elf32_s_hdr - database for 32-bit elf section header
 * @sh_name: name of the section
 * @sh_type: type of the header
 * @sh_flags: attributes of the section
 * @sh_addr: virtual address of the section in memory
 * @sh_offset: offset of the section in the file image
 * @sh_size: size in bytes of the section in the file image
 * @sh_link: section index of an associated section
 * @sh_info: extra information about the section
 * @sh_addr_align: required alignment of the section
 * @sh_entsize: size in bytes of each entry
 */
typedef struct elf32_s_hdr
{
	uint32_t sh_name; /* byte size 4 */
	uint32_t sh_type; /* byte size 4 */
	uint32_t sh_flags; /* byte size 4 */
	uint32_t sh_addr; /* byte size 4 */
	uint32_t sh_offset; /* byte size 4 */
	uint32_t sh_size; /* byte size 4 */
	uint32_t sh_link; /* byte size 4 */
	uint32_t sh_info; /* byte size 4 */
	uint32_t sh_addr_align; /* byte size 4 */
	uint32_t sh_entsize; /* byte size 4 */
} elf32_sh;

/**
 * struct elf64_s_hdr - database for 64-bit elf section header
 * @sh_name: name of the section
 * @sh_type: type of the header
 * @sh_flags: attributes of the section
 * @sh_addr: virtual address of the section in memory
 * @sh_offset: offset of the section in the file image
 * @sh_size: size in bytes of the section in the file image
 * @sh_link: section index of an associated section
 * @sh_info: extra information about the section
 * @sh_addr_align: required alignment of the section
 * @sh_entsize: size in bytes of each entry
 */
typedef struct elf64_s_hdr
{
	uint32_t sh_name; /* byte size 4 */
	uint32_t sh_type; /* byte size 4 */
	uint64_t sh_flags; /* byte size 8 */
	uint64_t sh_addr; /* byte size 8 */
	uint64_t sh_offset; /* byte size 8 */
	uint64_t sh_size; /* byte size 8 */
	uint32_t sh_link; /* byte size 4 */
	uint32_t sh_info; /* byte size 4 */
	uint64_t sh_addr_align; /* byte size 8 */
	uint64_t sh_entsize; /* byte size 8 */
} elf64_sh;

/**
 * struct elf_header - database for the elf header, may not need this struct
 * @j: byte size flag, 1 for 32-bit, 2 for 64-bit
 * @e_magic: varable 1, the sequence constitutes the ELF magic number
 * @e_class: varable 2, elf file class
 * @e_data: varable 3, elf file data
 * @e_version: varable 4,elf file version
 * @abi_name: varable 5, operation system API
 * @abi_v: varable 6, API version
 * @type: varable 7, type
 * @machine: varable 8, machine
 * @version: varable 9, elf file version
 * @entry_addrl: varable 10, entry point address for 32-bit
 * @entry_addrh: varable 10, entry point address 64-bit
 * @start_pro_hl: varable 11, start of program headers 32-bit
 * @start_pro_hh: varable 11, start of program headers 64-bit
 * @start_sec_hl: varable 12, start of section headers 32-bit
 * @start_sec_hh: varable 12, start of section headers 64-bit
 * @flags: varable 13, flags
 * @size_h: varable 14, size of this header
 * @size_pro_h: varable 15, size of program headers
 * @num_pro_h: varable 16, number of program headers
 * @size_sec_h: varable 17, size of section headers
 * @num_sec_h: varable 18, number of section headers
 * @sec_h_str_index: varable 19, section header string table index
 */
typedef struct elf_header
{
	int j;
	uint8_t e_magic[16];
	int e_class;
	int e_data;
	int e_version;
	int abi_name;
	int abi_v;
	uint32_t type;
	uint32_t machine;
	uint32_t version;
	uint32_t *entry_addrl;
	uint64_t *entry_addrh;
	uint32_t *start_pro_hl;
	uint64_t *start_pro_hh;
	uint32_t *start_sec_hl;
	uint64_t *start_sec_hh;
	uint32_t flags;
	uint16_t size_eh;
	uint16_t size_pro_h;
	uint16_t num_pro_h;
	uint16_t size_sec_h;
	uint16_t num_sec_h;
	uint16_t sec_h_str_index;
} elf_hdr;

/* 1-hreadelf */
void create_saxon(elf32_hdr *myself, int endian, FILE *elf_file);
unsigned long int bitwise_swap(unsigned long int num, int bitsize);
elf32_sh *saxon_swap(elf32_sh *saxon);
/* section header print set 1 */
void print_saxon(elf32_hdr *elf_head, int endian, FILE *elf_file);
void print_shoff(elf32_hdr *elf_head);
int magic_check(elf32_hdr *elf_head);
void sec_flag(unsigned long int data);
char *typewriter(int type);

#endif /* SECHEAD_H */
