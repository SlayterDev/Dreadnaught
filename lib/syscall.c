// syscall.c -- Brad Slayter

#include "lib/syscall.h"
#include "lib/stdio.h"
#include "io/monitor.h"

#include "kernel/isr.h"

static void syscall_handler(registers_t regs);

static void *syscalls[3] = {
	&kprintf,
	&getch,
	&mon_write
};
u32int num_syscalls = 3;

DEFN_SYSCALL2(kprintf, 0, int, const char *);
DEFN_SYSCALL0(getch, 1);
DEFN_SYSCALL1(mon_write, 2, const char *);

void initialize_syscalls() {
	register_interrupt_handler(0x80, syscall_handler);
}

void syscall_handler(registers_t regs) {
	kprintf(K_INFO, "Syscall handler\n");
	if (regs.eax >= num_syscalls)
		return;

	void *location = syscalls[regs.eax];

	int ret;
	asm volatile(" \
		push %1; \
		push %2; \
		push %3; \
		push %4; \
		push %5; \
		call *%6; \
		pop %%ebx; \
		pop %%ebx; \
		pop %%ebx; \
		pop %%ebx; \
		pop %%ebx; \
		" : "=a" (ret) : "r" (regs.edi), "r" (regs.esi), "r" (regs.edx), "r" (regs.ecx), "r" (regs.ebx), "r" (location));
	regs.eax = ret;
}