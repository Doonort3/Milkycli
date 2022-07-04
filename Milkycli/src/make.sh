nasm -f elf32 ./main.asm -o ./bin/main.asm.o
gcc -m32 -c ./kernel.c -o ./bin/kernel.o

ld -m elf_i386 -T link.ld -o fkernel ./bin/main.asm.o ./bin/kernel.o

cp fkernel ./iso/boot/Kernel
grub-mkrescue -o milky.iso iso