#ifndef TASKING_H
#define TASKING_H

#include <types.h>

#define STATE_READY 0
#define STATE_RUNNING 1
#define STATE_ZOMBIE 2
#define STATE_DEAD 3

#define PRIORITY_VERYLOW 1
#define PRIORITY_LOW 5
#define PRIORITY_NORMAL 10
#define PRIORITY_HIGH 15
#define PRIORITY_VERYHIGH 20

typedef struct process{
    char *name;
    uint32_t pid;
    uint32_t esp;
    uint32_t stack;
    uint32_t eip;
    uint32_t cr3;
    bool notExecuted;
    uint8_t state;
    uint8_t priority;
    struct process *next, *prev;
} process;

void init_tsk();
process *createProcess(char *name,  uint32_t addr, uint8_t priority);
void addProcess(process *p);
void schedule();
void execute_scheduler();
bool taskingEnabled;
uint8_t getCurrentPriority();
void exit();

#endif
