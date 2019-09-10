#include <types.h>
#include <port.h>
#include <memory.h>
#include <gdt.h>
#include <idt.h>
#include <tasking.h>
#include <mouse.h>

void printf(char* str){
    static uint16_t* VideoMemory = (uint16_t*)0xb8000;

    static uint8_t x=0,y=0;

    for(int i = 0; str[i] != '\0'; ++i){
        switch(str[i]){
            case '\n':
                x = 0;
                y++;
                break;
            default:
                VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | str[i];
                x++;
                break;
        }
        if(x >= 80){
            x = 0;
            y++;
        }
        if(y >= 25){
            for(y = 0; y < 25; y++)
                for(x = 0; x < 80; x++)
                    VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | ' ';
            x = 0;
            y = 0;
        }
    }
}

void printfHex(uint8_t key){
    char* foo = "00";
    char* hex = "0123456789ABCDEF";
    foo[0] = hex[(key >> 4) & 0xF];
    foo[1] = hex[key & 0xF];
    printf(foo);
}

void cleanBuffer(){
    for (int i = 0; i < 2000; i++){
        printf(" ");
    }
}

void setPitFreq(uint32_t divisor){
    writePort8(0x43, 0x36);
    writePort8(0x40, divisor & 0xFF);
    writePort8(0x40, divisor >> 8);
}

typedef void (*constructor)();
constructor start_ctors;
constructor end_ctors;
void callConstructors(){
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}

void kernelMain(const void* multiboot_structure){

    uint32_t* memupper = (uint32_t*)(((size_t)multiboot_structure) + 8);
    size_t heap = 10*1024*1024;
    init_mem(heap, (*memupper)*1024 - heap - 10*1024);
    void* allocated = malloc(1024);

    setPitFreq(11931810);
    cleanBuffer();
    printf("Starting MullowayOS 2.2c\n");
    init_gdt();
    init_idt();
    init_mou();
    init_tsk();
}
