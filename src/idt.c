#include <idt.h>
#include <keyboard.h>
#include <mouse.h>
#include <port.h>

void printf(char*);

idt_descriptor idt[256];

void init_idt() {

    printf("Initializing interrupt descriptor table\n");
    extern int32_t load_idt();
    extern int32_t irq0();
    extern int32_t irq1();
    extern int32_t irq2();
    extern int32_t irq3();
    extern int32_t irq4();
    extern int32_t irq5();
    extern int32_t irq6();
    extern int32_t irq7();
    extern int32_t irq8();
    extern int32_t irq9();
    extern int32_t irq10();
    extern int32_t irq11();
    extern int32_t irq12();
    extern int32_t irq13();
    extern int32_t irq14();
    extern int32_t irq15();

    uint32_t irq0_address;
    uint32_t irq1_address;
    uint32_t irq2_address;
    uint32_t irq3_address;
    uint32_t irq4_address;
    uint32_t irq5_address;
    uint32_t irq6_address;
    uint32_t irq7_address;
    uint32_t irq8_address;
    uint32_t irq9_address;
    uint32_t irq10_address;
    uint32_t irq11_address;
    uint32_t irq12_address;
    uint32_t irq13_address;
    uint32_t irq14_address;
    uint32_t irq15_address;
    uint32_t idt_address;
    uint32_t idt_ptr[2];

    printf("Remapping PIC\n");
    /* remapping the PIC */
    write_port8(0x20, 0x11);
    write_port8(0xA0, 0x11);
    write_port8(0x21, 0x20);
    write_port8(0xA1, 40);
    write_port8(0x21, 0x04);
    write_port8(0xA1, 0x02);
    write_port8(0x21, 0x01);
    write_port8(0xA1, 0x01);
    write_port8(0x21, 0x0);
    write_port8(0xA1, 0x0);

    irq0_address = (uint32_t)irq0;
    idt[32].offset_lowerbits = irq0_address & 0xffff;
    idt[32].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[32].zero = 0;
    idt[32].type_attr = 0x8e; /* INTERRUPT_GATE */
    idt[32].offset_higherbits = (irq0_address & 0xffff0000) >> 16;

    irq1_address = (uint32_t)irq1;
    idt[33].offset_lowerbits = irq1_address & 0xffff;
    idt[33].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[33].zero = 0;
    idt[33].type_attr = 0x8e; /* INTERRUPT_GATE */
    idt[33].offset_higherbits = (irq1_address & 0xffff0000) >> 16;

    irq2_address = (uint32_t)irq2;
    idt[34].offset_lowerbits = irq2_address & 0xffff;
    idt[34].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[34].zero = 0;
    idt[34].type_attr = 0x8e; /* INTERRUPT_GATE */
    idt[34].offset_higherbits = (irq2_address & 0xffff0000) >> 16;

    irq3_address = (uint32_t)irq3;
    idt[35].offset_lowerbits = irq3_address & 0xffff;
    idt[35].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[35].zero = 0;
    idt[35].type_attr = 0x8e; /* INTERRUPT_GATE */
    idt[35].offset_higherbits = (irq3_address & 0xffff0000) >> 16;

    irq4_address = (uint32_t)irq4;
    idt[36].offset_lowerbits = irq4_address & 0xffff;
    idt[36].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[36].zero = 0;
    idt[36].type_attr = 0x8e; /* INTERRUPT_GATE */
    idt[36].offset_higherbits = (irq4_address & 0xffff0000) >> 16;

    irq5_address = (uint32_t)irq5;
    idt[37].offset_lowerbits = irq5_address & 0xffff;
    idt[37].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[37].zero = 0;
    idt[37].type_attr = 0x8e; /* INTERRUPT_GATE */
    idt[37].offset_higherbits = (irq5_address & 0xffff0000) >> 16;

    irq6_address = (uint32_t)irq6;
    idt[38].offset_lowerbits = irq6_address & 0xffff;
    idt[38].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[38].zero = 0;
    idt[38].type_attr = 0x8e; /* INTERRUPT_GATE */
    idt[38].offset_higherbits = (irq6_address & 0xffff0000) >> 16;

    irq7_address = (uint32_t)irq7;
    idt[39].offset_lowerbits = irq7_address & 0xffff;
    idt[39].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[39].zero = 0;
    idt[39].type_attr = 0x8e; /* INTERRUPT_GATE */
    idt[39].offset_higherbits = (irq7_address & 0xffff0000) >> 16;

    irq8_address = (uint32_t)irq8;
    idt[40].offset_lowerbits = irq8_address & 0xffff;
    idt[40].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[40].zero = 0;
    idt[40].type_attr = 0x8e; /* INTERRUPT_GATE */
    idt[40].offset_higherbits = (irq8_address & 0xffff0000) >> 16;

    irq9_address = (uint32_t)irq9;
    idt[41].offset_lowerbits = irq9_address & 0xffff;
    idt[41].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[41].zero = 0;
    idt[41].type_attr = 0x8e; /* INTERRUPT_GATE */
    idt[41].offset_higherbits = (irq9_address & 0xffff0000) >> 16;

    irq10_address = (uint32_t)irq10;
    idt[42].offset_lowerbits = irq10_address & 0xffff;
    idt[42].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[42].zero = 0;
    idt[42].type_attr = 0x8e; /* INTERRUPT_GATE */
    idt[42].offset_higherbits = (irq10_address & 0xffff0000) >> 16;

    irq11_address = (uint32_t)irq11;
    idt[43].offset_lowerbits = irq11_address & 0xffff;
    idt[43].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[43].zero = 0;
    idt[43].type_attr = 0x8e; /* INTERRUPT_GATE */
    idt[43].offset_higherbits = (irq11_address & 0xffff0000) >> 16;

    irq12_address = (uint32_t)irq12;
    idt[44].offset_lowerbits = irq12_address & 0xffff;
    idt[44].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[44].zero = 0;
    idt[44].type_attr = 0x8e; /* INTERRUPT_GATE */
    idt[44].offset_higherbits = (irq12_address & 0xffff0000) >> 16;

    irq13_address = (uint32_t)irq13;
    idt[45].offset_lowerbits = irq13_address & 0xffff;
    idt[45].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[45].zero = 0;
    idt[45].type_attr = 0x8e; /* INTERRUPT_GATE */
    idt[45].offset_higherbits = (irq13_address & 0xffff0000) >> 16;

    irq14_address = (uint32_t)irq14;
    idt[46].offset_lowerbits = irq14_address & 0xffff;
    idt[46].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[46].zero = 0;
    idt[46].type_attr = 0x8e; /* INTERRUPT_GATE */
    idt[46].offset_higherbits = (irq14_address & 0xffff0000) >> 16;

    irq15_address = (uint32_t)irq15;
    idt[47].offset_lowerbits = irq15_address & 0xffff;
    idt[47].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[47].zero = 0;
    idt[47].type_attr = 0x8e; /* INTERRUPT_GATE */
    idt[47].offset_higherbits = (irq15_address & 0xffff0000) >> 16;

    /* fill the idt descriptor */
    idt_address = (uint32_t)idt ;
    idt_ptr[0] = (sizeof (idt_descriptor) * 256) + ((idt_address & 0xffff) << 16);
    idt_ptr[1] = idt_address >> 16;

    printf("Loading IDT");
    load_idt(idt_ptr);
    printf (" [DONE]\n");
}

