[bits 32]

VIDEO_MEMORY		equ 0xB8000
VIDEO_COLS		equ 80
VIDEO_ROWS		equ 32
VIDEO_WHITE_BLACK	equ 0x0F

; eax = size
; ebx = pointer
print_string32:
	push	edi
	push	edx
	push	ecx
	mov	edi, VIDEO_MEMORY	; video memory iterator
	xor	ecx, ecx		; byte counter
print_string32_check:
	cmp	ecx, eax
	je	print_string32_exit

	mov	dl, [ebx]
	mov	dh, VIDEO_WHITE_BLACK
	mov	[edi], dx

	inc	ecx
	inc	ebx
	add	edi, 2
	jmp	print_string32_check
print_string32_exit:
	pop	ecx
	pop	edx
	pop	edi
	ret
