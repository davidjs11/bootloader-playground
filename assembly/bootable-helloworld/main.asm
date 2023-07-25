[org 0x7C00]

; call for print function
mov bx, string
call print
call newline
call print

; infinite loop
jmp $


; include everything
%include "print.asm"

; string definition
string:
    db "here goes da string!!", 0x00

; fill the rest of the binary with 0s till reaching 510
times 510-($-$$) db 0
dw 0xAA55 ; last bytes that let BIOS detect the program 
