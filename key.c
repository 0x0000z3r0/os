#include "key.h"
#include "isr.h"
#include "port.h"
#include "screen.h"

void
key_func(isr_regs regs)
{
	(void)regs;

	u8 code;
	code = port_in_u8(KEY_DATA);

	switch (code) {
	case KEY_0:
		screen_print_char('0');
		break;
	case KEY_1:
		screen_print_char('1');
		break;
	case KEY_2:
		screen_print_char('2');
		break;
	case KEY_3:
		screen_print_char('3');
		break;
	case KEY_4:
		screen_print_char('4');
		break;
	case KEY_5:
		screen_print_char('5');
		break;
	case KEY_6:
		screen_print_char('6');
		break;
	case KEY_7:
		screen_print_char('7');
		break;
	case KEY_8:
		screen_print_char('8');
		break;
	case KEY_9:
		screen_print_char('9');
		break;
	case KEY_A:
		screen_print_char('a');
		break;
	case KEY_B:
		screen_print_char('b');
		break;
	case KEY_C:
		screen_print_char('c');
		break;
	case KEY_D:
		screen_print_char('d');
		break;
	case KEY_E:
		screen_print_char('e');
		break;
	case KEY_F:
		screen_print_char('f');
		break;
	case KEY_G:
		screen_print_char('g');
		break;
	case KEY_H:
		screen_print_char('h');
		break;
	case KEY_I:
		screen_print_char('i');
		break;
	case KEY_J:
		screen_print_char('j');
		break;
	case KEY_K:
		screen_print_char('k');
		break;
	case KEY_L:
		screen_print_char('l');
		break;
	case KEY_M:
		screen_print_char('m');
		break;
	case KEY_N:
		screen_print_char('n');
		break;
	case KEY_O:
		screen_print_char('o');
		break;
	case KEY_P:
		screen_print_char('p');
		break;
	case KEY_Q:
		screen_print_char('q');
		break;
	case KEY_R:
		screen_print_char('r');
		break;
	case KEY_S:
		screen_print_char('s');
		break;
	case KEY_T:
		screen_print_char('t');
		break;
	case KEY_U:
		screen_print_char('u');
		break;
	case KEY_V:
		screen_print_char('v');
		break;
	case KEY_W:
		screen_print_char('w');
		break;
	case KEY_X:
		screen_print_char('x');
		break;
	case KEY_Y:
		screen_print_char('k');
		break;
	case KEY_Z:
		screen_print_char('z');
		break;
	case KEY_ENTER:
		screen_print_char('\n');
		break;
	}
}

void
key_init(void)
{
	irq_reg(IRQ1, key_func);
}
