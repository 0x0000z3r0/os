#ifndef _TIMER_H_
#define _TIMER_H_

#include "types.h"

#define TIMER_FREQ	(u32)(1193180)
#define TIMER_CHAN0	0x40
#define TIMER_CHAN1	0x41
#define TIMER_CHAN2	0x42
#define	TIMER_MODE	0x43

enum {
	TIMER_MODE_CHAN0 = 0,
	TIMER_MODE_CHAN1,
	TIMER_MODE_CHAN2,
	TIMER_MODE_READBACK
};

enum {
	TIMER_MODE_ACCESS_LATCH = 0,
	TIMER_MODE_ACCESS_LO,
	TIMER_MODE_ACCESS_HI,
	TIMER_MODE_ACCESS_LO_HI
};

enum {
	TIMER_MODE_OPER_TERM_CNT = 0,
	TIMER_MODE_OPER_RE_TRIGGER,
	TIMER_MODE_OPER_RATE_GEN,
	TIMER_MODE_OPER_SQUARE_WAVE,
	TIMER_MODE_OPER_SW_TRIGGER,
	TIMER_MODE_OPER_HW_TRIGGER,
	TIMER_MODE_OPER_RATE_GEN_2,
	TIMER_MODE_OPER_SQUARE_WAVE_2
};

enum {
	TIMER_MODE_TYPE_16BIT = 0,
	TIMER_MODE_TYPE_BCD
};

void
timer_init(u32);

#endif
