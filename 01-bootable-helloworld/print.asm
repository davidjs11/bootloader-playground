print:
    pusha   ; push all registers into stack

print_start:
    ; check if the value pointed by bx is 0x00
    mov al, [bx]
    cmp al, 0x00
    je print_end

    ; print the value stored in 'al'
    mov ah, 0x0E    ; set TTY mode
    int 0x10        ; print interrumption

    ; increment address in 'bx'
    add bx, 1
    jmp print_start

print_end:
    popa    ; recover registers from stack
    ret     ; finish function


; prints a new line
newline:
    pusha   ; push registers into stack
    mov ax, 0x0E0A  ; new line character
    int 0x10
    mov ax, 0x0E0D  ; carriage return
    int 0x10
    popa    ; recover registers from stack
    ret     ; finish function
