#include <memory.h>

MemoryChunk* first;

void init_mem(size_t start, size_t size){
    if (size < sizeof(MemoryChunk)){
        first = 0;
    }
    else{
        first = (MemoryChunk*)start;
        first -> allocated = false;
        first -> prev = 0;
        first -> next = 0;
        first -> size = size - sizeof(MemoryChunk);
    }
}

void* malloc(size_t size){
    MemoryChunk *result = 0;

    for(MemoryChunk* chunk = first; chunk != 0 && result == 0; chunk = chunk->next)
        if(chunk->size > size && !chunk->allocated)
            result = chunk;

    if(result == 0)
        return 0;

    if(result->size >= size + sizeof(MemoryChunk) + 1){
        MemoryChunk* temp = (MemoryChunk*)((size_t)result + sizeof(MemoryChunk) + size);

        temp->allocated = false;
        temp->size = result->size - size - sizeof(MemoryChunk);
        temp->prev = result;
        temp->next = result->next;
        if(temp->next != 0)
            temp->next->prev = temp;

        result->size = size;
        result->next = temp;
    }

    result->allocated = true;
    return (void*)(((size_t)result) + sizeof(MemoryChunk));
}

void free(void* ptr){
    MemoryChunk* chunk = (MemoryChunk*)((size_t)ptr - sizeof(MemoryChunk));

    chunk -> allocated = false;

    if(chunk->prev != 0 && !chunk->prev->allocated){
        chunk->prev->next = chunk->next;
        chunk->prev->size += chunk->size + sizeof(MemoryChunk);
        if(chunk->next != 0)
            chunk->next->prev = chunk->prev;

        chunk = chunk->prev;
    }

    if(chunk->next != 0 && !chunk->next->allocated){
        chunk->size += chunk->next->size + sizeof(MemoryChunk);
        chunk->next = chunk->next->next;
        if(chunk->next != 0)
            chunk->next->prev = chunk;
    }
}

void *memset(void *dest, char val, int count){
    char *temp = (char *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}