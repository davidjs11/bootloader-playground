[org 0x7C00]

; init the stack
mov bp, 0x8000
mov sp, bp

; the program!
mov cl, 0x06    ; set number of iterations

main:
    cmp cl, 0x00 ; check if loop has finished
    je main_end

    sub cl, 0x01    ; reduce 'cl'

    ; print string
    mov bx, string  ; move string address into 'bx' register
    add bx, cx      ; increment with 'cl' value
    call print      ; call 'print' function and start a new line
    call newline

    jmp main

main_end:
    mov bx, bye_string ; print last string
    call print

    call newline
    mov dx, 0xABCD
    call print_hex 

    jmp $   ; infinite loop

; include functions
%include "print.asm"
%include "print_hex.asm"

string:
    db "hello world!", 0x00

bye_string:
    db "maracatones", 0x00


; fill the binary
times 510-($-$$) db 0
dw 0xAA55
