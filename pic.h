#ifndef _PIC_H_
#define _PIC_H_

#include "port.h"

#define PIC_MASTER	0x20
#define PIC_SLAVE	0xA0
#define PIC_MASTER_CMD	PIC_MASTER
#define PIC_MASTER_DATA	(PIC_MASTER + 1)
#define PIC_SLAVE_CMD	PIC_SLAVE
#define PIC_SLAVE_DATA	(PIC_SLAVE + 1)

#define PIC_EOI		0x20

#define PIC_ICW1_ICW4		0x01	// Indicates that ICW4 will be present 
#define PIC_ICW1_SINGLE		0x02	// Single (cascade) mode 
#define PIC_ICW1_INTERVAL4	0x04	// Call address interval 4 (8) 
#define PIC_ICW1_LEVEL		0x08	// Level triggered (edge) mode 
#define PIC_ICW1_INIT		0x10	// Initialization - required! 
 
#define PIC_ICW4_8086		0x01	// 8086/88 (MCS-80/85) mode 
#define PIC_ICW4_AUTO		0x02	// Auto (normal) EOI 
#define PIC_ICW4_BUF_SLAVE	0x08	// Buffered mode/slave 
#define PIC_ICW4_BUF_MASTER	0x0C	// Buffered mode/master 
#define PIC_ICW4_SFNM		0x10	// Special fully nested (not) 

void
pic_eoi(u8);

void
pic_init(u8, u8);

#endif
