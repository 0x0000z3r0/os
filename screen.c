#include "port.h"

#define SCREEN_ADDRESS		0xB8000
#define SCREEN_ROWS		(u16)(25)
#define SCREEN_COLS		(u16)(80)
#define SCREEN_WHITE_BLACK	0x0F
#define SCREEN_REG_CTRL		(u16)(0x3D4)
#define SCREEN_REG_DATA		(u16)(0x3D5)

void
screen_cur_init(void)
{
	u8 tmp;
	tmp = 0;

	port_out_u8(SCREEN_REG_CTRL, 0x0A);
	tmp = port_in_u8(SCREEN_REG_DATA) & 0x1F;
	
	port_out_u8(SCREEN_REG_CTRL, 0x0A);
	port_out_u8(SCREEN_REG_DATA, tmp | 0x20);
}

void
screen_cur_del(void)
{
	port_out_u8(SCREEN_REG_CTRL, 0x0A);
	port_out_u8(SCREEN_REG_DATA, 0x20);
}

u16
screen_cur_get(void)
{
	u16 off;
	off = 0;

	port_out_u8(SCREEN_REG_CTRL, 0xF);
	off |= port_in_u8(SCREEN_REG_DATA);

	port_out_u8(SCREEN_REG_CTRL, 0xE);
	off |= ((u16)port_in_u8(SCREEN_REG_DATA)) << 8;

	return off;
}

void
screen_cur_set(u16 off)
{
	port_out_u8(SCREEN_REG_CTRL, 0x0F);
	port_out_u8(SCREEN_REG_DATA, (u8)(off & 0xFF));
	port_out_u8(SCREEN_REG_CTRL, 0x0E);
	port_out_u8(SCREEN_REG_DATA, (u8)((off >> 8) & 0xFF));
}

void
screen_clear(void)
{
	u8 *mem;
	mem = (u8*)SCREEN_ADDRESS;

	for (u16 i = 0; i < SCREEN_COLS * SCREEN_ROWS; ++i) {
		mem[i * 2 + 0] = ' ';
		mem[i * 2 + 1] = SCREEN_WHITE_BLACK;
	}

	screen_cur_set(0);
}

void
screen_print_char(char sym)
{
	u8 *mem;
	mem = (u8*)SCREEN_ADDRESS;
	
	u16 off;
	off = screen_cur_get();

	mem[off * 2 + 0] = sym;
	mem[off * 2 + 1] = SCREEN_WHITE_BLACK;
	
	++off;
	screen_cur_set(off);
}

void
screen_print(u16 len, s8 *str)
{
	for (u16 i = 0; i < len; ++i)
		screen_print_char(str[i]);
}

