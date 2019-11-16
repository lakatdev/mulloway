#include <graphics.h>
#include <memory.h>
#include <math.h>
#include <ubuntu-mono.h>

void printf(char*);

#define BITGET(var, pos) (((var) & (1 << pos)))
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define SCREEN_SIZE 786432
#define BUFFER_SIZE 3145728
#define BUFFER_PITCH 4096
#define BUFFER_PITCH_BITS 12

static uint8_t* GraphicsBuffer;
static uint8_t* SecBuffer;

void init_grp(uint32_t addr){
    printf("Initializing VESA graphics");
    GraphicsBuffer = (uint8_t*)addr;
    SecBuffer = (uint8_t*)malloc(BUFFER_SIZE);
}

void drawScreen(int color){
    for (int i = 0; i < SCREEN_SIZE; i++){
        uint32_t address = i << 2;
        SecBuffer[address] = color & 255;              // BLUE
        SecBuffer[address + 1] = (color >> 8) & 255;   // GREEN
        SecBuffer[address + 2] = (color >> 16) & 255;  // RED
    }
}

void putPixel(uint16_t x, uint16_t y, int color){
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) return;
    uint32_t offset = (x << 2) + (y << BUFFER_PITCH_BITS);
    SecBuffer[offset] = color & 255;              // BLUE
    SecBuffer[offset + 1] = (color >> 8) & 255;   // GREEN
    SecBuffer[offset + 2] = (color >> 16) & 255;  // RED
}

void drawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, int color){
    for(int x1 = 0; x1 < w; x1++){
        for(int y1 = 0; y1 < h; y1++){
            putPixel(x1 + x, y1 + y, color);
        }
    }
}

void drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, int color){
    int i,dx,dy,sdx,sdy,dxabs,dyabs,x,y,px,py;

    dx = x2 - x1; //the horizontal distance of the line
    dy = y2 - y1; //the vertical distance of the line
    dxabs = abs(dx);
    dyabs = abs(dy);
    sdx = sgn(dx);
    sdy = sgn(dy);
    x = dyabs >> 1;
    y = dxabs >> 1;
    px = x1;
    py = y1;

    putPixel(px,py,color);
    if (dxabs >= dyabs){ //more horizontal
        for(i = 0; i < dxabs; i++){
            y += dyabs;
            if (y >= dxabs){
                y -= dxabs;
                py += sdy;
            }
            px += sdx;
            putPixel(px,py,color);
        }
    }
    else{ //more vertical
        for(i = 0; i < dyabs; i++){
            x += dxabs;
            if (x >= dyabs){
                x -= dyabs;
                px += sdx;
            }
            py += sdy;
            putPixel(px,py,color);
        }
    }
}

void drawWideLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, int color, uint16_t w){
    int dxabs, dyabs, start, end;

    dxabs = abs(x2 - x1);
    dyabs = abs(y2 - y1);

    start = (w >> 1) - w + 1;
    end = w - abs(start);

    if (dxabs >= dyabs){
        for (int i = start; i < end; i++){
            drawLine(x1,y1+i,x2,y2+i,color);
        }
    }
    else{
        for (int i = start; i < end; i++){
            drawLine(x1+i,y1,x2+i,y2,color);
        }
    }
}

void drawCircle(uint16_t x0, uint16_t y0, uint16_t radius, uint8_t style, int color){
    int x = radius;
    int y = 0;
    int err = 0;
 
    while (x >= y){
        if (style == 0 || style == 1 || style == 5 || style == 8 || style == 9 || style == 11 || style == 12){
            putPixel(x0 + y, y0 - x, color); //1
            putPixel(x0 + x, y0 - y, color);
        }
        if (style == 0 || style == 2 || style == 5 || style == 6 || style == 9 || style == 10 || style == 12){
            putPixel(x0 + x, y0 + y, color); //2
            putPixel(x0 + y, y0 + x, color);
        }
        if (style == 0 || style == 3 || style == 6 || style == 7 || style == 9 || style == 10 || style == 11){
            putPixel(x0 - y, y0 + x, color); //3
            putPixel(x0 - x, y0 + y, color);
        }
        if (style == 0 || style == 4 || style == 7 || style == 8 || style == 10 || style == 11 || style == 12){
            putPixel(x0 - x, y0 - y, color); //4
            putPixel(x0 - y, y0 - x, color);
        }

        if (err <= 0){
            y += 1;
            err += 2*y + 1;
        }
    
        if (err > 0){
            x -= 1;
            err -= 2*x + 1;
        }
    }

}

