#include <rtc.h>
#include <port.h>

uint8_t get_year() {
    write_port8(0x70, 0x09);
    return read_port8(0x71);
}

uint8_t get_month() {
    write_port8(0x70, 0x08);
    return read_port8(0x71);
}

uint8_t get_day() {
    write_port8(0x70, 0x07);
    return read_port8(0x71);
}

uint8_t get_weekday() {
    write_port8(0x70, 0x06);
    return read_port8(0x71);
}

uint8_t get_hour() {
    write_port8(0x70, 0x04);
    return read_port8(0x71);
}

uint8_t get_minute() {
    write_port8(0x70, 0x02);
    return read_port8(0x71);
}

uint8_t get_second() {
    write_port8(0x70, 0x00);
    return read_port8(0x71);
}
