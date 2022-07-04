# Milkycli
### Compile:
* $ nasm -f elf32 ./main.asm -o ./bin/main.asm.o
* $ gcc -m32 -c ./kernel.c -o ./bin/kernel.o
* $ ld -m elf_i386 -T link.ld -o fkernel ./bin/main.asm.o ./bin/kernel.o
* $ cp fkernel ./iso/boot/Kernel
* $ grub-mkrescue -o milky.iso iso
### Start on QEMU:
* qemu-system-x86_64 -cdrom milky.iso

***This repository has an already compiled and linked "kernel" file to run.
If you do not have the right tools to compile and link yand installed, you can start the milky.iso QEMU directly by using the command 
which is listed under "Start on QEMU" (qemu-system-x86_64 -cdrom milky.iso).***
