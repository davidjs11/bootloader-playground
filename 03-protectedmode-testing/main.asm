; --- main.asm ------------------------------

[org 0x7C00]    ; set memory segment

; init the stack
mov bp, 0x8000
mov sp, bp

jmp $ ; do nothing



;--- functions ------------------------------

%include "print.asm"
%include "print_hex.asm"
%include "read_disk.asm"
%include "print_vga.asm"
%include "gdt.asm"

; fill the binary with 0s until byte 510
times 510-($-$$) db 0x00
dw 0xAA55 ; magic last word 
