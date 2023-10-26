all: os.img
	qemu-system-x86_64 -fda $<

os.img: boot.bin kernel.bin
	cat $^ > $@

kernel.bin: entry.o kernel.o
	ld -m elf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

entry.o: entry.s
	nasm $< -f elf -o $@

kernel.o: kernel.c
	gcc -O2 -m32 -ffreestanding -c $< -o $@

boot.bin: boot.s
	nasm $< -f bin -o $@

clear:
	rm *.bin *.img *.o
