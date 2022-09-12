#ifndef PORT_H
#define PORT_H

#include <types.h>

//read ports
static inline uint8_t read_port8(uint16_t _port) {
    uint8_t result;
    __asm__ volatile("inb %1, %0" : "=a" (result) : "Nd" (_port));
    return result;
}

static inline uint16_t read_port16(uint16_t _port) {
    uint16_t result;
    __asm__ volatile("inw %1, %0" : "=a" (result) : "Nd" (_port));
    return result;
}

static inline uint32_t read_port32(uint16_t _port) {
    uint32_t result;
    __asm__ volatile("inl %1, %0" : "=a" (result) : "Nd" (_port));
    return result;
}

//write ports
static inline void write_port8(uint16_t _port, uint8_t _data) {
    __asm__ volatile("outb %0, %1" : : "a" (_data), "Nd" (_port));
}

static inline void write_port8_slow(uint16_t _port, uint8_t _data) {
    __asm__ volatile("outb %0, %1\njmp 1f\n1: jmp 1f\n1:" : : "a" (_data), "Nd" (_port));
}

static inline void write_port16(uint16_t _port, uint16_t _data) {
    __asm__ volatile("outw %0, %1" : : "a" (_data), "Nd" (_port));
}

static inline void write_port32(uint16_t _port, uint32_t _data) {
    __asm__ volatile("outl %0, %1" : : "a"(_data), "Nd" (_port));
}

#endif
