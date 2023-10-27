DATA_SEG equ	0x10

[extern isr_hnd]
isr_stub:
	; push all registers & the current data segement selector
	pusha		
	mov	ax, ds	
	push	eax
	; load kernel data segment selector
	mov	ax, DATA_SEG
	mov	ds, ax
	mov	es, ax
	mov	fs, ax
	mov	gs, ax
	; call the handler
	call	isr_hnd
	; load the original data segement selector
	pop	eax
	mov	ds, ax
	mov	es, ax
	mov	fs, ax
	mov	gs, ax
	; pop all registers
	popa
	; clean up the push error code (by CPU) and isr number (by us)
	add	esp, 8
	; enable interrupts
	sti
	; return from the interrupt, which pop cs, eip, eflags, ss, and esp
	iret

[extern irq_hnd]
irq_stub:
	; push all registers & the current data segement selector
	pusha		
	mov	ax, ds	
	push	eax
	; load kernel data segment selector
	mov	ax, DATA_SEG
	mov	ds, ax
	mov	es, ax
	mov	fs, ax
	mov	gs, ax
	; call the handler
	call	irq_hnd
	; load the original data segement selector
	pop	eax
	mov	ds, ax
	mov	es, ax
	mov	fs, ax
	mov	gs, ax
	; pop all registers
	popa
	; clean up the push error code (by CPU) and isr number (by us)
	add	esp, 8
	; enable interrupts
	sti
	; return from the interrupt, which pop cs, eip, eflags, ss, and esp
	iret
	

; isrs
global isr0
global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15
global isr16
global isr17
global isr18
global isr19
global isr20
global isr21
global isr22
global isr23
global isr24
global isr25
global isr26
global isr27
global isr28
global isr29
global isr30
global isr31
; irqs
global irq0
global irq1
global irq2
global irq3
global irq4
global irq5
global irq6
global irq7
global irq8
global irq9
global irq10
global irq11
global irq12
global irq13
global irq14
global irq15

; ===== generic handling =====
; 1. push the error code (optional for some ISRs)
; 2. push the iterrupt number
; 3. jump to the stub

isr0:
	cli
	push	byte 0
	push	byte 0
	jmp	isr_stub

isr1:
	push	byte 0
	push	byte 1
	jmp	isr_stub

isr2:
	push	byte 0
	push	byte 2
	jmp	isr_stub

isr3:
	push	byte 0
	push	byte 3
	jmp	isr_stub

isr4:
	push	byte 0
	push	byte 4
	jmp	isr_stub

isr5:
	push	byte 0
	push	byte 5
	jmp	isr_stub

isr6:
	push	byte 0
	push	byte 6
	jmp	isr_stub

isr7:
	push	byte 0
	push	byte 7
	jmp	isr_stub

isr8:
	push	byte 8
	jmp	isr_stub

isr9:
	push	byte 9
	jmp	isr_stub

isr10:
	push	byte 10
	jmp	isr_stub

isr11:
    	push	byte 11
    	jmp	isr_stub

isr12:
    	push	byte 12
    	jmp	isr_stub

isr13:
	push	byte 13
	jmp	isr_stub

isr14:
	push	byte 14
	jmp	isr_stub

isr15:
	push	byte 0
	push	byte 15
	jmp	isr_stub

isr16:
	push	byte 0
	push	byte 16
	jmp	isr_stub

isr17:
	push	byte 0
	push	byte 17
	jmp	isr_stub

isr18:
	push	byte 0
	push	byte 18
	jmp	isr_stub

isr19:
	push	byte 0
	push	byte 19
	jmp	isr_stub

isr20:
	push	byte 0
	push	byte 20
	jmp	isr_stub

isr21:
	push	byte 0
	push	byte 21
	jmp	isr_stub

isr22:
	push	byte 0
	push	byte 22
	jmp	isr_stub

isr23:
	push	byte 0
	push	byte 23
	jmp	isr_stub

isr24:
	push	byte 0
	push	byte 24
	jmp	isr_stub

isr25:
	push	byte 0
	push	byte 25
	jmp	isr_stub

isr26:
	push	byte 0
	push	byte 26
	jmp	isr_stub

isr27:
	push	byte 0
	push	byte 27
	jmp	isr_stub

isr28:
	push	byte 0
	push	byte 28
	jmp	isr_stub

isr29:
	push	byte 0
	push	byte 29
	jmp	isr_stub

isr30:
	push	byte 0
	push	byte 30
	jmp	isr_stub

isr31:
	push	byte 0
	push	byte 31
	jmp	isr_stub

; === IRQ ===
irq0:
	push	byte 0
	push	byte 32
	jmp	irq_stub

irq1:
	push	byte 1
	push	byte 33
	jmp	irq_stub

irq2:
	push	byte 2
	push	byte 34
	jmp	irq_stub

irq3:
	push	byte 3
	push	byte 35
	jmp	irq_stub

irq4:
	push	byte 4
	push	byte 36
	jmp	irq_stub

irq5:
	push	byte 5
	push	byte 37
	jmp	irq_stub

irq6:
	push	byte 6
	push	byte 38
	jmp	irq_stub

irq7:
	push	byte 7
	push	byte 39
	jmp	irq_stub

irq8:
	push	byte 8
	push	byte 40
	jmp	irq_stub

irq9:
	push	byte 9
	push	byte 41
	jmp	irq_stub

irq10:
	push	byte 10
	push	byte 42
	jmp	irq_stub

irq11:
	push	byte 11
	push	byte 43
	jmp	irq_stub

irq12:
	push	byte 12
	push	byte 44
	jmp	irq_stub

irq13:
	push	byte 13
	push	byte 45
	jmp	irq_stub

irq14:
	push	byte 14
	push	byte 46
	jmp	irq_stub

irq15:
	push	byte 15
	push	byte 47
	jmp	irq_stub
