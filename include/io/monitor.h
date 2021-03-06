// monitor.h -- Brad Slayter

#ifndef MONITOR_H
#define MONITOR_H

#include "lib/common.h"

enum vgaColor {
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GREY = 7,
	COLOR_DARK_GREY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_LIGHT_BROWN = 14,
	COLOR_WHITE = 15,
};

void mon_clear();

void mon_set_color(u8int back, u8int fore);

void mon_put(char c);
void mon_write(const char *c);
void mon_write_line(const char *c);
void DEBUG_mon_write(const char *c);
void mon_backspace();
void mon_write_hex(u32int n);
void mon_write_dec(int n);

#endif