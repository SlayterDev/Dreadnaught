// common.h -- Brad Slayter

#ifndef COMMON_H
#define COMMON_H

#define DEBUG 1

typedef unsigned int   u32int;
typedef			 int   s32int;
typedef unsigned short u16int;
typedef			 short s16int;
typedef unsigned char  u8int;
typedef			 char  s8int;

// Hardware speaking functions
void outb(u16int port, u8int value);
u8int inb(u16int port);
u16int inw(u16int port);

// string length
u32int strlen(char *str);

#endif