#include <idt.h>
#include <keyboard.h>
#include <mouse.h>

void printf(char*);

idtDescriptor idt[256];

void init_idt(){

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
    writePort8(0x20, 0x11);
    writePort8(0xA0, 0x11);
    writePort8(0x21, 0x20);
    writePort8(0xA1, 40);
    writePort8(0x21, 0x04);
    writePort8(0xA1, 0x02);
    writePort8(0x21, 0x01);
    writePort8(0xA1, 0x01);
    writePort8(0x21, 0x0);
    writePort8(0xA1, 0x0);
 
    irq0_address = (uint32_t)irq0; 
    idt[32].offsetLowerbits = irq0_address & 0xffff;
    idt[32].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[32].zero = 0;
    idt[32].typeAttr = 0x8e; /* INTERRUPT_GATE */
    idt[32].offsetHigherbits = (irq0_address & 0xffff0000) >> 16;
 
    irq1_address = (uint32_t)irq1; 
    idt[33].offsetLowerbits = irq1_address & 0xffff;
    idt[33].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[33].zero = 0;
    idt[33].typeAttr = 0x8e; /* INTERRUPT_GATE */
    idt[33].offsetHigherbits = (irq1_address & 0xffff0000) >> 16;
 
    irq2_address = (uint32_t)irq2; 
    idt[34].offsetLowerbits = irq2_address & 0xffff;
    idt[34].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[34].zero = 0;
    idt[34].typeAttr = 0x8e; /* INTERRUPT_GATE */
    idt[34].offsetHigherbits = (irq2_address & 0xffff0000) >> 16;
 
    irq3_address = (uint32_t)irq3; 
    idt[35].offsetLowerbits = irq3_address & 0xffff;
    idt[35].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[35].zero = 0;
    idt[35].typeAttr = 0x8e; /* INTERRUPT_GATE */
    idt[35].offsetHigherbits = (irq3_address & 0xffff0000) >> 16;
 
    irq4_address = (uint32_t)irq4; 
    idt[36].offsetLowerbits = irq4_address & 0xffff;
    idt[36].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[36].zero = 0;
    idt[36].typeAttr = 0x8e; /* INTERRUPT_GATE */
    idt[36].offsetHigherbits = (irq4_address & 0xffff0000) >> 16;
 
    irq5_address = (uint32_t)irq5; 
    idt[37].offsetLowerbits = irq5_address & 0xffff;
    idt[37].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[37].zero = 0;
    idt[37].typeAttr = 0x8e; /* INTERRUPT_GATE */
    idt[37].offsetHigherbits = (irq5_address & 0xffff0000) >> 16;
 
    irq6_address = (uint32_t)irq6; 
    idt[38].offsetLowerbits = irq6_address & 0xffff;
    idt[38].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[38].zero = 0;
    idt[38].typeAttr = 0x8e; /* INTERRUPT_GATE */
    idt[38].offsetHigherbits = (irq6_address & 0xffff0000) >> 16;
 
    irq7_address = (uint32_t)irq7; 
    idt[39].offsetLowerbits = irq7_address & 0xffff;
    idt[39].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[39].zero = 0;
    idt[39].typeAttr = 0x8e; /* INTERRUPT_GATE */
    idt[39].offsetHigherbits = (irq7_address & 0xffff0000) >> 16;
 
    irq8_address = (uint32_t)irq8; 
    idt[40].offsetLowerbits = irq8_address & 0xffff;
    idt[40].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[40].zero = 0;
    idt[40].typeAttr = 0x8e; /* INTERRUPT_GATE */
    idt[40].offsetHigherbits = (irq8_address & 0xffff0000) >> 16;
 
    irq9_address = (uint32_t)irq9; 
    idt[41].offsetLowerbits = irq9_address & 0xffff;
    idt[41].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[41].zero = 0;
    idt[41].typeAttr = 0x8e; /* INTERRUPT_GATE */
    idt[41].offsetHigherbits = (irq9_address & 0xffff0000) >> 16;
 
    irq10_address = (uint32_t)irq10; 
    idt[42].offsetLowerbits = irq10_address & 0xffff;
    idt[42].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[42].zero = 0;
    idt[42].typeAttr = 0x8e; /* INTERRUPT_GATE */
    idt[42].offsetHigherbits = (irq10_address & 0xffff0000) >> 16;
 
    irq11_address = (uint32_t)irq11; 
    idt[43].offsetLowerbits = irq11_address & 0xffff;
    idt[43].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[43].zero = 0;
    idt[43].typeAttr = 0x8e; /* INTERRUPT_GATE */
    idt[43].offsetHigherbits = (irq11_address & 0xffff0000) >> 16;
 
    irq12_address = (uint32_t)irq12; 
    idt[44].offsetLowerbits = irq12_address & 0xffff;
    idt[44].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[44].zero = 0;
    idt[44].typeAttr = 0x8e; /* INTERRUPT_GATE */
    idt[44].offsetHigherbits = (irq12_address & 0xffff0000) >> 16;
 
    irq13_address = (uint32_t)irq13; 
    idt[45].offsetLowerbits = irq13_address & 0xffff;
    idt[45].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[45].zero = 0;
    idt[45].typeAttr = 0x8e; /* INTERRUPT_GATE */
    idt[45].offsetHigherbits = (irq13_address & 0xffff0000) >> 16;
 
    irq14_address = (uint32_t)irq14; 
    idt[46].offsetLowerbits = irq14_address & 0xffff;
    idt[46].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[46].zero = 0;
    idt[46].typeAttr = 0x8e; /* INTERRUPT_GATE */
    idt[46].offsetHigherbits = (irq14_address & 0xffff0000) >> 16;
 
    irq15_address = (uint32_t)irq15; 
    idt[47].offsetLowerbits = irq15_address & 0xffff;
    idt[47].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    idt[47].zero = 0;
    idt[47].typeAttr = 0x8e; /* INTERRUPT_GATE */
    idt[47].offsetHigherbits = (irq15_address & 0xffff0000) >> 16;
 
    /* fill the idt descriptor */
    idt_address = (uint32_t)idt ;
    idt_ptr[0] = (sizeof (idtDescriptor) * 256) + ((idt_address & 0xffff) << 16);
    idt_ptr[1] = idt_address >> 16;

    printf("Loading IDT");
    load_idt(idt_ptr);
    printf (" [DONE]\n");
}

