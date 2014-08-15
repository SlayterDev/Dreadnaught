// isr.c -- Brad Slayter

#include "kernel/isr.h"
#include "lib/common.h"
#include "io/monitor.h"

isr_t interrupt_handlers[256];

void register_interrupt_handler(u8int n, isr_t handler) {
	interrupt_handlers[n] = handler;
}

void isr_handler(registers_t regs) {
	if (interrupt_handlers[regs.int_no] != 0) {
		isr_t handler = interrupt_handlers[regs.int_no];
		handler(regs);
	} else {
		mon_write("Recieved interrupt: ");
		mon_write_dec(regs.int_no);
		mon_put('\n');
	}

	/*if (regs.int_no == 14) {
		PANIC("Page Fault!");
	}*/
}

void irq_handler(registers_t regs) {
	if (regs.int_no >= 40) {
		outb(0xA0, 0x20);
	}

	// send reset signal to PICs
	outb(0x20, 0x20);

	if (interrupt_handlers[regs.int_no] != 0) {
		isr_t handler = interrupt_handlers[regs.int_no];
		handler(regs);
	}
}