#ifndef LIBASM_H
#define LIBASM_H

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t asm_strlen(const char *str);
int asm_strcmp(const char *s1, const char *s2);
int asm_strncmp(const char *s1, const char *s2, size_t n);

#endif /* LIBASM_H */
