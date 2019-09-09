#include <rtc.h>
#include <port.h>

uint8_t getYear(){
    writePort8(0x70, 0x09);
    return readPort8(0x71);
}

uint8_t getMonth(){
    writePort8(0x70, 0x08);
    return readPort8(0x71);
}

uint8_t getDay(){
    writePort8(0x70, 0x07);
    return readPort8(0x71);
}

uint8_t getWeekday(){
    writePort8(0x70, 0x06);
    return readPort8(0x71);
}

uint8_t getHour(){
    writePort8(0x70, 0x04);
    return readPort8(0x71);
}

uint8_t getMinute(){
    writePort8(0x70, 0x02);
    return readPort8(0x71);
}

uint8_t getSecond(){
    writePort8(0x70, 0x00);
    return readPort8(0x71);
}
