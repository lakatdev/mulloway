#include <tasking.h>
#include <memory.h>

void printf(char*);

uint32_t lpid = 0;
process *current;
process *kernel;

void exit(){
    current->state = STATE_ZOMBIE;
    while(1);
}

void taskCleaner(){
    taskingEnabled = true;
    process *p = current;
    while(1){
        p = p->next;
        if (p->state == STATE_ZOMBIE){
            taskingEnabled = false;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free((void *)p->stack);
            free(p);
            taskingEnabled = true;
        }
    }
}

uint8_t getCurrentPriority(){
    return current->priority;
}

process *createProcess(char *name, uint32_t addr, uint8_t priority){
    process *p = malloc(sizeof(process));
    memset(p,0,sizeof(process));

    p->name = name;
    p->state = STATE_READY;
    p->pid = ++lpid;
    p->eip = addr;
    p->esp = (uint32_t) malloc(4096);
    p->notExecuted = true;
    p->priority = priority;
    asm volatile("mov %%cr3, %%eax":"=a"(p->cr3));
    uint32_t *stack = (uint32_t *)(p->esp + 4096);
    p->stack = p->esp;

    //pushing registers on to the stack
    *--stack = 0x202; // eflags
    *--stack = 0x8; // cs
    *--stack = addr; // eip
    *--stack = 0; // eax
    *--stack = 0; // ebx
    *--stack = 0; // ecx;
    *--stack = 0; //edx
    *--stack = 0; //esi
    *--stack = 0; //edi
    *--stack = p->esp + 4096; //ebp
    *--stack = 0x10; // ds
    *--stack = 0x10; // fs
    *--stack = 0x10; // es
    *--stack = 0x10; // gs

    p->esp = (uint32_t)stack;
    return p;
}

void execute(){
    current->notExecuted = false;
    asm volatile("mov %%eax, %%esp": :"a"(current->esp));
    asm volatile("pop %gs");
    asm volatile("pop %fs");
    asm volatile("pop %es");
    asm volatile("pop %ds");
    asm volatile("out %%al, %%dx": :"d"(0x20), "a"(0x20));
    asm volatile("pop %ebp");
    asm volatile("pop %edi");
    asm volatile("pop %esi");
    asm volatile("pop %edx");
    asm volatile("pop %ecx");
    asm volatile("pop %ebx");
    asm volatile("pop %eax");
    asm volatile("iret");
}

void init_tsk(){
    printf("Starting multitasking service\n");
    kernel = createProcess("cleaner-service", (uint32_t)taskCleaner, PRIORITY_VERYLOW);
    kernel->next = kernel;
    kernel->prev = kernel;
    current = kernel;
    execute();
    printf("FATAL ERROR: couldn't start multitasking\n");
}

void addProcess(process *p){
    bool en = taskingEnabled;
    taskingEnabled = false;
    p->next = current->next;
    p->next->prev = p;
    p->prev = current;
    current->next = p;
    p->state = STATE_RUNNING;
    taskingEnabled = en;
}

void schedule(){
    //push current tasks' registers to it's stack
    asm volatile("push %eax");
    asm volatile("push %ebx");
    asm volatile("push %ecx");
    asm volatile("push %edx");
    asm volatile("push %esi");
    asm volatile("push %edi");
    asm volatile("push %ebp");
    asm volatile("push %ds");
    asm volatile("push %es");
    asm volatile("push %fs");
    asm volatile("push %gs");
    asm volatile("mov %%esp, %%eax":"=a"(current->esp));
    current = current->next;
    if(current->notExecuted){
        execute();
        return;
    }
    //pop registers of new task
    asm volatile("mov %%eax, %%cr3": :"a"(current->cr3));
    asm volatile("mov %%eax, %%esp": :"a"(current->esp));
    asm volatile("pop %gs");
    asm volatile("pop %fs");
    asm volatile("pop %es");
    asm volatile("pop %ds");
    asm volatile("pop %ebp");
    asm volatile("pop %edi");
    asm volatile("pop %esi");
    asm volatile("pop %edx");
    asm volatile("pop %ecx");
    asm volatile("pop %ebx");
    asm volatile("pop %eax");
}
