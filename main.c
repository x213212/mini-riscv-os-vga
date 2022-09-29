#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "os.h"

void os_kernel() {
	task_os();
}

void os_start() {
	lib_puts("OS start\n");
	user_init();
}

#define UART        0x10000000
#define UART_THR    (uint8_t*)(UART+0x00) // THR:transmitter holding register
#define UART_LSR    (uint8_t*)(UART+0x05) // LSR:line status register
#define UART_LSR_EMPTY_MASK 0x40          // LSR Bit 6: Transmitter empty; both the THR and LSR are empty



#define VRAM ((volatile uint8_t *)0x50000000)

uintptr_t cmain_stack[4096/sizeof(uintptr_t)];

int mandelbrot(float cr, float ci)
{
	uint32_t reps = 0;
	float zr = 0.0f;
	float zi = 0.0f;
	for ( ; reps < 256; reps++ ) {
		float tr = zr*zr - zi*zi;
		float ti = 2.0f*zr*zi;
		zr = tr + cr;
		zi = ti + ci;
		if ( zr*zr + zi*zi >= 2.0f*2.0f ) {
			break;
		}
	}
	return reps;
}

void os_main(void)
{
	os_start();
	int current_task = 0;
	int i =0;
		
	while (1) {
	
		lib_puts("OS: Activate next task\n");
		task_go(current_task);
		lib_puts("OS: Back to OS\n");
		current_task = (current_task + 1) % taskTop; // Round Robin Scheduling
		lib_puts("\n");
	}
	
}
