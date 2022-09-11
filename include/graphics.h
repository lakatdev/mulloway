#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <types.h>

void init_grp(uint32_t addr);
void draw_screen(int color);
void put_pixel(uint16_t x, uint16_t y, int color);
void draw_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, int color);
void draw_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, int color);
void draw_wide_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, int color, uint16_t w);
void draw_circle(uint16_t x0, uint16_t y0, uint16_t radius, uint8_t style, int color);
void draw_wide_circle(uint16_t x0, uint16_t y0, uint16_t radius, uint8_t style, int color, int width);
void draw_mono(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t* data, int color);
void draw_char(uint16_t x, uint16_t y, int color, uint8_t* data);
void render_char(uint8_t code, uint16_t px, uint16_t py, uint8_t size, int color);
void draw_string(char* str, uint16_t px, uint16_t py, uint8_t size, int color);
void flush_buffer();

#endif