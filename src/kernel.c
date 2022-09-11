#include <types.h>
#include <port.h>
#include <memory.h>
#include <gdt.h>
#include <idt.h>
#include <mouse.h>
#include <graphics.h>

extern void enable_sse();

void printf(char* str){
    static uint16_t* video_memory = (uint16_t*)0xb8000;

    static uint8_t x=0,y=0;

    for(int i = 0; str[i] != '\0'; ++i){
        switch(str[i]){
            case '\n':
                x = 0;
                y++;
                break;
            case '\b':
                if (x <= 0)
                    break;
                x--;
                video_memory[80*y+x] = (video_memory[80*y+x] & 0xFF00) | '\0';
                break;
            default:
                video_memory[80*y+x] = (video_memory[80*y+x] & 0xFF00) | str[i];
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
                    video_memory[80*y+x] = (video_memory[80*y+x] & 0xFF00) | ' ';
            x = 0;
            y = 0;
        }
    }
}

void printf_hex(uint8_t key){
    char* foo = "00";
    char* hex = "0123456789ABCDEF";
    foo[0] = hex[(key >> 4) & 0xF];
    foo[1] = hex[key & 0xF];
    printf(foo);
}

void clean_buffer(){
    for (int i = 0; i < 2000; i++){
        printf(" ");
    }
}

void set_pit_freq(uint32_t divisor){
    write_port8(0x43, 0x36);
    write_port8(0x40, divisor & 0xFF);
    write_port8(0x40, divisor >> 8);
}

void graphics_update(){
    while(1){
        draw_screen(0x34A9CA);
        draw_cursor();
        flush_buffer();
        sleep(3);
    }
}

void kernel_main(const void* multiboot_structure){

    uint32_t* header = (uint32_t*)(((size_t)multiboot_structure) + 8);

    enable_sse();
    set_pit_freq(11931810);
    clean_buffer();
    printf("Starting MullowayOS 2.4\n");
    init_gdt();
    init_grp(header[20]);
    init_idt();
    init_mou();

    graphics_update();
}
