#include "idt.h"
#include "gdt.h"

static idt_gate idt_gates[IDT_CNT];
static idt_desc idt_init;

void
idt_gate_init(u32 idx, u32 addr)
{
	idt_gates[idx].addr_lo = (u16)(addr & 0xFFFF);
	idt_gates[idx].seg_sel = CODE_SEG;
	idt_gates[idx].resrv_0 = 0;
	idt_gates[idx].flags   = 0b10001110; // present(1), priv(00), magic(01110)
	idt_gates[idx].addr_hi = (u16)((addr >> 16) & 0xFFFF);
}

void
idt_desc_init(void)
{
	idt_init.base  = (u32)(&idt_gates);
	idt_init.limit = sizeof (idt_gates) - 1;

	asm volatile("lidtl	(%0)" : : "r" (&idt_init));
}
