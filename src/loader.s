.set MAGIC, 0x1badb002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
    .long MAGIC
    .long FLAGS
    .long CHECKSUM
 
.section .text

.global _set_gdtr
.type _set_gdtr, @function
_set_gdtr:
    push %ebp
    movl %esp, %ebp

    lgdt 0x800

    movl %ebp, %esp
    pop %ebp
    ret

.global _reload_segments
.type _reload_segments, @function
_reload_segments:
    push %ebp
    movl %esp, %ebp

    push %eax
    mov $0x10, %ax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    mov %ax, %ss
    pop %eax

    ljmp $0x8, $me
me:
    movl %ebp, %esp
    pop %ebp
    ret

.extern kernelMain
.extern callConstructors
.global loader

loader:
    mov $kernel_stack, %esp
    call callConstructors
    push %eax
    push %ebx
    call kernelMain
    
_stop:
    cli
    hlt
    jmp _stop

.section .bss
.space 2*1024*1024; #2MiB
kernel_stack:
