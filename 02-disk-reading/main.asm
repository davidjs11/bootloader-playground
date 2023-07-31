; main.asm

[org 0x7C00]

; init the stack
mov bp, 0x8000
mov sp, bp

; read sectors from disk
mov bx, 0x9000  ; buffer address
mov dh, 0x05    ; number of sectors to read
                ; BIOS saves boot disk index into 'dl' 

call read_disk

; index
mov cl, 0x00

; prints first word from first 5 sectors
reading_loop:
    cmp cl, 0x05
    je reading_end

    ; print first word from sector 
    mov dx, [bx]
    call print_hex
    call newline

    add cl, 0x01        ; increment index
    add bx, 0x0200      ; increment pointer
    
    jmp reading_loop    ; continue loop

reading_end:
    jmp $
     



; print first word from second read sector
mov dx, [0x9000 + 0x200]
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
times 256 dw 0x4321 ; write on sector 0x04
times 256 dw 0x8910 ; write on sector 0x05
times 256 dw 0x3476 ; write on sector 0x06
