#ifndef _ISR_H_
#define _ISR_H_

#include "types.h"

typedef struct {
	u32	ds;
	u32	edi;
	u32	esi;
	u32	ebp;
	u32	esp;
	u32	ebx;
	u32	edx;
	u32	ecx;
	u32	eax;
	u32	num;
	u32	err;
	u32	eip;
	u32	cs;
	u32	eflags;
	u32	usr_esp;
	u32	ss;
} isr_regs;

typedef void (*irq_func)(isr_regs);

// PIC remmaped values
#define IRQ0	32
#define IRQ1	33
#define IRQ2	34
#define IRQ3	35
#define IRQ4	36
#define IRQ5	37
#define IRQ6	38
#define IRQ7	39
#define IRQ8	40
#define IRQ9	41
#define IRQ10	42
#define IRQ11	43
#define IRQ12	44
#define IRQ13	45
#define IRQ14	46
#define IRQ15	47

#define IRQ_MASTER_OFF	IRQ0
#define IRQ_SLAVE_OFF	IRQ8

void
isr_init(void);

void
isr_hnd(isr_regs);

void
irq_hnd(isr_regs);

void
irq_reg(u32, irq_func);

// default ISRs
extern void
isr0();

extern void
isr1();

extern void
isr2();

extern void
isr3();

extern void
isr4();

extern void
isr5();

extern void
isr6();

extern void
isr7();

extern void
isr8();

extern void
isr9();

extern void
isr10();

extern void
isr11();

extern void
isr12();

extern void
isr13();

extern void
isr14();

extern void
isr15();

extern void
isr16();

extern void
isr17();

extern void
isr18();

extern void
isr19();

extern void
isr20();

extern void
isr21();

extern void
isr22();

extern void
isr23();

extern void
isr24();

extern void
isr25();

extern void
isr26();

extern void
isr27();

extern void
isr28();

extern void
isr29();

extern void
isr30();

extern void
isr31();

// default IRQs
extern void
irq0();

extern void
irq1();

extern void
irq2();

extern void
irq3();

extern void
irq4();

extern void
irq5();

extern void
irq6();

extern void
irq7();

extern void
irq8();

extern void
irq9();

extern void
irq10();

extern void
irq11();

extern void
irq12();

extern void
irq13();

extern void
irq14();

extern void
irq15();

#endif
