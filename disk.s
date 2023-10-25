disk_load:
	push	dx
	mov	ah, 0x2 ; disk read
	mov	al, dh	; 
	mov	ch, 0x0 ; cylinder 0
	mov	dh, 0x0 ; head 0
	mov	cl, 0x2 ; 1st is boot sector, 2nd is free
	int	0x13	; disk interrupt
	jc	disk_error
	pop	dx
	cmp	dh, al
	jne	disk_error
	ret
disk_error:
	mov	bx, 10
	mov	cx, str_disk_error
	call	print_string

str_disk_error:
	db	"disk error"
