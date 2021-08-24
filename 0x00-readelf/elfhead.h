#ifndef ELFHEAD_H
#define ELFHEAD_H

#define EI_MAG0 0x7f
#define EI_MAG1 'E'
#define EI_MAG2 'L'
#define EI_MAG3 'F'
#define BUFFALO 32

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

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
 * @version: varable 9, elf file version
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
 * struct machine_list
 * @war_machine: machine names as many as Iron Man's armors
 */
struct machine_list
{
	abyss war_machine[82];
} default_machine = {{
	{0, "No machine"},
	{1, "AT&T WE 32100"},
	{2, "Sparc"},
	{3, "Intel 80386"},
	{4, "Motorola 68000"},
	{5, "Motorola 88000"}, /* 6 reserved */
	{7, "Intel 80860"},
	{8, "MIPS I Architecture"},
	{9, "IBM System/370 Processor"},
	{10, "MIPS RS3000 Little-endian"}, /* 11-14 reserved */
	{15, "Hewlett-Packard PA-RISC"}, /* 16 reserved */
	{17, "Fujitsu VPP500"},
	{18, "Enhanced instruction set Sparc"},
	{19, "Intel 80960"},
	{20, "PowerPC"},
	{21, "64-bit PowerPC"},
	{22, "IBM System/390 Processor"}, /* 23-35 reserved */
	{36, "NEC V800"},
	{37, "Fujitsu FR20"},
	{38, "TRW RH-32"},
	{39, "Motorola RCE"},
	{40, "Advanced RISC Machines ARM"},
	{41, "Digital Alpha"},
	{42, "Hitachi SH"},
	{43, "Sparc Version 9"},
	{44, "Siemens TriCore embedded processor"},
	{45, "Argonaut RISC Core, Argonaut Technologies Inc."},
	{46, "Hitachi H8/300"},
	{47, "Hitachi H8/300H"},
	{48, "Hitachi H8S"},
	{49, "Hitachi H8/500"},
	{50, "Intel IA-64 processor architecture"},
	{51, "Stanford MIPS-X"},
	{52, "Motorola ColdFire"},
	{53, "Motorola M68HC12"},
	{54, "Fujitsu MMA Multimedia Accelerator"},
	{55, "Siemens PCP"},
	{56, "Sony nCPU embedded RISC processor"},
	{57, "Denso NDR1 microprocessor"},
	{58, "Motorola Star*Core processor"},
	{59, "Toyota ME16 processor"},
	{60, "STMicroelectronics ST100 processor"},
	{61, "Advanced Logic Corp. TinyJ embedded processor family"},
	{62, "Advanced Micro Devices X86-64"},
	{63, "Sony DSP Processor"},
	{64, "Digital Equipment Corp. PDP-10"},
	{65, "Digital Equipment Corp. PDP-11"},
	{66, "Siemens FX66 microcontroller"},
	{67, "STMicroelectronics ST9+ 8/16 bit microcontroller"},
	{68, "STMicroelectronics ST7 8-bit microcontroller"},
	{69, "Motorola MC68HC16 Microcontroller"},
	{70, "Motorola MC68HC11 Microcontroller"},
	{71, "Motorola MC68HC08 Microcontroller"},
	{72, "Motorola MC68HC05 Microcontroller"},
	{73, "Silicon Graphics SVx"},
	{74, "STMicroelectronics ST19 8-bit microcontroller"},
	{75, "Digital VAX"},
	{76, "Axis Communications 32-bit embedded processor"},
	{77, "Infineon Technologies 32-bit embedded processor"},
	{78, "Element 14 64-bit DSP Processor"},
	{79, "LSI Logic 16-bit DSP Processor"},
	{80, "Donald Knuth's educational 64-bit processor"},
	{81, "Harvard University machine-independent object files"},
	{82, "SiTera Prism"},
	{83, "Atmel AVR 8-bit microcontroller"},
	{84, "Fujitsu FR30"},
	{85, "Mitsubishi D10V"},
	{86, "Mitsubishi D30V"},
	{87, "NEC v850"},
	{88, "Mitsubishi M32R"},
	{89, "Matsushita MN10300"},
	{90, "Matsushita MN10200"},
	{91, "picoJava"},
	{92, "OpenRISC 32-bit embedded processor"},
	{93, "ARC Cores Tangent-A5"},
	{94, "Tensilica Xtensa Architecture"},
	{95, "Alphamosaic VideoCore processor"},
	{96, "Thompson Multimedia General Purpose Processor"},
	{97, "National Semiconductor 32000 series"},
	{98, "Tenor Network TPC processor"},
	{99, "Trebia SNP 1000 processor"},
	{100, "STMicroelectronics ST200 microcontroller"}
	}}; /* Iron Man surely has lots of armors */
typedef struct machine_list iron_man;

/* Prototypes: 0-hreadelf */
void create_fileinfo(elf_hdr *Legolas, char *filename);
int magic_check(elf_hdr *elf_head);
/* print set 1 */
void print_head(elf_hdr *elf_head);
void print_h_magic16(elf_hdr *elf_head);
char *abi_list(elf_hdr *elf_head);
char *type_list(elf_hdr *elf_head);
/* print set 2 */






#endif /* ELFHEAD_H */
