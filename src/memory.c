#include <memory.h>

void *memset(void *dest, char val, int count) {
    char *temp = (char *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}

void *memcpy(void *dest, const void *src, size_t count) {
    const char *sp = (const char *)src;
    char *dp = (char *)dest;
    for(; count != 0; count--) *dp++ = *sp++;
    return dest;
}

int memcmp(const void* str1, const void* str2, size_t count) {
    register const unsigned char *s1 = (const unsigned char*)str1;
    register const unsigned char *s2 = (const unsigned char*)str2;

    while (count-- > 0) {
        if (*s1++ != *s2++)
            return s1[-1] < s2[-1] ? -1 : 1;
    }
    return 0;
}

size_t getsize(void *p) {
    size_t * in = p;
    if (in) { --in; return *in; }
    return 0;
}
