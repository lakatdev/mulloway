#ifndef MEMORY_H
#define MEMORY_H

#include <types.h>

void *memset(void *dest, char val, int count);
void *memcpy(void *dest, const void *src, size_t count);
extern void memcpy_sse(void *dest, const void *src, size_t count);
int memcmp(const void* str1, const void* str2, size_t count);
#endif
