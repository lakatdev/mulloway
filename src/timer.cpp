#include <com/timer.h>
#include <common/functions.h>

//inits system timer
SystemTimer::SystemTimer(InterruptManager* manager) : InterruptHandler(manager, 0x20),
	channelZeroPort(0x40),
	cmdregisterPort(0x43){	
	int divisor = 1193180;
	cmdregisterPort.Write(0x36);
	channelZeroPort.Write(divisor & 0xFF);
	channelZeroPort.Write(divisor >> 8);
}

SystemTimer::~SystemTimer(){
}

int timerTicks = 0;

//called every tick
uint32_t SystemTimer::HandleInterrupt(uint32_t esp){
	timerTicks++;
	if (timerTicks % 100 == 0){
	    timerTicks = 0;
	    common::increaseUptime();
	}
	return esp;
}

