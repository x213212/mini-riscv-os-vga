# mini-riscv-os-vga

VGA framebuffer output for [`mini-riscv-os`](https://github.com/cccriscv/mini-riscv-os)
— a minimal multi-tasking RISC-V teaching kernel — so the kernel can draw to a
screen instead of only writing to the UART.

## What was added

`vga.c` / `vga.h` map the QEMU VGA framebuffer at `0x50000000` and provide
pixel and rectangle primitives on a 320-pixel-wide surface:

```c
#define VRAM ((volatile uint8_t *)0x50000000)

void putpixel(uint32_t x, uint32_t y, int color) {
    unsigned where = (x * 1) + y * 320;
    VRAM[where]     =  color        & 255;   // B
    VRAM[where + 1] = (color >>  8) & 255;   // G
    VRAM[where + 2] = (color >> 16) & 255;   // R
}
```

`main.c` and `task.c` then drive it from the existing cooperative task
scheduler, so drawing happens from a scheduled task rather than a busy loop.

## Build and run

```bash
make
```

The Makefile builds `vga-hello.elf` and launches QEMU (`qemu.ld` is the link
script; `boot.S` / `start.s` are the entry path).

## Layout

| File | Purpose |
|---|---|
| `vga.c`, `vga.h` | framebuffer mapping and drawing primitives |
| `task.c`, `task.h` | cooperative scheduler (from upstream) |
| `boot.S`, `start.s`, `sys.s` | entry and trap setup |
| `qemu.ld` | link script |
| `lib.c`, `lib.h` | small runtime helpers |

## Upstream and license

This is a derivative of `mini-riscv-os` by National Quemoy University, Taiwan,
which is distributed under the two-clause BSD License. That license is carried
in [LICENSE](LICENSE) and applies to this repository as well.
