GPPPARAMS = -m32 -Iinclude -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings
ASPARAMS = --32
LDPARAMS = -melf_i386

objects = obj/loader.o \
		obj/kernel.o \
		obj/gdt.o \
		obj/port.o \
		obj/interruptstubs.o \
		obj/memorymanagement.o \
		obj/timer.o \
		obj/interrupts.o \
		obj/keyboard.o \
		obj/vga.o \
		obj/programs.o \
		obj/functions.o \
		obj/multitasking.o

obj/%.o: src/%.cpp
	mkdir -p $(@D)
	gcc $(GPPPARAMS) -c -o $@ $<
	
obj/%.o: src/%.s
	mkdir -p $(@D)
	as $(ASPARAMS) -o $@ $<
	
build: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp build iso/boot/build
	echo 'set timeout=0'					  > iso/boot/grub/grub.cfg
	echo 'set default=0'					 >> iso/boot/grub/grub.cfg
	echo ''								  >> iso/boot/grub/grub.cfg
	echo 'menuentry "Mulloway" {' >> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/build'	>> iso/boot/grub/grub.cfg
	echo '  boot'							>> iso/boot/grub/grub.cfg
	echo '}'								 >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=mulloway.iso iso
	rm -rf iso
run:
	qemu-system-i386 mulloway.iso

clean:
	rm -rf obj build mulloway.iso
