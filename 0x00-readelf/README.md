# 0x00. C - ELF: readelf
## General
### What is the ELF format
### What kind of files are in the ELF format
### What are the different parts that constitute an ELF file
### What information are present in the file header
### What information are present in the sections header table
### What information are present in the program header table
### How to parse an ELF file using C structures

## 0. ELF file header
Write a program that displays the information contained in the ELF file header of an ELF file.
- Usage: 0-hreadelf elf_filename
- Your standard output, error output and status should be the exact same as readelf -W -h
Your makefile must define the rule 0-hreadelf and compile the needed sources to form the executable 0-hreadelf

## 1. ELF sections' headers
Write a program that displays the information contained in the ELF sections' headers of an ELF file.
- Usage: 1-hreadelf elf_filename
- Your standard output, error output and status should be the exact same as readelf -W -S
Your makefile must define the rule 1-hreadelf and compile the needed sources to form the executable 1-hreadelf

## 2. ELF program headers
Write a program that displays the information contained in the ELF program headers of an ELF file.
- Usage: 2-hreadelf elf_filename
- Your standard output, error output and status should be the exact same as readelf -W -l
Your makefile must define the rule 2-hreadelf and compile the needed sources to form the executable 2-hreadelf