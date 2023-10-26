all: os.img
	qemu-system-x86_64 -fda $<

debug-build: os.img
	qemu-system-x86_64 -s -fda $<

debug-start: kernel.dbg
	gdb -ex "target remote localhost:1234" -ex "symbol-file kernel.dbg"

kernel.dbg: entry.o kernel.o
	ld -m elf_i386 -o $@ -Ttext 0x1000 $^

os.img: boot.bin kernel.bin
	cat $^ > $@

kernel.bin: entry.o kernel.o screen.o port.o
	ld -m elf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

entry.o: entry.s
	nasm $< -f elf -o $@

kernel.o: kernel.c
	gcc -Wall -Wextra -g -Og -fno-pie -m32 -ffreestanding -c $< -o $@

port.o: port.c
	gcc -Wall -Wextra -g -Og -fno-pie -m32 -ffreestanding -c $< -o $@

screen.o: screen.c
	gcc -Wall -Wextra -g -Og -fno-pie -m32 -ffreestanding -c $< -o $@

boot.bin: boot.s
	nasm $< -f bin -o $@

clear:
	rm *.bin *.img *.o *.dbg 
