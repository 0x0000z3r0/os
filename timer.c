#include "timer.h"
#include "isr.h"
#include "port.h"
#include "screen.h"
#include "util.h"

static void
timer_func(isr_regs regs)
{
	(void)regs;
}

void
timer_init(u32 freq)
{
	irq_reg(IRQ0, timer_func);

	u32 div;
	div = TIMER_FREQ / freq;

	u8 mode;
	mode = 0;

	mode |= (TIMER_MODE_TYPE_16BIT << 0);
	mode |= (TIMER_MODE_OPER_SQUARE_WAVE << 1);
	mode |= (TIMER_MODE_ACCESS_LO_HI << 4);
	mode |= (TIMER_MODE_CHAN0 << 6);

	// set the timer mode
	port_out_u8(TIMER_MODE, mode);
	// supply the frequency
	port_out_u8(TIMER_CHAN0, (u8)(div & 0xFF));
	port_out_u8(TIMER_CHAN0, (u8)((div >> 8) & 0xFF));
}
