# 0x01. x86 Assembly - libASM

## General
- The differences between Intel and AT&T syntaxes
- The different x86 GPR
- The different flag registers
- What is a stack frame
- How to setup a stack frame
- How to call a function
- How to make a system call
- How to pass parameters to a function
- How to retrieve parameters

## Compilation and usage examples
gcc -Wall -Wextra -Werror -pedantic -g3 -c -o 0-main.o 0-main.c
nasm -f elf64 -o 0-strlen.o 0-strlen.asm
gcc -o 0-strlen 0-main.o 0-strlen.o
./0-strlen

## 0. strlen
Write a copycat of the function strlen(3), in x86-64 Assembly
- Prototype when used in C: size_t asm_strlen(const char *str);

## 1. strcmp
Write a copycat of the function strcmp(3), in x86-64 Assembly
- Prototype when used in C: int asm_strcmp(const char *s1, const char *s2);

## 2. strncmp
Write a copycat of the function strncmp(3), in x86-64 Assembly
- Prototype when used in C: int asm_strncmp(const char *s1, const char *s2, size_t n);

## 3. strchr
Write a copycat of the function strchr(3), in x86-64 Assembly
- Prototype when used in C: char *asm_strchr(const char *s, int c);

## 4. strstr
Write a copycat of the function strstr(3), in x86-64 Assembly
- Prototype when used in C: char *asm_strstr(const char *haystack, const char *needle);

## 5. memcpy
Write a copycat of the function memcpy(3), in x86-64 Assembly
- Prototype when used in C: void *asm_memcpy(void *dest, const void *src, size_t n);

## 6. putc
Write a function that prints a single character on the standard output, in x86-64 Assembly
- Prototype when used in C: size_t asm_putc(int c);
- Where c holds the character to be printed
- Your function must return the total number of bytes written on the standard output
- For this task, you are allowed to use the syscall instruction only once in your file

## 7. puts
Write a function that prints a string of characters on the standard output, in x86-64 Assembly
- Prototype when used in C: size_t asm_puts(const char *str);
- Where str holds the string to be printed
- Your function must return the total number of bytes written on the standard output
- You are not allowed to use any sort of jump
- Your file 0-strlen.asm will be compiled as well, you are allowed to call it once in your file
- For this task, you are allowed to use the syscall instruction only once in your file
