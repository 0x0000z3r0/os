#include "port.h"

u8
port_in_u8(u16 port)
{
	u16 res;
	asm volatile("in	%%dx, %%al" : "=a"(res) : "Nd"(port));

	return res;
}

void
port_out_u8(u16 port, u8 data)
{
	asm volatile("out	%%al, %%dx" : : "a"(data), "Nd"(port));
}

void
port_io_wait(void)
{
	// NOTE: clarify the constant
	port_out_u8(0x80, 0);
}
