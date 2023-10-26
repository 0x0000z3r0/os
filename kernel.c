#include "screen.h"

void
kernel_main(void)
{
	screen_clear();
	screen_print(4, "abcd");
	screen_print(4, "abcd");
}
