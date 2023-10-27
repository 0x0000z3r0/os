#ifndef _PORT_H_
#define _PORT_H_

#include "types.h"

u8
port_in_u8(u16);

void
port_out_u8(u16, u8);

void
port_io_wait(void);

#endif
