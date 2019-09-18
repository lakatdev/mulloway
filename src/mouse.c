#include <mouse.h>

uint8_t mouseCycle;
int8_t mouseByte[3];
int8_t mouseX, mouseY;

//Mouse functions
void handleMouse(){
    switch(mouseCycle){
        case 0:
            mouseByte[0] = readPort8(0x60);
            mouseCycle++;
            break;
        case 1:
            mouseByte[1] = readPort8(0x60);
            mouseCycle++;
            break;
        case 2:
            mouseByte[2] = readPort8(0x60);
            mouseX = mouseByte[1];
            mouseY = mouseByte[2];
            mouseCycle = 0;
            break;
    }
}

void mouseWait(uint8_t type){
    uint32_t timeOut = 100000;
    if(type == 0){
        while(timeOut--){
            if((readPort8(0x64) & 1) == 1){
                return;
            }
        }
        return;
}
    else{
        while(timeOut--){
            if((readPort8(0x64) & 2) == 0){
                return;
            }
        }
        return;
    }
}

void mouseWrite(uint8_t write){
    //Wait to be able to send a command
    mouseWait(1);
    //Tell the mouse we are sending a command
    writePort8(0x64, 0xD4);
    //Wait for the final part
    mouseWait(1);
    //Finally write
    writePort8(0x60, write);
}

uint8_t mouseRead(){
    //Get's response from mouse
    mouseWait(0);
    return readPort8(0x60);
}

void init_mou(){
    uint8_t status;

    //Enable the auxiliary mouse device
    mouseWait(1);
    writePort8(0x64, 0xA8);

    //Tell the mouse to use default settings
    mouseWrite(0xF6);
    mouseRead();  //Acknowledge
    
    //Enable the interrupts
    mouseWait(1);
    writePort8(0x64, 0x20);
    mouseWait(0);
    status = (readPort8(0x60) | 2);
    mouseWait(1);
    writePort8(0x64, 0x60);
    mouseWait(1);
    writePort8(0x60, status);

    //Enable the mouse
    mouseWrite(0xF4);
    mouseRead();  //Acknowledge
    
    mouseCycle = 0;
}
