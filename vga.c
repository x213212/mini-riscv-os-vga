#include "vga.h"
#include <stdint.h>
#include <string.h>
#define VRAM ((volatile uint8_t *)0x50000000)
void putpixel(uint32_t  x,uint32_t  y, int color) {
    unsigned where = (x*1)+y*320;
    VRAM[where] = color & 255;              // BLUE
    VRAM[where + 1] = (color >> 8) & 255;   // GREEN
    VRAM[where + 2] = (color >> 16) & 255;  // RED
}

void fillrect(uint32_t  x,uint32_t  y, int color) {


    uint32_t  i, j;
 	
    for (i = x; i < x+20; i+=1) {
        for (j = y; j < y+20; j+=1) {
          putpixel(i,j,color);
        }
      
    }
}
