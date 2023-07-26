; string length
; while (string[i] != 0) { i++; }
str_len:
    ; condition
    mov ch, [bx]
    cmp ch, 0
    je str_len_end

    add cl, 1  ; increment counter
    add bx, 1   ; increment pointer
    jmp str_len

str_len_end:
    mov ch, 0x00
    ret
