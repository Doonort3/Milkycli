# Milkycli
### Compile:
* $ nasm -f elf32 main.asm -o kasm.o
* $ gcc -m32 -c kmain.c -o kc.o
* $ ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o
### Start on QEMU:
* qemu-system-i386 -kernel kernel

***This repository has an already compiled and linked "kernel" file to run.
If you do not have the right tools to compile and link yand installed, you can start the "kernel" file in QEMU directly by using the command 
which is listed under "Start on QEMU" (qemu-system-i386 -kernel kernel).***
