#ifndef ELFHEAD_H
#define ELFHEAD_H

#define EI_MAG0 0x7F
#define EI_MAG1 'E'
#define EI_MAG2 'L'
#define EI_MAG3 'F'
#define BUFFALO 32

/**
 * struct elf_header - database for the elf header
 * @e_magic: varable 1, the sequence constitutes the ELF magic number
 * @e_class: varable 2, elf file class
 * @e_data: varable 3, elf file data
 * @e_version: varable 4,elf file version
 * @abi_name: varable 5, operation system API
 * @abi_v: varable 6, API version
 * @type: varable 7, type
 * @machine: varable 8, machine
 * @version: varable 9, looks like elf file version in another form
 * @entry_addr: varable 10, entry point address
 * @start_pro_h: varable 11, start of program headers
 * @start_sec_h: varable 12, start of section headers
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
	uint8_t e_magic[16];
	int e_class;
	int e_data;
	int e_version;
	int abi_name;
	int abi_v;
	uint32_t type;
	uint32_t machine;
	uint32_t version;
	uint32_t entry_addr[4];
	uint32_t start_pro_h;
	uint32_t start_sec_h;
	uint32_t flags;
	uint16_t size_h;
	uint16_t size_pro_h;
	uint16_t num_pro_h;
	uint16_t size_sec_h;
	uint16_t num_sec_h;
	uint16_t sec_h_str_index;
} elf_hdr;

enum elf_id
{
	EI_MAG0 = 0, /* 0x7F */
	EI_MAG1 = 1, /* 'E' */
	EI_MAG2 = 2, /* 'L' */
	EI_MAG3 = 3, /* 'F' */
	EI_CLASS = 4, /* Architecture (32/64) */
	EI_DATA = 5, /* Byte order */
	EI_VERSION = 6, /* ELF version */
	EI_OSABI = 7, /* OS property */
	EI_ABIVERSION = 8, /* OS property */
	EI_PAD = 9  /* Padding */
}

elf_hdr create_fileinfo(char *filename);

#endif /* ELFHEAD_H */