void drawWideCircle(uint16_t x0, uint16_t y0, uint16_t radius, uint8_t style, int color, int width){
    for (int i = radius; i < radius + width; i++){
        drawCircle(x0, y0, i, style, color);
    }
}

void drawMono8(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t* data, int color){
    int h = y;
    int w = x;
    for (int i = 0; i < width * height; i++){
        int j = 7 - (i % 8);
        if (BITGET(data[i >> 3], j)){
            putPixel(w, h, color);
        }
        w++;
        if (w >= width + x){
            h++;
            w = x;
        }
    }
}

void drawChar(uint16_t x, uint16_t y, int color, uint8_t* data){
    int h = y;
    int w = x;
    for (int i = 0; i < (data[0] << 3); i++){
        int j = 7 - (i % 8);
        if (BITGET(data[(i >> 3) + 3], j)){
            putPixel(w, h, color);
        }
        w++;
        if (w >= data[1] + x){
            h--;
            w = x;
        }
    }
}

uint8_t codesAscii[128] = {
    0,0,0,0,0,0,0,0,108,109,107,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,106,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,64,65,66,67,
    68,69,70,71,72,73,89,90,91,92,93,94,95,32,33,34,36,37,38,39,41,43,
    44,46,47,48,49,50,51,52,53,54,56,57,59,60,61,62,63,96,98,97,99,100,
    101,0,1,2,4,5,6,7,9,11,12,14,15,16,17,18,19,20,21,22,24,25,27,28,
    29,30,31,102,103,104,105,0
};

void renderChar(uint8_t code, uint16_t px, uint16_t py, uint8_t size, int color){
    int pos = 0;

    /*check if selected size is available*/
    for (int  i = 0; i < ubuntu_mono_v2_mfp[0]; i++){
        if (ubuntu_mono_v2_mfp[i + 2] == size){
            pos = i;
            break;
        }
        if (i == ubuntu_mono_v2_mfp[0] - 1)
            return;
    }

    /*set up a cursor*/
    uint32_t cursor = ubuntu_mono_v2_mfp[0] + 2;

    /*get to the start of the selected size*/
    for (int i = 0; i < pos * 106; i++){
        cursor += ubuntu_mono_v2_mfp[cursor] + 3;
    }

    /*get to the selected character*/
    for (int i = 0; i < code; i++){
        cursor += ubuntu_mono_v2_mfp[cursor] + 3;
    }

    int absSize = ubuntu_mono_v2_mfp[cursor] + 3;
    uint8_t* data = malloc(absSize);
    memcpy(data, &ubuntu_mono_v2_mfp[cursor], absSize);

    /*move characters to the middle of their given space*/
    px += ((size / 2) - data[1]) / 2;

    /*get vertical placement of the character*/
    switch(data[2]){
        case 1:{
            py += size * 0.16;
            break;
        }
        case 2:{
            py -= size / 3;
            break;
        }
        case 3:{
            py -= size / 10;
            break;
        }
    }

    drawChar(px, py, color, data);
    free(data);
}

void drawString(char* str, uint16_t px, uint16_t py, uint8_t size, int color){
    for (int i = 0; str[i] != '\0'; i++){
        if (codesAscii[str[i]] == 106){
            px += size / 2;
            continue;
        }
        renderChar(codesAscii[str[i]], px, py, size, color);
        px += size / 2;
    }
}

void flushBuffer(){
    memcpySSE(GraphicsBuffer, SecBuffer, BUFFER_SIZE);
}