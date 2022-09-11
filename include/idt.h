#ifndef IDT_H
#define IDT_H

#include <types.h>

typedef struct {
    uint16_t offset_lowerbits;
    uint16_t selector;
    uint8_t zero;
    uint8_t type_attr;
    uint16_t offset_higherbits;
} __attribute__((packed)) idt_descriptor;

void init_idt();
void sleep(uint64_t ticks);

#endif
