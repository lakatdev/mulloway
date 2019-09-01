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

#endif
