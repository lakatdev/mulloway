#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <types.h>

void init_grp(uint32_t addr);
void drawScreen(int color);
void putPixel(uint16_t x, uint16_t y, int color);
void flushBuffer();

#endif