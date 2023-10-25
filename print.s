; bx = size
; cx = pointer
print_string:
	mov	ah, 0x0E	; enable TTY
	push	dx
	xor	dx, dx
print_string_check:
	cmp	dx, bx
	je	print_string_exit
	push	bx
	mov	bx, cx
	mov	al, [bx]
	int	0x10
	pop	bx
	inc	dx
	inc	cx
	jmp	print_string_check
print_string_exit:
	pop	dx
	ret

; bx = number
print_hex:
	mov	ah, 0x0E	; enable TTY
	push	cx
	push	dx
	xor	dx, dx
print_hex_check:
	cmp	dx, 4
	je	print_hex_exit
	mov	cx, bx
	and	cx, 0xF000
	shr	cx, 12
	cmp	cx, 0xA
	jl	print_hex_decimal
print_hex_letter:
	sub	cl, 0xA
	mov	al, cl
	add	al, 'A'
	int	0x10
	inc	dx
	rol	bx, 4
	jmp	print_hex_check
print_hex_decimal:
	mov	al, cl
	add	al, '0'
	int	0x10
	inc	dx
	rol	bx, 4
	jmp	print_hex_check
print_hex_exit:
	pop	dx
	pop	cx
	ret
