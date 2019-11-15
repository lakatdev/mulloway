#include <graphics.h>
#include <memory.h>
#include <math.h>
#include <ubuntu-mono.h>

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

void flushBuffer(){
    memcpySSE(GraphicsBuffer, SecBuffer, BUFFER_SIZE);
}