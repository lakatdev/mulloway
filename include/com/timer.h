#ifndef TIMER_H
#define TIMER_H

#include <common/types.h>
#include <com/interrupts.h>
#include <com/port.h>

class SystemTimer : public InterruptHandler {
	Port8Bit channelZeroPort;
	Port8Bit cmdregisterPort;
		
	public:
		SystemTimer(InterruptManager* manager);
		~SystemTimer();
		virtual uint32_t HandleInterrupt(uint32_t esp);
};

#endif
