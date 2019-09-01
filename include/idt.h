#ifndef IDT_H
#define IDT_H

#include <types.h>
#include <port.h>

typedef struct {
    uint16_t offsetLowerbits;
	uint16_t selector;
	uint8_t zero;
	uint8_t typeAttr;
    uint16_t offsetHigherbits;
} __attribute__((packed)) idtDescriptor;

void init_idt();

#endif
