#include <stdint.h>
#ifndef __VGA_H__
#define __VGA_H__

extern void putpixel(uint32_t  x,uint32_t  y, int color) ;
extern void fillrect(uint32_t  x,uint32_t  y, int color) ;
#endif
