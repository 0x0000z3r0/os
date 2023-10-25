gdt_start:

gdt_null:
	dq	0x0

;
; +---------------------------------------------------------------------------------------------------------------+
; | Base(31:24)[31:24] | Granularty(23) | Default Operation Size(22) | 64bit Segment(21) | AVL(20) | Limit(19:16) |
; |---------------------------------------------------------------------------------------------------------------|
; | Present(15) | Privelege(14:13) | Descriptor(12) | Type(11:8) | Base(7:0)[23-16]                               |
; |---------------------------------------------------------------------------------------------------------------|
; | Base(31:16)[15:00]                                                                                            |                                                                       |
; |---------------------------------------------------------------------------------------------------------------|
; | Limit(15:00)[15:00]                                                                                           |
; +---------------------------------------------------------------------------------------------------------------+
;

; LIMIT:	0xFFFFF
; BASE:		0x00000000
; TYPE:		1010b => [code]1, [conforming]0, [readable]1, [accessed]0
; DESCRIPTOR:	1b => [code&data]1
; PRIVELEGE:	00b => [ring 0]0
; PRESENT:	1b => [present]1
; AVL:		0b => [unused]0
; 64BIT:	0b => [unused]0
; SIZE:		1b => [32bit]1
; GRANULARITY:	1b => [MUL4K]1
gdt_code:
	dw	0xFFFF		; limit 0:15
	dw	0x0000		; base 0:15
	db	0x00		; base 16:23
	db	10011010b	; type 8:11, descriptor 12, privelege 13:14, present 15
	db	11001111b	; limit 16:19, avl 20, 64bit 21, size 22, granularity 23
	db	0x00		; base 24:31
	
; LIMIT:	0xFFFFF
; BASE:		0x00000000
; TYPE:		0010b => [code]0, [conforming]0, [readable]1, [accessed]0
; DESCRIPTOR:	1b => [code&data]1
; PRIVELEGE:	00b => [ring 0]0
; PRESENT:	1b => [present]1
; AVL:		0b => [unused]0
; 64BIT:	0b => [unused]0
; SIZE:		1b => [32bit]1
; GRANULARITY:	1b => [MUL4K]1
gdt_data:
	dw	0xFFFF		; limit 0:15
	dw	0x0000		; base 0:15
	db	0x00		; base 16:23
	db	10010010b	; type 8:11, descriptor 12, privelege 13:14, present 15
	db	11001111b	; limit 16:19, avl 20, 64bit 21, size 22, granularity 23
	db	0x00		; base 24:31

gdt_end:

; GDT descriptor
gdt_desc:
	dw	gdt_end - gdt_start - 1	; size
	dd	gdt_start		; offset

CODE_SEG equ	gdt_code - gdt_start
DATA_SEG equ	gdt_data - gdt_start

