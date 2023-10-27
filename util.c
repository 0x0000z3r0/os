#include "util.h"

void
u32_to_str(u32 num, u32 len, s8 *str, u32 *ret)
{
	u32 idx;
	idx = 0;
	while (num != 0 && idx < len) {
		str[idx] = (num % 10) + '0';
	
		++idx;
		num /= 10;
	}

	s8 tmp;
	for (u32 i = 0; i < idx; ++i) {
		tmp = str[i];
		str[i] = str[idx - 1];
		str[idx - 1] = tmp;
	}

	*ret = idx;
}
