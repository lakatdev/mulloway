#include <mouse.h>
#include <port.h>
#include <graphics.h>

uint8_t mouseCycle;
int8_t mouseByte[3];
int8_t mouseX, mouseY;
uint16_t absX = 400;
uint16_t absY = 300;

uint8_t cursor_outline[63] = {
    0xc0, 0x00, 0x38, 0x00, 0x0f, 0x00, 0x03, 0xe0, 0x00, 0xdc, 0x00, 0x33,
    0x80, 0x0c, 0x70, 0x03, 0x0e, 0x00, 0xc1, 0xc0, 0x30, 0x38, 0x0c, 0x07,
    0x03, 0x00, 0xe0, 0xc0, 0x1c, 0x30, 0x03, 0x8c, 0x00, 0x73, 0x00, 0x1c,
    0xc0, 0x3f, 0x31, 0x9f, 0x8c, 0xe6, 0x03, 0x78, 0xc0, 0xfb, 0x30, 0x3c,
    0xc6, 0x0c, 0x19, 0xc0, 0x06, 0x30, 0x00, 0x8c, 0x00, 0x37, 0x00, 0x0f,
    0x80, 0x01, 0x80
};

uint8_t cursor_back[63] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x0c,
    0x00, 0x03, 0x80, 0x00, 0xf0, 0x00, 0x3e, 0x00, 0x0f, 0xc0, 0x03, 0xf8,
    0x00, 0xff, 0x00, 0x3f, 0xe0, 0x0f, 0xfc, 0x03, 0xff, 0x80, 0xff, 0xe0,
    0x3f, 0xc0, 0x0e, 0x60, 0x03, 0x18, 0x00, 0x87, 0x00, 0x00, 0xc0, 0x00,
    0x38, 0x00, 0x06, 0x00, 0x01, 0xc0, 0x00, 0x70, 0x00, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00
};

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
    absX += mouseX;
    absY -= mouseY;
}

void drawCursor(){
    drawMono8(absX,absY,18,28,cursor_outline,0);
    drawMono8(absX,absY,18,28,cursor_back,0xFFFFFF);
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
