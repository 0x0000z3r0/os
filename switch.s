[bits 16]
switch_to_protected:
	cli			; clear interrupts
	lgdt	[gdt_desc]	; load GDT descriptor
	mov	eax, cr0
	or	eax, 0x1
	mov	cr0, eax	; enable the 32bit mode bit
	
	; far jump to flush the pipeline
	jmp	CODE_SEG:init_protected 

[bits 32]
init_protected:
	; re-init the cleard segment registers
	mov	ax, DATA_SEG
	mov	ds, ax
	mov	ss, ax
	mov	es, ax
	mov	fs, ax
	mov	gs, ax
	; setup the stack
	mov	ebp, 0x9000
	mov	esp, ebp
	; jump to kernel start
	call	protected_mode_start
