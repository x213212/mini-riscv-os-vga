all :
	riscv32-unknown-elf-gcc  -Os -mcmodel=medany -nostdlib  -Wl,-T,qemu.ld -o vga-hello.elf boot.S main.c sys.s lib.c task.c  user.c vga.c
qemu:
	qemu-system-riscv32 -bios none -machine virt -device VGA -smp 1 -kernel vga-hello.elf
