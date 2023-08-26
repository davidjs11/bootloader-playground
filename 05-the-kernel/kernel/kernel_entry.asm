; --- kernel-entry.asm ----------------------
; initializes the main function of the kernel, instead of
; running the first piece of code of the program.

[bits 32]       ; set 32-bit mode
[extern main]   ; use main declared in kernel.c
call main        
jmp $
