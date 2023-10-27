#include "screen.h"
#include "isr.h"
#include "timer.h"
#include "key.h"

void
kernel_main(void)
{
	screen_clear();

	s8 str_isr[] = "initializing ISRs\n";
	screen_print(sizeof (str_isr) - 1, str_isr);

	isr_init();

	s8 str_timer[] = "enabling the interrupts\n";
	screen_print(sizeof (str_timer) - 1, str_timer);

	asm volatile("sti");
	
	s8 str_key[] = "initializing the keyboard\n";
	screen_print(sizeof (str_key) - 1, str_key);

	key_init();

	s8 str_done[] = "done\n";
	screen_print(sizeof (str_done) - 1, str_done);
}
