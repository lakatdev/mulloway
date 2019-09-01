#ifndef PORT_H
#define PORT_H

#include <types.h>

//read ports
static inline uint8_t readPort8(uint16_t _port){
    uint8_t result;
    __asm__ volatile("inb %1, %0" : "=a" (result) : "Nd" (_port));
    return result;
}

static inline uint16_t readPort16(uint16_t _port){
    uint16_t result;
    __asm__ volatile("inw %1, %0" : "=a" (result) : "Nd" (_port));
    return result;
}

static inline uint32_t readPort32(uint16_t _port){
    uint32_t result;
    __asm__ volatile("inl %1, %0" : "=a" (result) : "Nd" (_port));
    return result;
}

//write ports
static inline void writePort8(uint16_t _port, uint8_t _data){
    __asm__ volatile("outb %0, %1" : : "a" (_data), "Nd" (_port));
}

static inline void writePort8Slow(uint16_t _port, uint8_t _data){
    __asm__ volatile("outb %0, %1\njmp 1f\n1: jmp 1f\n1:" : : "a" (_data), "Nd" (_port));
}

static inline void writePort16(uint16_t _port, uint16_t _data){
    __asm__ volatile("outw %0, %1" : : "a" (_data), "Nd" (_port));
}

static inline void writePort32(uint16_t _port, uint32_t _data){
    __asm__ volatile("outl %0, %1" : : "a"(_data), "Nd" (_port));
}

#endif
