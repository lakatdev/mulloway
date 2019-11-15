#include <graphics.h>
#include <memory.h>
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

void flushBuffer(){
    memcpySSE(GraphicsBuffer, SecBuffer, BUFFER_SIZE);
}