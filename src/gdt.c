#include <gdt.h>

static uint32_t gdtPointer = 0;
static uint32_t  gdtSize = 0;
static uint32_t gdtrLoc = 0;

static uint32_t highpart = 0;
static uint32_t lowpart = 0;

void printf(char*);
extern void _set_gdtr();
extern void _reload_segments();

void init_gdt(){
	gdtPointer = 0x806; // start GDT data at 4MB
	gdtrLoc =    0x800;
	gdtAddDescriptor(0, 0);
	gdtAddDescriptor(1, 0x00CF9A000000FFFF);
	gdtAddDescriptor(2, 0x00CF92000000FFFF);
	gdtAddDescriptor(3, 0x008FFA000000FFFF); // 16bit code pl3
	gdtSetDescriptor(4, 0x008FF2000000FFFF); // 16bit data pl3
	printf("Global Descriptor Table is alive.\n");
}

int gdtSetDescriptor(){
	/* GDTR
	 * 0-1 = SIZE - 1
	 * 2-5 = OFFSET
	 */
	*(uint16_t*)gdtrLoc = (gdtSize - 1) & 0x0000FFFF;
	gdtrLoc += 2;
	*(uint32_t*)gdtrLoc = gdtPointer;
	_set_gdtr();
	printf("GDTR was set\n");
	_reload_segments();
	printf("Segments reloaded\n");
	return 0;
}

int gdtAddDescriptor(uint8_t id, uint64_t desc){
	uint32_t loc = gdtPointer + sizeof(uint64_t)*id;
	*(uint64_t*)loc = desc;
	printf("Added GDT entry\n");
	gdtSize += sizeof(desc);
	return 0;
}

uint64_t gdtCreateDescriptor(uint32_t base, uint32_t limit, uint16_t flag){
	uint64_t desc = 0;
	highpart = 0;
	lowpart = 0;
	desc = limit 		& 0x000F0000;
	desc |= (flag << 8) 	& 0x00F0FF00;
	desc |= (base >> 16) 	& 0x000000FF;
	desc |= base		& 0xFF000000;
	
	highpart = desc;
	desc <<= 32;

	desc |= base << 16;
	desc |= limit		& 0x0000FFFF;
	lowpart = (uint32_t)desc;
	return desc;
}
