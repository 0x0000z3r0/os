#include "isr.h"
#include "idt.h"
#include "screen.h"
#include "pic.h"
#include "util.h"

irq_func irq_funcs[256];

void
isr_init(void)
{
	idt_gate_init(0, (u32)isr0);
	idt_gate_init(1, (u32)isr1);
	idt_gate_init(2, (u32)isr2);
	idt_gate_init(3, (u32)isr3);
	idt_gate_init(4, (u32)isr4);
	idt_gate_init(5, (u32)isr5);
	idt_gate_init(6, (u32)isr6);
	idt_gate_init(7, (u32)isr7);
	idt_gate_init(8, (u32)isr8);
	idt_gate_init(9, (u32)isr9);
	idt_gate_init(10, (u32)isr10);
	idt_gate_init(11, (u32)isr11);
	idt_gate_init(12, (u32)isr12);
	idt_gate_init(13, (u32)isr13);
	idt_gate_init(14, (u32)isr14);
	idt_gate_init(15, (u32)isr15);
	idt_gate_init(16, (u32)isr16);
	idt_gate_init(17, (u32)isr17);
	idt_gate_init(18, (u32)isr18);
	idt_gate_init(19, (u32)isr19);
	idt_gate_init(20, (u32)isr20);
	idt_gate_init(21, (u32)isr21);
	idt_gate_init(22, (u32)isr22);
	idt_gate_init(23, (u32)isr23);
	idt_gate_init(24, (u32)isr24);
	idt_gate_init(25, (u32)isr25);
	idt_gate_init(26, (u32)isr26);
	idt_gate_init(27, (u32)isr27);
	idt_gate_init(28, (u32)isr28);
	idt_gate_init(29, (u32)isr29);
	idt_gate_init(30, (u32)isr30);
	idt_gate_init(31, (u32)isr31);

	pic_init(IRQ_MASTER_OFF, IRQ_SLAVE_OFF);

	idt_gate_init(IRQ0, (u32)irq0);
	idt_gate_init(IRQ1, (u32)irq1);
	idt_gate_init(IRQ2, (u32)irq2);
	idt_gate_init(IRQ3, (u32)irq3);
	idt_gate_init(IRQ4, (u32)irq4);
	idt_gate_init(IRQ5, (u32)irq5);
	idt_gate_init(IRQ6, (u32)irq6);
	idt_gate_init(IRQ7, (u32)irq7);
	idt_gate_init(IRQ8, (u32)irq8);
	idt_gate_init(IRQ9, (u32)irq9);
	idt_gate_init(IRQ10, (u32)irq10);
	idt_gate_init(IRQ11, (u32)irq11);
	idt_gate_init(IRQ12, (u32)irq12);
	idt_gate_init(IRQ13, (u32)irq13);
	idt_gate_init(IRQ14, (u32)irq14);
	idt_gate_init(IRQ15, (u32)irq15);

	idt_desc_init();
}

void
isr_hnd(isr_regs regs)
{
	static s8 *isr_msgs[] = {
		"Division By Zero",
		"Debug",
    		"Non Maskable Interrupt",
    		"Breakpoint",
    		"Into Detected Overflow",
    		"Out of Bounds",
    		"Invalid Opcode",
    		"No Coprocessor",
    		"Double Fault",
    		"Coprocessor Segment Overrun",
    		"Bad TSS",
    		"Segment Not Present",
    		"Stack Fault",
    		"General Protection Fault",
    		"Page Fault",
    		"Unknown Interrupt",
    		"Coprocessor Fault",
    		"Alignment Check",
    		"Machine Check",
    		"Reserved",
    		"Reserved",
    		"Reserved",
    		"Reserved",
    		"Reserved",
    		"Reserved",
    		"Reserved",
    		"Reserved",
    		"Reserved",
    		"Reserved",
    		"Reserved",
    		"Reserved",
    		"Reserved"
	};

	s8 isr_init_msg[] = "interrupt: ";
	screen_print(sizeof (isr_init_msg) - 1, isr_init_msg);
	// NOTE: meh
	screen_print(4, isr_msgs[regs.num]);
	screen_print(1, "\n");
}

void
irq_hnd(isr_regs regs)
{
	// reset the offset
	pic_eoi(regs.num - IRQ0);

	// call the handler
	if (irq_funcs[regs.num] != NULL) {
		irq_func func;
		func = irq_funcs[regs.num];

		func(regs);
	}
}

void
irq_reg(u32 idx, irq_func func)
{
	irq_funcs[idx] = func;
}