uint64_t timer_ticks = 0;
void sleep(uint64_t ticks) {
    timer_ticks = ticks;
    while (timer_ticks > 0);
}

void irq0_handler(void) {
    if (timer_ticks > 0) {
        timer_ticks--;
    }
    write_port8(0x20, 0x20); //EOI
}

void irq1_handler(void) {
    handle_keypress(read_port8(0x60));
    write_port8(0x20, 0x20); //EOI
}

void irq2_handler(void) {
    write_port8(0x20, 0x20); //EOI
}

void irq3_handler(void) {
    write_port8(0x20, 0x20); //EOI
}

void irq4_handler(void) {
    write_port8(0x20, 0x20); //EOI
}

void irq5_handler(void) {
    write_port8(0x20, 0x20); //EOI
}

void irq6_handler(void) {
    write_port8(0x20, 0x20); //EOI
}

void irq7_handler(void) {
    write_port8(0x20, 0x20); //EOI
}

void irq8_handler(void) {
    write_port8(0xA0, 0x20);
    write_port8(0x20, 0x20); //EOI
}

void irq9_handler(void) {
    write_port8(0xA0, 0x20);
    write_port8(0x20, 0x20); //EOI
}

void irq10_handler(void) {
    write_port8(0xA0, 0x20);
    write_port8(0x20, 0x20); //EOI
}

void irq11_handler(void) {
    write_port8(0xA0, 0x20);
    write_port8(0x20, 0x20); //EOI
}

void irq12_handler(void) {
    handle_mouse();
    write_port8(0xA0, 0x20);
    write_port8(0x20, 0x20); //EOI
}

void irq13_handler(void) {
    write_port8(0xA0, 0x20);
    write_port8(0x20, 0x20); //EOI
}

void irq14_handler(void) {
    write_port8(0xA0, 0x20);
    write_port8(0x20, 0x20); //EOI
}

void irq15_handler(void) {
    write_port8(0xA0, 0x20);
    write_port8(0x20, 0x20); //EOI
}
