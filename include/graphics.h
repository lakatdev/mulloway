#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <types.h>

void init_grp(uint32_t addr);
void drawScreen(int color);
void putPixel(uint16_t x, uint16_t y, int color);
void drawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, int color);
void drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, int color);
void drawWideLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, int color, uint16_t w);
void drawCircle(uint16_t x0, uint16_t y0, uint16_t radius, uint8_t style, int color);
void drawWideCircle(uint16_t x0, uint16_t y0, uint16_t radius, uint8_t style, int color, int width);
void flushBuffer();

#endif