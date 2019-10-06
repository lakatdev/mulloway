#ifndef MEMORY_H
#define MEMORY_H

#include <types.h>

typedef struct MemoryChunk MemoryChunk;

struct MemoryChunk{
    MemoryChunk *next;
    MemoryChunk *prev;
    bool allocated;
    size_t size;
};

void init_mem(size_t start, size_t size);
void* malloc(size_t size);
void free(void* ptr);
void *memset(void *dest, char val, int count);
void *memcpy(void *dest, const void *src, size_t count);
extern void memcpySSE(void *dest, const void *src, size_t count);
int memcmp(const void *const s1, const void const* s2, const size_t n);
void *realloc(void *ptr, size_t size);

#endif