void irq0_handler(void) {
    writePort8(0x20, 0x20); //EOI
}
 
void irq1_handler(void) {
    handleKeypress(readPort8(0x60));
    writePort8(0x20, 0x20); //EOI
}
 
void irq2_handler(void) {
    writePort8(0x20, 0x20); //EOI
}
 
void irq3_handler(void) {
    writePort8(0x20, 0x20); //EOI
}
 
void irq4_handler(void) {
    writePort8(0x20, 0x20); //EOI
}
 
void irq5_handler(void) {
    writePort8(0x20, 0x20); //EOI
}
 
void irq6_handler(void) {
    writePort8(0x20, 0x20); //EOI
}
 
void irq7_handler(void) {
    writePort8(0x20, 0x20); //EOI
}
 
void irq8_handler(void) {
    writePort8(0xA0, 0x20);
    writePort8(0x20, 0x20); //EOI          
}
 
void irq9_handler(void) {
    writePort8(0xA0, 0x20);
    writePort8(0x20, 0x20); //EOI
}
 
void irq10_handler(void) {
    writePort8(0xA0, 0x20);
    writePort8(0x20, 0x20); //EOI
}
 
void irq11_handler(void) {
    writePort8(0xA0, 0x20);
    writePort8(0x20, 0x20); //EOI
}

void irq12_handler(void) {
    handleMouse();
    writePort8(0xA0, 0x20);
    writePort8(0x20, 0x20); //EOI
}
 
void irq13_handler(void) {
    writePort8(0xA0, 0x20);
    writePort8(0x20, 0x20); //EOI
}
 
void irq14_handler(void) {
    writePort8(0xA0, 0x20);
    writePort8(0x20, 0x20); //EOI
}
 
void irq15_handler(void) {
    writePort8(0xA0, 0x20);
    writePort8(0x20, 0x20); //EOI
}
