; --- main.asm ------------------------------
[bits 16]               ; 16bit real mode
[org 0x7C00]            ; set memory segment

mov bp, 0x9000          ; init stack
mov sp, bp

mov bx, MSG_REAL_MODE   ; write message in real mode
call print

call switch_pm          ; init protected mode


; --- functions -----------------------------
%include "print.asm"        ; printing in 16bit real mode
%include "gdt.asm"          ; defining global descriptor table
%include "print_vga.asm"    ; printing in 32bit protected mode
%include "switch_pm.asm"    ; switching to 32 bit protected mode


; --- code for protected mode ---------------
[bits 32]
BEGIN_PM:
    mov ebx, MSG_PROTECTED_MODE ; print message
    call print_vga
    jmp $                       ; do nothing


; --- strings -------------------------------
MSG_REAL_MODE db "Now in 16-bit real mode.", 0
MSG_PROTECTED_MODE db "Now in 32-bit protected mode.", 0


; --- mbr boot signature --------------------
times 510-($-$$) db 0x00
dw 0xAA55 ; magic last word 
