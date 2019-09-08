#ifndef TASKING_H
#define TASKING_H

#include <types.h>

#define STATE_READY 0
#define STATE_RUNNING 1
#define STATE_ZOMBIE 2
#define STATE_DEAD 3

typedef struct process{
	char *name;
	uint32_t pid;
	uint32_t esp;
	uint32_t stack;
	uint32_t eip;
	uint32_t cr3;
	bool notExecuted;
    uint8_t state;
	struct process *next, *prev;
} process;

void init_tsk();
process *createProcess(char *name,  uint32_t addr);
void addProcess(process *p);
void schedule();
bool taskingEnabled;
void exit();

#endif
