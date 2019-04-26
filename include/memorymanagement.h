#ifndef MEMORYMANAGEMENT_H
#define MEMORYMANAGEMENT_H
 
#include <common/types.h>

struct MemoryChunk{
    MemoryChunk *next;
    MemoryChunk *prev;
    bool allocated;
    size_t size;
};


class MemoryManager{

protected:
    MemoryChunk* first;
public:

    static MemoryManager *activeMemoryManager;
    MemoryManager(size_t first, size_t size);
    ~MemoryManager();
    void* malloc(size_t size);
    void free(void* ptr);
};

void* operator new(unsigned size);
void* operator new[](unsigned size);

void* operator new(unsigned size, void* ptr);
void* operator new[](unsigned size, void* ptr);

void operator delete(void* ptr);
void operator delete[](void* ptr);

#endif
