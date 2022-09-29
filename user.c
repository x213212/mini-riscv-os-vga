#include "os.h"

void user_task0(void)
{
	
	
	lib_puts("Task0: Created!\n");
	lib_puts("Task0: Now, return to kernel mode\n");
	os_kernel();
	int i=0;
	while (1) {
		lib_puts("Task0: Running...\n");
		lib_delay(10);
		os_kernel();
			for(int j= 0; j < 200 ;j++){
			putpixel(i,j,0x7800);
			
		}
		i++;
		if (i == 320)
		i=0;
	}
}

void user_task1(void)
{
	lib_puts("Task1: Created!\n");
	lib_puts("Task1: Now, return to kernel mode\n");
	os_kernel();
	int i=0;
	int flag =0;
	while (1) {
		lib_puts("Task1: Running...\n");
		lib_delay(300);
		os_kernel();
		if(flag)
		fillrect(20+i,i,0x000000);
		else
		fillrect(20+i,i,0x0000ff);

		
		i+=40;
		if (i == 320){
		i=0;
		flag=~flag;
		}
	}
}

void user_init() {
	task_create(&user_task0);
	task_create(&user_task1);
}
