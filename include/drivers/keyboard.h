#ifndef KEYBOARD_H
#define KEYBOARD_H

    #include <common/types.h>
    #include <com/interrupts.h>
    #include <com/port.h>

    class KeyboardDriver : public InterruptHandler {
        Port8Bit dataport;
        Port8Bit commandport;
    public:
        KeyboardDriver(InterruptManager* manager);
        ~KeyboardDriver();
        virtual uint32_t HandleInterrupt(uint32_t esp);
    };

#endif
