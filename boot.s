[org 0x7C00]

; steup the stack
mov	bp, 0x9000
mov	sp, bp
; log the 16 bit mode
mov	bx, string_16bit_len
mov	cx, string_16bit
call	print_string
; switch to 32bit mode
call	switch_to_protected

loop:
	jmp loop

%include "print.s"
%include "print32.s"
%include "gdt.s"
%include "switch.s"

[bits 32]
protected_mode_start:

mov	eax, string_32bit_len
mov	ebx, string_32bit
call	print_string32

loop32:
	jmp loop32

string_16bit:		
	db	"16 bit mode init"
string_16bit_len equ		($ - string_16bit)

string_32bit:		
	db	"32 bit mode init"
string_32bit_len equ		($ - string_32bit)

; setup the magic number for BIOS
times	510 - ($ - $$)	db 0
dw	0xAA55
