all:
		nasm -f elf color.asm
		gcc -Wall main.c color.o
