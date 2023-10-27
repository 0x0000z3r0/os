#include "pic.h"

void
pic_eoi(u8 irq)
{
	// if its a slave irq then send to both
	if (irq >= 8)
		port_out_u8(PIC_SLAVE_CMD, PIC_EOI);

	port_out_u8(PIC_MASTER_CMD, PIC_EOI);
}

void
pic_init(u8 off_m, u8 off_s)
{
	// start initialization
	port_out_u8(PIC_MASTER_CMD, PIC_ICW1_INIT | PIC_ICW1_ICW4);
	port_out_u8(PIC_SLAVE_CMD, PIC_ICW1_INIT | PIC_ICW1_ICW4);

	// set the desired offsets
	port_out_u8(PIC_MASTER_DATA, off_m);
	port_out_u8(PIC_SLAVE_DATA, off_s);

	// tell master that the slave PIC communicates via IRQ2
	port_out_u8(PIC_MASTER_DATA, 0b00000100);

	// tell the cascade identity
	port_out_u8(PIC_SLAVE_DATA, 0b00000010);

	// switch to 8086 mode from 8080
	port_out_u8(PIC_MASTER_DATA, PIC_ICW4_8086);
	port_out_u8(PIC_SLAVE_DATA, PIC_ICW4_8086);

	// enable all PIC lines
	port_out_u8(PIC_MASTER_DATA, 0x0);
	port_out_u8(PIC_SLAVE_DATA, 0x0);
}
