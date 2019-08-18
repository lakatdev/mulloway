#include <common/types.h>
#include <gdt.h>
#include <drivers/keyboard.h>
#include <com/interrupts.h>
#include <common/functions.h>
#include <memorymanagement.h>
#include <common/programs.h>
#include <com/timer.h>
#include <common/multithreading.h>

static char currentLine[80]; 

void clear(string option){
    static uint16_t* VideoMemory = (uint16_t*)0xb8000;
    static uint8_t x=0,y=5;
    
    if (option == "comline"){
        for(x = 0; x < 80; x++){
            VideoMemory[80*3+x] = (VideoMemory[80*3+x] & common::colorDef) | '\0';
        }
    }
    else if (option == "playground") {
        for (y = 5; y < 25; y++){
            for(x = 0; x < 80; x++){
                VideoMemory[80*y+x] = (VideoMemory[80*y+x] & common::colorDef) | '\0';
            }
        }
    }
}

void printf(string str){
    static uint16_t* VideoMemory = (uint16_t*)0xb8000;
    static uint8_t x=0,y=3;

    for(int i = 0; str[i] != '\0'; ++i) {
            switch(str[i]){
            case '\n':
                clear("comline");   
                handleInput(currentLine);
		        for(int j = 0; currentLine[j] != '\0'; ++j) {
		            currentLine[j] = '\0';
		        }
                x = 0;
                break;
            case '\b':
                if (x > 0){
                    x--;
                    VideoMemory[80*y+x] = (VideoMemory[80*y+x] & common::colorDef) | '\0';
                    currentLine[x] = '\0';
                    break;
                }
                break;
            default:
                if (x < 79){
                    VideoMemory[80*y+x] = (VideoMemory[80*y+x] & common::colorDef) | str[i];
                    currentLine[x] = str[i];
                    x++;
                }
                break;
        }
    }
}

void init(){
    clear("comline");
    clear("playground");
    exit();
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors(){
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}

extern "C" void kernelMain(const void* multiboot_structure, uint32_t /*multiboot_magic*/){
    GlobalDescriptorTable gdt;
    
    uint32_t* memupper = (uint32_t*)(((size_t)multiboot_structure) + 8);
    size_t heap = 10*1024*1024;
    MemoryManager memoryManager(heap, (*memupper)*1024 - heap - 10*1024);
    void* allocated = memoryManager.malloc(1024);

    TaskManager taskManager;
    Task taskInit(&gdt, init);
    taskManager.AddTask(&taskInit);

    InterruptManager interrupts(0x20, &gdt, &taskManager);
    KeyboardDriver keyboard(&interrupts);
    SystemTimer timer(&interrupts);
    interrupts.Activate();

    while(1);
}


