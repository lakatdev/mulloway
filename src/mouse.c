#include <mouse.h>
#include <port.h>
#include <graphics.h>

uint8_t mouse_cycle;
int8_t mouse_byte[3];
int8_t mouse_x, mouse_y;
uint16_t abs_x = 400;
uint16_t abs_y = 300;

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
void handle_mouse() {
    switch(mouse_cycle) {
        case 0:
            mouse_byte[0] = read_port8(0x60);
            mouse_cycle++;
            break;
        case 1:
            mouse_byte[1] = read_port8(0x60);
            mouse_cycle++;
            break;
        case 2:
            mouse_byte[2] = read_port8(0x60);
            mouse_x = mouse_byte[1];
            mouse_y = mouse_byte[2];
            mouse_cycle = 0;
            break;
    }
    abs_x += mouse_x;
    abs_y -= mouse_y;
}

void draw_cursor() {
    draw_mono(abs_x,abs_y,18,28,cursor_outline,0);
    draw_mono(abs_x,abs_y,18,28,cursor_back,0xFFFFFF);
}

void mouse_wait(uint8_t type) {
    uint32_t time_out = 100000;
    if(type == 0) {
        while(time_out--) {
            if((read_port8(0x64) & 1) == 1) {
                return;
            }
        }
        return;
}
    else{
        while(time_out--) {
            if((read_port8(0x64) & 2) == 0) {
                return;
            }
        }
        return;
    }
}

void mouse_write(uint8_t write) {
    //Wait to be able to send a command
    mouse_wait(1);
    //Tell the mouse we are sending a command
    write_port8(0x64, 0xD4);
    //Wait for the final part
    mouse_wait(1);
    //Finally write
    write_port8(0x60, write);
}

uint8_t mouse_read() {
    //Get's response from mouse
    mouse_wait(0);
    return read_port8(0x60);
}

void init_mou() {
    uint8_t status;

    //Enable the auxiliary mouse device
    mouse_wait(1);
    write_port8(0x64, 0xA8);

    //Tell the mouse to use default settings
    mouse_write(0xF6);
    mouse_read();  //Acknowledge
    
    //Enable the interrupts
    mouse_wait(1);
    write_port8(0x64, 0x20);
    mouse_wait(0);
    status = (read_port8(0x60) | 2);
    mouse_wait(1);
    write_port8(0x64, 0x60);
    mouse_wait(1);
    write_port8(0x60, status);

    //Enable the mouse
    mouse_write(0xF4);
    mouse_read();  //Acknowledge
    
    mouse_cycle = 0;
}
