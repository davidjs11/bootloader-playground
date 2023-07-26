; main.asm

[org 0x7C00]

; init the stack
mov bp, 0x8000
mov sp, bp

; read sectors from disk
mov bx, 0x9000  ; buffer address
mov dh, 0x02    ; number of sectors to read
                ; BIOS saves boot disk index into 'dl' 

call read_disk

; print first word from first read sector
mov dx, [0x9000]
call print_hex
call newline

; print first word from second read sector
mov dx, [0x9000 + 512]
call print_hex
call newline

; infinite loop
jmp $

; import functions
%include "print.asm"
%include "print_hex.asm"
%include "read_disk.asm"

; fill the binary with 0s until byte 510
times 510-($-$$) db 0x00
dw 0xAA55 ; magic last word 

; write data into disk
times 256 dw 0xABCD ; write on sector 0x02
times 256 dw 0x1234 ; write on sector 0x03
