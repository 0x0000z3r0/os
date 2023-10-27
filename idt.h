#ifndef _IDT_H_
#define _IDT_H_

#include "types.h"

typedef struct {
	u16 	addr_lo; // function address
	u16 	seg_sel; // segment selector
	u8 	resrv_0; // always zero
	u8 	flags;   // flags => present(7), privelege(6:5), magic(4:0)
	u16 	addr_hi; // function address
} __attribute__((packed)) idt_gate;

typedef struct {
	u16 	limit;
	u32 	base;
} __attribute__((packed)) idt_desc;

#define IDT_CNT 256

void
idt_gate_init(u32, u32);

void
idt_desc_init(void);

#endif
