print_hex:
    pusha       ; push registers into stack
    mov cx, 0   ; index variable

hex_loop:
    ; loop condition
    cmp cx, 4   ; iterate 4 times
    je end      ; finish loop

    ; get last digit from 'dx' and convert it into ASCII value
    mov ax, dx      ; get value from 'dx' into 'ax'
    and ax, 0x000F  ; mask last 4 bytes from 'ax'
    add ax, 0x0030  ; convert digit N into char 'N'
    cmp al, 0x39    ; check if digit > 9
    jle hex_loop_step2  ; if not, jump to step 2
    add ax, 0x0007  ; add 8 (for chars from 'A' to 'F')

hex_loop_step2:
    mov bx, HEX_CODE+5  ; get pointer to the end of the string 
    sub bx, cx      ; get string index  
    mov [bx], al    ; put value into string
    ror dx, 4       ; shift-right 4 bits
    add cx, 1       ; increment index
    jmp hex_loop    ; loop

end:
    mov bx, HEX_CODE ; get address of the string
    call print       ; print string

    popa             ; recover registers from stack
    ret

HEX_CODE:
    db "0x0000", 0x00

