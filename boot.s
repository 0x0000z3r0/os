[org 0x7C00]

KERNEL_OFFSET equ	0x1000

; saving the disk drive
mov	[boot_drive], dl
; steup the stack
mov	bp, 0x9000
mov	sp, bp
; log the 16 bit mode
mov	bx, string_16bit_len
mov	cx, string_16bit
call	print_string
; load the kernel
call	kernel_load
; switch to 32bit mode
call	switch_to_protected

loop:
	jmp loop

%include "print.s"
%include "print32.s"
%include "gdt.s"
%include "switch.s"
%include "disk.s"

[bits 16]
kernel_load:
	mov	bx, KERNEL_OFFSET	; address pointer
	mov	dh, 15			; sector count (head)
	mov	dl, [boot_drive]	; drive handle
	call	disk_load
	ret

[bits 32]
protected_mode_start:
	; log the 32 bit mode
	mov	eax, string_32bit_len
	mov	ebx, string_32bit
	call	print_string32
	; call the kernel main
	call	KERNEL_OFFSET

loop32:
	jmp loop32

boot_drive:
	db	0

string_16bit:		
	db	"16 bit mode init"
string_16bit_len equ		($ - string_16bit)

string_32bit:		
	db	"32 bit mode init"
string_32bit_len equ		($ - string_32bit)

; setup the magic number for BIOS
times	510 - ($ - $$)	db 0
dw	0xAA55
