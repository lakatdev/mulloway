#ifndef GDT_H
#define GDT_H

#include <types.h>

#define GDT_ACCESSED	0x01
#define GDT_READWRITE	0x02
#define GDT_DIRECTION	0x04
#define GDT_EXEC	0x08
#define GDT_STATIC	0x10
#define GDT_PRESENT	0x20

extern void init_gdt();
extern int gdtSetDescriptor();
extern int gdtAddDescriptor(uint8_t id, uint64_t desc);
extern uint64_t gdtCreateDescriptor(uint32_t base, uint32_t limit, uint16_t flag);

#endif
